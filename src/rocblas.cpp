#include "../include/rocblas.hpp"


void* init_rocblas()
{

	rocblas_handle handle;
	rocblas_create_handle(&handle);
	return handle;
}

void dgemm(char* transA, char* transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int LDC)
{

	void* handle = (rocblas_handle)init_rocblas();
	cublasStatus ret = CUBLAS_STATUS_SUCCESS;

	ret = cublasDgemm(handle, transA, transB, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		fprintf(stderr, "Something went wrong");
		exit(EXIT_FAILURE);
	}
		
}
