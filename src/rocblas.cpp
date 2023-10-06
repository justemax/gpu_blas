#include "../include/rocblas.hpp"

#include <rocblas/rocblas.h>
void* init_rocblas()
{

	rocblas_handle handle;
	rocblas_create_handle(&handle);
	return handle;
}



rocblas_fill convert_uplo(char uplo)
{
	rocblas_fill ret;
	if(uplo == 'U' || uplo == 'u')
		ret = rocblas_fill_upper;
	else if(uplo == 'L' || uplo == 'l')
		ret = rocblas_fill_lower;
	else
		ret = rocblas_fill_full;

	return ret;
}

rocblas_side convert_side(char side)
{
	rocblas_side ret;
	if(side == 'L' || side == 'l')
		ret = rocblas_side_left;
	else if(side == 'R' || side == 'l')
		ret = rocblas_side_right;
	else
		ret = rocblas_side_both;
	return ret;

}

void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int LDC)
{

	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_dgemm((rocblas_handle)handle, rocblas_operation_none, rocblas_operation_none, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
		
}



void sgemm(char transA, char transB, int M, int N, int K, const float ALPHA, float* A, int LDA, float* B, int LDB, const float BETA, float* C, int LDC)
{

	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_sgemm((rocblas_handle)handle, rocblas_operation_none, rocblas_operation_none, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
		
}
void hgemm(char transA, char transB, int M, int N, int K, half ALPHA, half* A, int LDA, half* B, int LDB, half BETA, half* C, int LDC)
{

	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_hgemm((rocblas_handle)handle, rocblas_operation_none, rocblas_operation_none, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
		
}
void cgemm(char transA, char transB, int M, int N, int K, float_complex ALPHA, float_complex* A, int LDA, float_complex* B, int LDB, float_complex BETA, float_complex* C, int LDC)
{

	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_cgemm((rocblas_handle)handle, rocblas_operation_none, rocblas_operation_none, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
		
}

void zgemm(char transA, char transB, int M, int N, int K, double_complex ALPHA, double_complex* A, int LDA, double_complex* B, int LDB, double_complex BETA, double_complex* C, int LDC)
{

	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_zgemm((rocblas_handle)handle, rocblas_operation_none, rocblas_operation_none, M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
		
}





void ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_ssymm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

void dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_dsymm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_csymm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret =rocblas_zsymm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}




