#include <cublas_v2.h>
#include "libgpublas.h"
void cublas_manage_error(int error_number);

cublasHandle_t init_cublas();


cublasOperation_t convert_to_cublas_trans(char* trans);

cublasSideMode_t convert_side(char* SIDE);
cublasFillMode_t convert_fill(char* UPLO);
cublasDiagType_t convert_diag(char* DIAG);



//XGEMV


void sgemv(char transA, int m, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy); 

void dgemv(char transA, int m, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy) ;

void cgemv(char transA, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy);

void zgemv(char transA, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy);



//XGBMV

void sgbmv(char transA, int m, int n, int kl, int ku, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy); 

void dgbmv(char transA, int m, int n, int kl, int ku, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy); 

void cgbmv(char transA, int m, int n, int kl, int ku, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy); 

void zgbmv(char transA, int m, int n, int kl, int ku, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy); 



//XSYMV

void ssymv(char UPLO, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy);

void dsymv(char UPLO, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy);

void csymv(char UPLO, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy);

void zsymv(char UPLO, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy);



//XSPMV

void sspmv(char UPLO, int n, float alpha, float* AP, float* X, int incx, float beta, float* Y, int inc); 

void dspmv(char UPLO, int n, double alpha, double* AP, double* X, int incx, double beta, double* Y, int inc); 


//XTRMV

void strmv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx);

void dtrmv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx);

void ctrmv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx);

void ztrmv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx);



//XTBMV

void stbmv(char UPLO, char TransA, char DIAG, int n, int k, float* A, int lda, float* X, int incx);

void dtbmv(char UPLO, char TransA, char DIAG, int n, int k, double* A, int lda, double* X, int incx);

void ctbmv(char UPLO, char TransA, char DIAG, int n, int k, float_complex* A, int lda, float_complex* X, int incx);

void ztbmv(char UPLO, char TransA, char DIAG, int n, int k, double_complex* A, int lda, double_complex* X, int incx);



//XTPMV

void stpmv(char UPLO, char transA, char DIAG, int n, float* AP, float* X, int incx);

void dtpmv(char UPLO, char transA, char DIAG, int n, double* AP, double* X, int incx);

void dtpmv(char UPLO, char transA, char DIAG, int n, float_complex* AP, float_complex* X, int incx);

void ztpmv(char UPLO, char transA, char DIAG, int n, double_complex* AP, double_complex* X, int incx);



//XTRSV


void strsv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx);

void dtrsv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx);

void ctrsv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx);

void ztrsv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx);

//XTBSV

void stbsv(char UPLO, char transA, char DIAG, int n, int k, float* A, int lda, float* X, int incx);

void dtbsv(char UPLO, char transA, char DIAG, int n, int k, double* A, int lda, double* X, int incx);

void ctbsv(char UPLO, char transA, char DIAG, int n, int k, float_complex* A, int lda, float_complex* X, int incx);

void ztbsv(char UPLO, char transA, char DIAG, int n, int k, double_complex* A, int lda, double_complex* X, int incx);





/*
 * BLAS 3
 *
 * ****/


//Xgemm

void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int64_t LDC);

void sgemm(char transA, char transB, int M, int N, int K, float ALPHA, float* A, int LDA, float* B, int LDB, float BETA, float* C, int LDC);

void hgemm(char transA, char transB, int M, int N, int K, half ALPHA, half* A, int LDA, half* B, int LDB, half BETA, half* C, int LDC);

void cgemm(char transA, char transB, int M, int N, int K, float_complex ALPHA, float_complex* A, int LDA, float_complex* B, int LDB, float_complex BETA, float_complex* C, int LDC);

void zgemm(char transA, char transB, int M, int N, int K, double_complex ALPHA, double_complex* A, int LDA, double_complex* B, int LDB, double_complex BETA, double_complex* C, int LDC);


//Xsymm

void ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc);

void dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc);

void csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc);

void zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc);


//Xsyrk

void ssyrk(char UPLO, char transA, int n, int k, float alpha, float* A, int lda, float beta, float* C, int ldc);

void dsyrk(char UPLO, char transA, int n, int k, double alpha, double* A, int lda, double beta, double* C, int ldc);

void csyrk(char UPLO, char transA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex beta, float_complex* C, int ldc);

void zsyrk(char UPLO, char transA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex beta, double_complex* C, int ldc);

//Xsyr2k



void ssyr2k(char UPLO, char TransA, int n, int k, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc);

void dsyr2k(char UPLO, char TransA, int n, int k, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc);

void csyr2k(char UPLO, char TransA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc);

void zsyr2k(char UPLO, char TransA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc);



//Xtrmm


void strmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float alpha, float* A, int lda, float* B, int ldb);

void dtrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double alpha, double* A, int lda, double* B, int ldb);

void ctrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb);

void ztrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb);



//Xtrsm


void strsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float alpha, float* A, int LDA, float* B, int ldb);

void dtrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double alpha, double* A, int LDA, double* B, int ldb);

void ctrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float_complex alpha, float_complex* A, int LDA, float_complex* B, int ldb);

void ztrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double_complex alpha, double_complex* A, int LDA, double_complex* B, int ldb) ;



