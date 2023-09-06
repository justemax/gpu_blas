#include "include/rocblas.hpp"

#include <rocblas/rocblas.h>
void* init_rocblas()
{

	rocblas_handle handle;
	rocblas_create_handle(&handle);
	return handle;
}

void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int LDC)
{

	printf("coucou\n");
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_dgemm((rocblas_handle)handle, rocblas_operation_none, rocblas_operation_none, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		fprintf(stderr, "Something went wrong");
		exit(EXIT_FAILURE);
	}
		
}
