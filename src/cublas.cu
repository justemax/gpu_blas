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



void sgemm(char transA, char transB, int M, int N, int K, const float ALPHA, float* A, int LDA, float* B, int LDB, const float BETA, float* C, int LDC)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cublasSgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

		
}


void hgemm(char transA, char transB, int M, int N, int K, half ALPHA, half* A, int LDA, half* B, int LDB, half BETA, half* C, int LDC)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cublasHgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	
	
}



void cgemm(char transA, char transB, int M, int N, int K, float_complex ALPHA, float_complex* A, int LDA, float_complex* B, int LDB, float_complex BETA, float_complex* C, int LDC)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret =rocblas_cgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	
}


void zgemm(char transA, char transB, int M, int N, int K, double_complex ALPHA, double_complex* A, int LDA, double_complex* B, int LDB, double_complex BETA, double_complex* C, int LDC)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret =rocblas_zgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	
		
}
