
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

#ifndef EXCHANGEHALO_HPP
#define EXCHANGEHALO_HPP
#include <mpi.h>
#include "SparseMatrix.hpp"
#include "Vector.hpp"
class ExchangeHalo_Split
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
		ExchangeHalo_Split(const SparseMatrix& A, Vector& x);
		~ExchangeHalo_Split();

		void ExchangeHalo_Init();
		void ExchangeHalo_Finalize();
};
#endif // EXCHANGEHALO_HPP
