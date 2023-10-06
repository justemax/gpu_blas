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


// Xgemm

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


//Xsymm

extern "C" int gpu_ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{
	ssymm(SIDE, UPLO, m, n, alpha, A, lda, B, ldb, beta, C, ldc); 
	return 0;
}

extern "C" int gpu_dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{
	dsymm(SIDE, UPLO, m, n, alpha, A, lda, B, ldb, beta, C, ldc); 
	return 0;
}

extern "C" int gpu_csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{
	csymm(SIDE, UPLO, m, n, alpha, A, lda, B, ldb, beta, C, ldc); 
	return 0;
}


extern "C" int gpu_zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{
	zsymm(SIDE, UPLO, m, n, alpha, A, lda, B, ldb, beta, C, ldc); 
	return 0;
}

//Xsyrk
extern "C" int gpu_ssyrk(char UPLO, char transA, int n, int k, float alpha, float* A, int lda, float beta, float* C, int ldc)
{
	ssyrk(UPLO, transA, n, k, alpha, A, lda, beta, C, ldc);
	return 0;
}

extern "C" int gpu_dsyrk(char UPLO, char transA, int n, int k, double alpha, double* A, int lda, double beta, double* C, int ldc)
{
	 
	dsyrk(UPLO, transA, n, k, alpha, A, lda, beta, C, ldc);
	return 0;
}

extern "C" int gpu_csyrk(char UPLO, char transA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex beta, float_complex* C, int ldc)
{
	csyrk(UPLO, transA, n, k, alpha, A, lda, beta, C, ldc);
	return 0;
}
extern "C" int gpu_zsyrk(char UPLO, char transA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex beta, double_complex* C, int ldc)
{
	zsyrk(UPLO, transA, n, k, alpha, A, lda, beta, C, ldc);
	return 0;
}



//Syr2k

extern "C" int gpu_ssyr2k(char UPLO, char TransA, int n, int k, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{
	ssyr2k(UPLO, TransA, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;
}

extern "C" int gpu_dsyr2k(char UPLO, char TransA, int n, int k, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{
	dsyr2k(UPLO, TransA, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;
}


extern "C" int gpu_csyr2k(char UPLO, char TransA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{
	csyr2k(UPLO, TransA, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;
}


extern "C" int gpu_zsyr2k(char UPLO, char TransA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{
	zsyr2k(UPLO, TransA, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
	return 0;
}




















