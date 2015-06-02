
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
#include "ExchangeHaloRequest.hpp"
#include <cstdlib>

/*!
	Communicates data that is at the border of the part of the domain assigned to this processor.
	Class holds data relevant to this calculation

	@param[in]    A The known system matrix
	@param[inout] x On entry: the local vector entries followed by entries to be communicated; on exit: the vector with non-local entries updated by other processors
 */


//TODO finish up this class structure

ExchangeHaloRequest::ExchangeHaloRequest(const SparseMatrix & A, Vector & x) : xv(x.values) {

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
	totalRequests = num_neighbors*2;

	int size, rank; // Number of MPI processes, My process ID
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_MY_TAG = 99;

<<<<<<< HEAD:src/ExchangeHaloRequest.cpp
	requests = new MPI_Request[totalRequests];	//handles send and recv requests
=======
	request = new MPI_Request[totalRequests];	//handles send and recv requests
>>>>>>> 74531baf625881e2ca1ecd03ffd28b91a867ee5b:src/ExchangeHaloRequest.cpp
	//
	// Externals are at end of locals
	//
	x_external = (double *) xv + localNumberOfRows;
}

void ExchangeHaloRequest::ExchangeHalo_Init()	{
	//
	//  first post receives, these are immediate receives
	//  Do not wait for result to come, will do that at the
	//  wait call below.
	//

	// TODO: Thread this loop
	for (local_int_t i = 0; i < num_neighbors; i++) {
		local_int_t n_recv = receiveLength[i];
<<<<<<< HEAD:src/ExchangeHaloRequest.cpp
		MPI_Irecv(x_external, n_recv, MPI_DOUBLE, neighbors[i], MPI_MY_TAG, MPI_COMM_WORLD, requests+i);
=======
		MPI_Irecv(x_external, n_recv, MPI_DOUBLE, neighbors[i], MPI_MY_TAG, MPI_COMM_WORLD, request);
		request++;
>>>>>>> 74531baf625881e2ca1ecd03ffd28b91a867ee5b:src/ExchangeHaloRequest.cpp
		x_external += n_recv;
	}


	//
	// Fill up send buffer
	//

	// TODO: Thread this loop
	for (local_int_t i=num_neighbors; i<totalToBeSent; i++) sendBuffer[i] = xv[elementsToSend[i]];

	//
	// Send to each neighbor
	//

	// TODO: Thread this loop
	// Send is non-blocking so the multiplication calculations can continue immediately
<<<<<<< HEAD:src/ExchangeHaloRequest.cpp
	for (local_int_t i = 0; i < num_neighbors; i++) {
		local_int_t n_send = sendLength[i];
		int offset = i + num_neighbors;
		MPI_Isend(sendBuffer, n_send, MPI_DOUBLE, neighbors[i], MPI_MY_TAG, MPI_COMM_WORLD, requests+offset);	//when you send an array, does this use one or two requests?
=======
	request += num_neighbors;
	for (local_int_t i = 0; i < num_neighbors; i++) {
		local_int_t n_send = sendLength[i];
		MPI_Isend(sendBuffer, n_send, MPI_DOUBLE, neighbors[i], MPI_MY_TAG, MPI_COMM_WORLD, request);
		request++;
>>>>>>> 74531baf625881e2ca1ecd03ffd28b91a867ee5b:src/ExchangeHaloRequest.cpp
		sendBuffer += n_send;
	}
}

void ExchangeHaloRequest::ExchangeHaloWaitall()	{
<<<<<<< HEAD:src/ExchangeHaloRequest.cpp
	status = new MPI_Status[totalRequests];

	//wait for all send and recv communication to complete
	MPI_Waitall(totalRequests, requests, status);
}

ExchangeHaloRequest::~ExchangeHaloRequest()	{
	delete[] requests;
	delete[] status;
=======
	MPI_Status *status = new MPI_Status[totalRequests];

	//wait for all send and recv communication to complete
	MPI_Waitall(totalRequests, request, status);
}

ExchangeHaloRequest::~ExchangeHaloRequest()	{
//	delete[] request;
//	delete[] status;
>>>>>>> 74531baf625881e2ca1ecd03ffd28b91a867ee5b:src/ExchangeHaloRequest.cpp
}

#endif //#ifndef HPCG_NOMPI
