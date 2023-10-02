/*
 *	Wrapper to acces the different blas inmplementation 
 *
 *
 *
 */
#ifdef HAVE_ROCBLAS
#include "include/rocblas.hpp"
typedef rocblas_float_complex float_complex ;
typedef rocblas_double_complex double_complex ;
typedef rocblas_half half ;
#elif HAVE_CUBLAS
#include "include/cublas.hpp"
typedef cuComplex float_complex ;
typedef cuDoubleComplex double_complex ;
typedef __half half ;
#endif



extern "C" int gpu_dgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double alpha, double* A, int64_t lda,\
		double* B, int64_t ldb, double beta, double* C, int64_t ldc)
{
	dgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}

extern "C" int gpu_sgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, const float alpha, float* A, int64_t lda,\
		float* B, int64_t ldb, const float beta, float* C, int64_t ldc)
{
	sgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}

extern "C" int gpu_hgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, half alpha, half* A, int64_t lda,\
		half* B, int64_t ldb, half beta, half* C, int64_t ldc)
{
	hgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}

extern "C" int gpu_cgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, float_complex alpha, float_complex* A, int64_t lda,\
		float_complex* B, int64_t ldb, float_complex beta, float_complex* C, int64_t ldc)
{
	cgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}

extern "C" int gpu_zgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double_complex alpha, double_complex* A, int64_t lda,\
		double_complex* B, int64_t ldb, double_complex beta, double_complex* C, int64_t ldc)
{
	zgemm(transA, transA, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;    
}

