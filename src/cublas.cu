#include "../include/cublas.hpp"

void cublas_manage_error(int error_number)
{
	if(error_number == 1)
	{
		printf("Bad transformation type");
	}
}

cublasHandle_t init_cublas()
{

	cublasHandle_t handle;
	cublasCreate(&handle);
	return handle;

}

cublasOperation_t convert_to_cublas_trans(char trans)
{
	cublasOperation_t ret;
	if(trans == 'N' || trans == 'n'){
		 ret = CUBLAS_OP_N; 
	}else if(trans == 'C' || trans == 'c')
	{
		ret = CUBLAS_OP_C;
	}else if(trans == 'T' || trans == 't')
	{
		ret = CUBLAS_OP_T;
	}else
	{
		cublas_manage_error(1);
	}	
	
	return ret;
}

void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int64_t LDC)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);



	

}	
