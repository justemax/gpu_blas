#include <cublas.h>
void cublas_manage_error(int error_number);

void* init_cublas();


cublasOperation_t convert_to_cublas_trans(char* trans);



void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, LDC);
