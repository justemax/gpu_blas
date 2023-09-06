/*
 *	Wrapper to acces the different blas inmplementation 
 *
 *
 *
 */

//#include "include/libgpublas.h"
#include "include/rocblas.hpp"
//#include "include/cublas.hpp"



extern "C" int gpu_dgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double alpha, double* A, int64_t lda,\
		double* B, int64_t ldb, double beta, double* C, int64_t ldc)
{
	dgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}
