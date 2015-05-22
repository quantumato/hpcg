
//@HEADER
// ***************************************************
//
// HPCG: High Performance Conjugate Gradient Benchmark
//
// Contact:
// Michael A. Heroux ( maherou@sandia.gov)
// Jack Dongarra     (dongarra@eecs.utk.edu)
// Piotr Luszczek    (luszczek@eecs.utk.edu)
//
// ***************************************************
//@HEADER

/*!
	@file ExchangeHalo.cpp

	HPCG routine
 */

#ifndef HPCG_NOMPI  // Compile this routine only if running in parallel
#include <mpi.h>
#include "Geometry.hpp"
#include "ExchangeHalo.hpp"
#include <cstdlib>

/*!
	Communicates data that is at the border of the part of the domain assigned to this processor.
	Class holds data relevant to this calculation

	@param[in]    A The known system matrix
	@param[inout] x On entry: the local vector entries followed by entries to be communicated; on exit: the vector with non-local entries updated by other processors
 */


//TODO finish up this class structure

class ExchangeHalo
{
	private:
		local_int_t localNumberOfRows;
		local_int_t * receiveLength;
		local_int_t * sendLength;
		local_int_t totalToBeSent;
		local_int_t * elementsToSend;

		int num_neighbors;
		int * neighbors;
		int MPI_MY_TAG;
		double * sendBuffer;
		double * const xv;

		double * x_external;
		int size, rank; // Number of MPI processes, My process ID

		MPI_Request * request;	//handles send and recv requests
		MPI_Status *status;
	public:
		ExchangeHalo(const SparseMatrix& A, Vector& x);
		~ExchangeHalo();

		void ExchangeHalo_Init();
		void ExchangeHalo_Finalize();
};

ExchangeHalo::ExchangeHalo(const SparseMatrix & A, Vector & x) : xv(x.values) {

	//Extract matrix pieces

	//xv = x.values; // Stores the xvalues for the halo

	localNumberOfRows = A.localNumberOfRows;
	num_neighbors = A.numberOfSendNeighbors;
	receiveLength = A.receiveLength;
	sendLength = A.sendLength;
	neighbors = A.neighbors;
	sendBuffer = A.sendBuffer;
	totalToBeSent = A.totalToBeSent;
	elementsToSend = A.elementsToSend;

	int size, rank; // Number of MPI processes, My process ID
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_MY_TAG = 99;

	request = new MPI_Request[2*num_neighbors];	//handles send and recv requests
	//
	// Externals are at end of locals
	//
	x_external = (double *) xv + localNumberOfRows;
}

void ExchangeHalo::ExchangeHalo_Init()	{
	//
	//  first post receives, these are immediate receives
	//  Do not wait for result to come, will do that at the
	//  wait call below.
	//

	// TODO: Thread this loop
	for (int i = 0; i < num_neighbors; i++) {
		local_int_t n_recv = receiveLength[i];
		MPI_Irecv(x_external, n_recv, MPI_DOUBLE, neighbors[i], MPI_MY_TAG, MPI_COMM_WORLD, request+i);
		x_external += n_recv;
	}


	//
	// Fill up send buffer
	//

	// TODO: Thread this loop
	for (local_int_t i=num_neighbors; i<totalToBeSent+num_neighbors; i++) sendBuffer[i] = xv[elementsToSend[i]];

	//
	// Send to each neighbor
	//

	// TODO: Thread this loop
	// Send is non-blocking so the multiplication calculations can continue immediately
	request += num_neighbors;
	for (int i = 0; i < num_neighbors; i++) {
		local_int_t n_send = sendLength[i];
		MPI_Isend(sendBuffer, n_send, MPI_DOUBLE, neighbors[i], MPI_MY_TAG, MPI_COMM_WORLD, request+i);
		sendBuffer += n_send;
	}

}

void ExchangeHalo::ExchangeHalo_Finalize()	{
	MPI_Status *status = new MPI_Status[2*num_neighbors];

	//wait for all send and recv communication to complete
	MPI_Waitall(2*num_neighbors, request, status);
}

ExchangeHalo::~ExchangeHalo()	{
	delete[] request;
	delete[] status;
}

#endif //#ifndef HPCG_NOMPI
