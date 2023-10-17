#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_ROCBLAS
#include <rocblas/rocblas.h>
typedef rocblas_float_complex float_complex ;
typedef rocblas_double_complex double_complex ;
typedef rocblas_half half ;
#elif HAVE_CUBLAS
typedef cuComplex float_complex ;
typedef cuDoubleComplex double_complex ;
typedef __half half ;
#endif



#ifdef __cplusplus
extern "C"
{
#endif



//XGEMV


int gpu_sgemv(char transA, int m, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy); 

int gpu_dgemv(char transA, int m, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy) ;

int gpu_cgemv(char transA, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy);

int gpu_zgemv(char transA, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy);

//XGBMV

int gpu_sgbmv(char transA, int m, int n, int kl, int ku, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy); 

int gpu_dgbmv(char transA, int m, int n, int kl, int ku, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy); 

int gpu_cgbmv(char transA, int m, int n, int kl, int ku, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy); 

int gpu_zgbmv(char transA, int m, int n, int kl, int ku, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy); 


//XSYMV

int gpu_ssymv(char UPLO, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy);

int gpu_dsymv(char UPLO, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy);

int gpu_csymv(char UPLO, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy);

int gpu_zsymv(char UPLO, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy);

//XSPMV

int gpu_sspmv(char UPLO, int n, float alpha, float* AP, float* X, int incx, float beta, float* Y, int inc); 

int gpu_dspmv(char UPLO, int n, double alpha, double* AP, double* X, int incx, double beta, double* Y, int inc); 


//XTRMV

int gpu_strmv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx);

int gpu_dtrmv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx);

int gpu_ctrmv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx);

int gpu_ztrmv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx);


//XTBMV

int gpu_stbmv(char UPLO, char TransA, char DIAG, int n, int k, float* A, int lda, float* X, int incx);

int gpu_dtbmv(char UPLO, char TransA, char DIAG, int n, int k, double* A, int lda, double* X, int incx);

int gpu_ctbmv(char UPLO, char TransA, char DIAG, int n, int k, float_complex* A, int lda, float_complex* X, int incx);

int gpu_ztbmv(char UPLO, char TransA, char DIAG, int n, int k, double_complex* A, int lda, double_complex* X, int incx);

//XTPMV

int gpu_stpmv(char UPLO, char transA, char DIAG, int n, float* AP, float* X, int incx);

int gpu_dtpmv(char UPLO, char transA, char DIAG, int n, double* AP, double* X, int incx);

int gpu_ctpmv(char UPLO, char transA, char DIAG, int n, float_complex* AP, float_complex* X, int incx);

int gpu_ztpmv(char UPLO, char transA, char DIAG, int n, double_complex* AP, double_complex* X, int incx);



//XTRSV


int gpu_strsv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx);

int gpu_dtrsv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx);

int gpu_ctrsv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx);

int gpu_ztrsv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx);


//XTBSV

int gpu_stbsv(char UPLO, char transA, char DIAG, int n, int k, float* A, int lda, float* X, int incx);

int gpu_dtbsv(char UPLO, char transA, char DIAG, int n, int k, double* A, int lda, double* X, int incx);

int gpu_ctbsv(char UPLO, char transA, char DIAG, int n, int k, float_complex* A, int lda, float_complex* X, int incx);

int gpu_ztbsv(char UPLO, char transA, char DIAG, int n, int k, double_complex* A, int lda, double_complex* X, int incx);


//XGER

int gpu_sger(int m, int n, float alpha, float* X, int incx, float* Y, int incy, float* A, int lda);

int gpu_dger(int m, int n, double alpha, double* X, int incx, double* Y, int incy, double* A, int lda);

int gpu_cger(int m, int n, float_complex alpha, float_complex* X, int incx, float_complex* Y, int incy, float_complex* A, int lda);

int gpu_zger(int m, int n, double_complex alpha, double_complex* X, int incx, double_complex* Y, int incy, double_complex* A, int lda);


//XSYR

int gpu_ssyr(char UPLO, int n, float alpha, float* X, int incx, float* A, int lda);

int gpu_dsyr(char UPLO, int n, double alpha, double* X, int incx, double* A, int lda);

int gpu_csyr(char UPLO, int n, float_complex alpha, float_complex* X, int incx, float_complex* A, int lda);

int gpu_zsyr(char UPLO, int n, double_complex alpha, double_complex* X, int incx, double_complex* A, int lda);

//XSPR

int gpu_sspr(char UPLO, int n, float alpha, float* X, int incx, float* AP);

int gpu_dspr(char UPLO, int n, double alpha, double* X, int incx, double* AP);

int gpu_cspr(char UPLO, int n, float_complex alpha, float_complex* X, int incx, float_complex* AP);

int gpu_zspr(char UPLO, int n, double_complex alpha, double_complex* X, int incx, double_complex* AP);


//XSYR2


//XSPR2

//XGEMM
int gpu_dgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double alpha, double* A, int64_t lda, double* B, int64_t ldb, double beta, double* C, int64_t ldc);


int gpu_sgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, const float alpha, float* A, int64_t lda, float* B, int64_t ldb, const float beta, float* C, int64_t ldc);

int gpu_hgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, half alpha, half* A, int64_t lda, half* B, int64_t ldb, half beta, half* C, int64_t ldc);

int gpu_cgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, float_complex alpha, float_complex* A, int64_t lda, float_complex* B, int64_t ldb, float_complex beta, float_complex* C, int64_t ldc);

int gpu_zgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double_complex alpha, double_complex* A, int64_t lda, double_complex* B, int64_t ldb, double_complex beta, double_complex* C, int64_t ldc);


//XSYMM


int gpu_ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc);

int gpu_dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc);

int gpu_csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc);

int gpu_zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc);

//Xsyrk

int gpu_ssyrk(char UPLO, char transA, int n, int k, float alpha, float* A, int lda, float beta, float* C, int ldc);

int gpu_dsyrk(char UPLO, char transA, int n, int k, double alpha, double* A, int lda, double beta, double* C, int ldc);

int gpu_csyrk(char UPLO, char transA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex beta, float_complex* C, int ldc);

int gpu_zsyrk(char UPLO, char transA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex beta, double_complex* C, int ldc);


//Xsyr2k


int gpu_ssyr2k(char UPLO, char TransA, int n, int k, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc);

int gpu_dsyr2k(char UPLO, char TransA, int n, int k, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc);

int gpu_csyr2k(char UPLO, char TransA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc);

int gpu_zsyr2k(char UPLO, char TransA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc);


//Xtrmm


int gpu_strmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float alpha, float* A, int lda, float* B, int ldb);

int gpu_dtrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double alpha, double* A, int lda, double* B, int ldb);

int gpu_ctrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb);

int gpu_ztrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb);


//Xtrsm


int gpu_strsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float alpha, float* A, int LDA, float* B, int ldb);

int gpu_dtrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double alpha, double* A, int LDA, double* B, int ldb);

int gpu_ctrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float_complex alpha, float_complex* A, int LDA, float_complex* B, int ldb);

int gpu_ztrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double_complex alpha, double_complex* A, int LDA, double_complex* B, int ldb) ;



#ifdef __cplusplus
}
#endif
