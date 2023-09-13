/*
 *	Wrapper to acces the different blas inmplementation 
 *
 *
 *
 */
#ifdef HAVE_ROCBLAS
#include "include/rocblas.hpp"
#elif HAVE_CUBLAS
#include "include/cublas.hpp"
#endif



extern "C" int gpu_dgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double alpha, double* A, int64_t lda,\
		double* B, int64_t ldb, double beta, double* C, int64_t ldc)
{
	dgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}
