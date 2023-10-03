#include <cublas_v2.h>
#include "libgpublas.h"
void cublas_manage_error(int error_number);

cublasHandle_t init_cublas();


cublasOperation_t convert_to_cublas_trans(char* trans);



void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int64_t LDC);




void sgemm(char transA, char transB, int M, int N, int K, float ALPHA, float* A, int LDA, float* B, int LDB, float BETA, float* C, int LDC);



void hgemm(char transA, char transB, int M, int N, int K, half ALPHA, half* A, int LDA, half* B, int LDB, half BETA, half* C, int LDC);


void cgemm(char transA, char transB, int M, int N, int K, float_complex ALPHA, float_complex* A, int LDA, float_complex* B, int LDB, float_complex BETA, float_complex* C, int LDC);



void zgemm(char transA, char transB, int M, int N, int K, double_complex ALPHA, double_complex* A, int LDA, double_complex* B, int LDB, double_complex BETA, double_complex* C, int LDC);
