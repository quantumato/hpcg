
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
 @file ComputeSPMV_ref.cpp

 HPCG routine
 */

#include "ComputeSPMV_ref.hpp"

#ifndef HPCG_NOMPI
#include <mpi.h>
#include "Geometry.hpp"
#include <cstdlib>
#include "ExchangeHaloRequest.hpp"
#endif

#ifndef HPCG_NOOPENMP
#include <omp.h>
#endif
#include <cassert>

/*!
  Routine to compute matrix vector product y = Ax where:
  Precondition: First call exchange_externals to get off-processor values of x

  This is the reference SPMV implementation.  It CANNOT be modified for the
  purposes of this benchmark.

  @param[in]  A the known system matrix
  @param[in]  x the known vector
  @param[out] y the On exit contains the result: Ax.

  @return returns 0 upon success and non-zero otherwise

  @see ComputeSPMV
*/
int ComputeSPMV_ref( const SparseMatrix & A, Vector & x, Vector & y) {

  assert(x.localLength>=A.localNumberOfColumns); // Test vector lengths
  assert(y.localLength>=A.localNumberOfRows);

	//
	// Halo Exchange
	//
#ifndef HPCG_NOMPI
    ExchangeHaloRequest Exchanger(A,x);
		Exchanger.ExchangeHalo_Init();
#endif

  const double * const xv = x.values;
  double * const yv = y.values;
  const local_int_t nrow = A.localNumberOfRows;
#ifndef HPCG_NOOPENMP
  #pragma omp parallel for
#endif

	// perform the row multiplication on values in x that are local
	// and unaffected by the halo exchange
  for (local_int_t i=0; i< nrow; i++)  {
    double sum = 0.0;
    const double * const cur_vals = A.matrixValues[i];
    const local_int_t * const cur_inds = A.mtxIndL[i];
    const int cur_nnz = A.nonzerosInRow[i];
    for (int j=0; j< cur_nnz; j++)	{
			if(cur_inds[j] < nrow)	{
				sum += cur_vals[j]*xv[cur_inds[j]];
				yv[i] = sum;
			}
		}
	}

#ifndef HPCG_NOMPI
	Exchanger.ExchangeHaloWaitall();
#endif

	// finish the row multiplications with the values in x that are external
  // and modified by the halo exchange
  for (local_int_t i=0; i< nrow; i++)  {
    double sum = 0.0;
    const double * const cur_vals = A.matrixValues[i];
    const local_int_t * const cur_inds = A.mtxIndL[i];
    const int cur_nnz = A.nonzerosInRow[i];
    for (int j=0; j< cur_nnz; j++)	{
			if(cur_inds[j] >= nrow)	{
				sum += cur_vals[j]*xv[cur_inds[j]];
				yv[i] = sum;
			}
		}
	}
	//deallocate memory
  return(0);
}
