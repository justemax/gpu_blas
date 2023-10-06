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


cublasSideMode convert_side(char* SIDE)
{
	cublasSideMode ret;
	if(SIDE == 'L' || side == 'l')
		ret = CUBLAS_SIDE_LEFT;
	else if(SIDE == 'r' || SIDE == 'R')
		ret = CUBLAS_SIDE_RIGHT;
	return ret
}
cublasFillMode convert_fill(char* UPLO)
{
	cublasFillMode ret;
	if(UPLO == 'U' || UPLO == 'u')
		ret == CUBLAS_FILL_MODE_UPPER;
	else if(UPLO == 'L' || UPLO == 'l')
		ret == CUBLAS_FILL_MODE_LOWER;
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

	ret = cublasCgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	
}


void zgemm(char transA, char transB, int M, int N, int K, double_complex ALPHA, double_complex* A, int LDA, double_complex* B, int LDB, double_complex BETA, double_complex* C, int LDC)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cublasZgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	
		
}



void ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cuSsymm(handle, convert_side(SIDE), convert_FILL(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cuDsymm(handle, convert_side(SIDE), convert_FILL(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cuCsymm(handle, convert_side(SIDE), convert_FILL(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{

	void* handle = (cublasHandle_t)init_cublas();

	ret = cuZsymm(handle, convert_side(SIDE), convert_FILL(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}

