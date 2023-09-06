#include <stdio.h>
#include <stdlib.h>
#include <rocblas/rocblas.h>



//#include <hip/hip_runtime>



void* init_rocblas();

void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int LDC);
