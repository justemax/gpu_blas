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




//XGEMV

extern "C" int gpu_sgemv(char transA, int m, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy) 
{
	sgemv(transA, m, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}


extern "C" int gpu_dgemv(char transA, int m, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy) 
{
	dgemv(transA, m, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}
extern "C" int gpu_cgemv(char transA, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy)
{
	cgemv(transA, m, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}
extern "C" int gpu_zgemv(char transA, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy)
{
	zgemv(transA, m, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}




//XGBMV

extern "C" int gpu_sgbmv(char transA, int m, int n, int kl, int ku, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy)
{
	sgbmv(transA, m, n, kl, ku, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}

extern "C" int gpu_dgbmv(char transA, int m, int n, int kl, int ku, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy) 
{
	dgbmv(transA, m, n, kl, ku, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}
extern "C" int gpu_cgbmv(char transA, int m, int n, int kl, int ku, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy) 
{
	cgbmv(transA, m, n, kl, ku, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}
extern "C" int gpu_zgbmv(char transA, int m, int n, int kl, int ku, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy) 
{
	zgbmv(transA, m, n, kl, ku, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}


//XSYMV

int gpu_ssymv(char UPLO, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy)
{
	ssymv(UPLO, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}



int gpu_dsymv(char UPLO, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy)
{
	dsymv(UPLO, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}
int gpu_csymv(char UPLO, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy)
{
	csymv(UPLO, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}
int gpu_zsymv(char UPLO, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy)
{
	zsymv(UPLO, n, alpha, A, lda, X, incx, beta, Y, incy);
	return 0;
}



//XSPMV

int gpu_sspmv(char UPLO, int n, float alpha, float* AP, float* X, int incx, float beta, float* Y, int inc) 
{
	sspmv(UPLO, n, alpha, AP, X, incx, beta, Y, inc);
	return 0;
}

int gpu_dspmv(char UPLO, int n, double alpha, double* AP, double* X, int incx, double beta, double* Y, int inc) 
{
	dspmv(UPLO, n, alpha, AP, X, incx, beta, Y, inc);
	return 0;
}



//XTRMV

int gpu_strmv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx)
{
	strmv(UPLO, transA, DIAG, n, A, lda, X, incx);
	return 0;
}

int gpu_dtrmv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx)
{
	dtrmv(UPLO, transA, DIAG, n, A, lda, X, incx);
	return 0;
}
int gpu_ctrmv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx)
{
	ctrmv(UPLO, transA, DIAG, n, A, lda, X, incx);
	return 0;
}
int gpu_ztrmv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx)
{
	ztrmv(UPLO, transA, DIAG, n, A, lda, X, incx);
	return 0;
}





/*****
 * BLAS 3
 * ****/


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

//Xtrmm

extern "C" int gpu_strmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float alpha, float* A, int lda, float* B, int ldb)
{
	strmm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, lda, B, ldb);
	return 0;
}

extern "C" int gpu_dtrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double alpha, double* A, int lda, double* B, int ldb)
{
	dtrmm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, lda, B, ldb);
	return 0;
}


extern "C" int gpu_ctrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb)
{
	ctrmm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, lda, B, ldb);
	return 0;
}


extern "C" int gpu_ztrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb)
{
	ztrmm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, lda, B, ldb);
	return 0;
}



//Xtrsm



extern "C" int gpu_strsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float alpha, float* A, int LDA, float* B, int ldb)
{
	strsm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, LDA, B, ldb);
	return 0;
}

extern "C" int gpu_dtrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double alpha, double* A, int LDA, double* B, int ldb)
{
	dtrsm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, LDA, B, ldb);
	return 0;
}
extern "C" int gpu_ctrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float_complex alpha, float_complex* A, int LDA, float_complex* B, int ldb)
{
	ctrsm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, LDA, B, ldb);
	return 0;
}
extern "C" int gpu_ztrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double_complex alpha, double_complex* A, int LDA, double_complex* B, int ldb) 
{
	ztrsm(SIDE, UPLO, TransA, DIAG, m, n, alpha, A, LDA, B, ldb);
	return 0;
}





















