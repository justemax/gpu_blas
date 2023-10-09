#include "../include/rocblas.hpp"

#include <rocblas/rocblas.h>
void* init_rocblas()
{

	rocblas_handle handle;
	rocblas_create_handle(&handle);
	return handle;
}


rocblas_diagonal convert_diag(char diag){
	rocblas_diagonal ret;
	if(diag == 'U' || diag == 'U')
		ret = rocblas_diagonal_unit;
	else if(diag == 'N' || diag == 'n')
		ret = rocblas_diagonal_non_unit;

	return ret;
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




//Xsyrk

void ssyrk(char UPLO, char transA, int n, int k, float alpha, float* A, int lda, float beta, float* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_ssyrk((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void dsyrk(char UPLO, char transA, int n, int k, double alpha, double* A, int lda, double beta, double* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_dsyrk((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

void csyrk(char UPLO, char transA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex beta, float_complex* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_csyrk((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

void zsyrk(char UPLO, char transA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex beta, double_complex* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_zsyrk((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

//Xsyr2k



void ssyr2k(char UPLO, char TransA, int n, int k, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_ssyr2k((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda, B, ldb,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

void dsyr2k(char UPLO, char TransA, int n, int k, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_dsyr2k((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda, B, ldb,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void csyr2k(char UPLO, char TransA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_csyr2k((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda, B, ldb,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void zsyr2k(char UPLO, char TransA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_zsyr2k((rocblas_handle)handle, convert_uplo(UPLO), rocblas_operation_none, n, k, &alpha, A, lda, B, ldb,  &beta, C, ldc);	

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}


//Xtrmm




void strmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float alpha, float* A, int lda, float* B, int ldb)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_strmm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), rocblas_operation_none, convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb); 

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

void dtrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double alpha, double* A, int lda, double* B, int ldb)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_dtrmm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), rocblas_operation_none, convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb); 

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void ctrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_ctrmm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), rocblas_operation_none, convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb); 

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}
void ztrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb)
{
	void* handle = (rocblas_handle)init_rocblas();
	rocblas_status ret ;

	ret = rocblas_ztrmm((rocblas_handle)handle, convert_side(SIDE), convert_uplo(UPLO), rocblas_operation_none, convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb); 

	if(ret != rocblas_status_success)
	{
		exit(EXIT_FAILURE);
	}
	
}

