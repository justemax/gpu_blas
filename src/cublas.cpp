#include "../include/cublas.hpp"
#include <cublas_v2.h>

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



cublasDiagType_t convert_diag(char DIAG)
{
	cublasDiagType_t ret;
	if(DIAG == 'N' || DIAG == 'n')
		ret = CUBLAS_DIAG_NON_UNIT;
	else if(DIAG == 'U' || DIAG == 'u')
		ret = CUBLAS_DIAG_UNIT;

	return ret;
}

cublasSideMode_t convert_side(char SIDE)
{
	cublasSideMode_t ret;
	if(SIDE == 'L' || SIDE == 'l')
		ret = CUBLAS_SIDE_LEFT;
	else if(SIDE == 'r' || SIDE == 'R')
		ret = CUBLAS_SIDE_RIGHT;
	return ret;
}
cublasFillMode_t convert_fill(char UPLO)
{
	cublasFillMode_t ret;
	if(UPLO == 'U' || UPLO == 'u')
		ret == CUBLAS_FILL_MODE_UPPER;
	else if(UPLO == 'L' || UPLO == 'l')
		ret == CUBLAS_FILL_MODE_LOWER;
	return ret;

}




//XGEMV


void sgemv(char transA, int m, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSgemv(handle, convert_to_cublas_trans(transA), m, n, &alpha, A, lda, X, incx, &beta, Y, incy);


}
void dgemv(char transA, int m, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDgemv(handle, convert_to_cublas_trans(transA), m, n, &alpha, A, lda, X, incx, &beta, Y, incy);


}

void cgemv(char transA, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCgemv(handle, convert_to_cublas_trans(transA), m, n, &alpha, A, lda, X, incx, &beta, Y, incy);


}

void zgemv(char transA, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZgemv(handle, convert_to_cublas_trans(transA), m, n, &alpha, A, lda, X, incx, &beta, Y, incy);


}



//XGBMV

void sgbmv(char transA, int m, int n, int kl, int ku, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSgbmv(handle, convert_to_cublas_trans(transA), m, n, kl, ku, &alpha, A, lda, X, incx, &beta, Y, incy);


}

void dgbmv(char transA, int m, int n, int kl, int ku, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDgbmv(handle, convert_to_cublas_trans(transA), m, n, kl, ku, &alpha, A, lda, X, incx, &beta, Y, incy);


}
void cgbmv(char transA, int m, int n, int kl, int ku, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCgbmv(handle, convert_to_cublas_trans(transA), m, n, kl, ku, &alpha, A, lda, X, incx, &beta, Y, incy);


}
void zgbmv(char transA, int m, int n, int kl, int ku, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZgbmv(handle, convert_to_cublas_trans(transA), m, n, kl, ku, &alpha, A, lda, X, incx, &beta, Y, incy);


}




//XSYMV

void ssymv(char UPLO, int n, float alpha, float* A, int lda, float* X, int incx, float beta, float* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSsymv(handle, convert_fill(UPLO), n, &alpha, A, lda, X, incx, &beta, Y, incy);


}
void dsymv(char UPLO, int n, double alpha, double* A, int lda, double* X, int incx, double beta, double* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDsymv(handle, convert_fill(UPLO), n, &alpha, A, lda, X, incx, &beta, Y, incy);


}

void csymv(char UPLO, int n, float_complex alpha, float_complex* A, int lda, float_complex* X, int incx, float_complex beta, float_complex* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCsymv(handle, convert_fill(UPLO), n, &alpha, A, lda, X, incx, &beta, Y, incy);


}
void zsymv(char UPLO, int n, double_complex alpha, double_complex* A, int lda, double_complex* X, int incx, double_complex beta, double_complex* Y, int incy)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZsymv(handle, convert_fill(UPLO), n, &alpha, A, lda, X, incx, &beta, Y, incy);


}



//XSPMV

void sspmv(char UPLO, int n, float alpha, float* AP, float* X, int incx, float beta, float* Y, int inc) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSspmv(handle, convert_fill(UPLO), n, &alpha, AP, X, incx, &beta, Y, inc);


}
void dspmv(char UPLO, int n, double alpha, double* AP, double* X, int incx, double beta, double* Y, int inc) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDspmv(handle, convert_fill(UPLO), n, &alpha, AP, X, incx, &beta, Y, inc);


}







//XTRMV

void strmv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasStrmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}
void dtrmv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDtrmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}
void ctrmv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCtrmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}
void ztrmv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZtrmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}




//XTBMV

void stbmv(char UPLO, char transA, char DIAG, int n, int k, float* A, int lda, float* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasStbmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}


void dtbmv(char UPLO, char transA, char DIAG, int n, int k, double* A, int lda, double* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDtbmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}
void ctbmv(char UPLO, char transA, char DIAG, int n, int k, float_complex* A, int lda, float_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCtbmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}
void ztbmv(char UPLO, char transA, char DIAG, int n, int k, double_complex* A, int lda, double_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZtbmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}




//XTPMV

void stpmv(char UPLO, char transA, char DIAG, int n, float* AP, float* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasStpmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, AP, X, incx);


}
void dtpmv(char UPLO, char transA, char DIAG, int n, double* AP, double* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDtpmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, AP, X, incx);


}
void ctpmv(char UPLO, char transA, char DIAG, int n, float_complex* AP, float_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCtpmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, AP, X, incx);


}
void ztpmv(char UPLO, char transA, char DIAG, int n, double_complex* AP, double_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZtpmv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, AP, X, incx);


}



//XTRSV


void strsv(char UPLO, char transA, char DIAG, int n, float* A, int lda, float* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasStrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}
void dtrsv(char UPLO, char transA, char DIAG, int n, double* A, int lda, double* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDtrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}
void ctrsv(char UPLO, char transA, char DIAG, int n, float_complex* A, int lda, float_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCtrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}
void ztrsv(char UPLO, char transA, char DIAG, int n, double_complex* A, int lda, double_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZtrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, A, lda, X, incx);


}



//XTBSV

void stbsv(char UPLO, char transA, char DIAG, int n, int k, float* A, int lda, float* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
//	cublasStatus_t error = cublasStrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}
void dtbsv(char UPLO, char transA, char DIAG, int n, int k, double* A, int lda, double* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	//cublasStatus_t error = cublasDtrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}
void ctbsv(char UPLO, char transA, char DIAG, int n, int k, float_complex* A, int lda, float_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	//cublasStatus_t error = cublasCtrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}
void ztbsv(char UPLO, char transA, char DIAG, int n, int k, double_complex* A, int lda, double_complex* X, int incx)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	//cublasStatus_t error = cublasZtrsv(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), convert_diag(DIAG), n, k, A, lda, X, incx);


}



//XGER

void sger(int m, int n, float alpha, float* X, int incx, float* Y, int incy, float* A, int lda)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSger(handle, m, n, &alpha, X, incx, Y, incy, A, lda);


}
void dger(int m, int n, double alpha, double* X, int incx, double* Y, int incy, double* A, int lda)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDger(handle, m, n, &alpha, X, incx, Y, incy, A, lda);


}

//XSYR

void ssyr(char UPLO, int n, float alpha, float* X, int incx, float* A, int lda)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSsyr(handle, convert_fill(UPLO), n, &alpha, X, incx, A, lda);


}

void dsyr(char UPLO, int n, double alpha, double* X, int incx, double* A, int lda)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDsyr(handle, convert_fill(UPLO), n, &alpha, X, incx, A, lda);


}
void csyr(char UPLO, int n, float_complex alpha, float_complex* X, int incx, float_complex* A, int lda)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasCsyr(handle, convert_fill(UPLO), n, &alpha, X, incx, A, lda);


}
void zsyr(char UPLO, int n, double_complex alpha, double_complex* X, int incx, double_complex* A, int lda)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasZsyr(handle, convert_fill(UPLO), n, &alpha, X, incx, A, lda);


}


//XSPR

void sspr(char UPLO, int n, float alpha, float* X, int incx, float* AP)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasSspr(handle, convert_fill(UPLO), n, &alpha, X, incx, AP);


}
void dspr(char UPLO, int n, double alpha, double* X, int incx, double* AP)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDspr(handle, convert_fill(UPLO), n, &alpha, X, incx, AP);


}
void cspr(char UPLO, int n, float_complex alpha, float_complex* X, int incx, float_complex* AP)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
//	cublasStatus_t error = cublasCspr(handle, convert_fill(UPLO), n, &alpha, X, incx, AP);


}
void zspr(char UPLO, int n, double_complex alpha, double_complex* X, int incx, double_complex* AP)
{
	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
//	cublasStatus_t error = cublasZspr(handle, convert_fill(UPLO), n, &alpha, X, incx, AP);


}





/******
  BLAS 3
  *****/


//Xgemm


void dgemm(char transA, char transB, int M, int N, int K, double ALPHA, double* A, int LDA, double* B, int LDB, double BETA, double* C, int64_t LDC)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();
	
	cublasStatus_t error = cublasDgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);


}	



void sgemm(char transA, char transB, int M, int N, int K, const float ALPHA, float* A, int LDA, float* B, int LDB, const float BETA, float* C, int LDC)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasSgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

		
}


void hgemm(char transA, char transB, int M, int N, int K, half ALPHA, half* A, int LDA, half* B, int LDB, half BETA, half* C, int LDC)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasHgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	
	
}



void cgemm(char transA, char transB, int M, int N, int K, float_complex ALPHA, float_complex* A, int LDA, float_complex* B, int LDB, float_complex BETA, float_complex* C, int LDC)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasCgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	

	
}


void zgemm(char transA, char transB, int M, int N, int K, double_complex ALPHA, double_complex* A, int LDA, double_complex* B, int LDB, double_complex BETA, double_complex* C, int LDC)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasZgemm(handle, convert_to_cublas_trans(transA), convert_to_cublas_trans(transB), M, N, K, &ALPHA, A, LDA, B, LDB, &BETA, C, LDC);	
		
}



void ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	//cublasStatus_t error = cuSsymm(handle, convert_side(SIDE), convert_fill(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuDsymm(handle, convert_side(SIDE), convert_fill(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuCsymm(handle, convert_side(SIDE), convert_fill(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsymm(handle, convert_side(SIDE), convert_fill(UPLO), m, n, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}



//Xsyrk

void ssyrk(char UPLO, char transA, int n, int k, float alpha, float* A, int lda, float beta, float* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsymm(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda,&beta, C, ldc);	
		
}


void dsyrk(char UPLO, char transA, int n, int k, double alpha, double* A, int lda, double beta, double* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsymm(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda,&beta, C, ldc);	
		
}
void csyrk(char UPLO, char transA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex beta, float_complex* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsymm(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda,&beta, C, ldc);	
		
}
void zsyrk(char UPLO, char transA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex beta, double_complex* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsymm(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda,&beta, C, ldc);	
		
}




//Xsyr2k



void ssyr2k(char UPLO, char TransA, int n, int k, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsyr2k(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}


void dsyr2k(char UPLO, char TransA, int n, int k, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsyr2k(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void csyr2k(char UPLO, char TransA, int n, int k, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsyr2k(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}
void zsyr2k(char UPLO, char transA, int n, int k, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cuZsyr2k(handle, convert_fill(UPLO), convert_to_cublas_trans(transA), n, k, &alpha, A, lda, B, ldb, &beta, C, ldc);	
		
}

//Xtrmm



void strmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float alpha, float* A, int lda, float* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cublasStrmm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}
void dtrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double alpha, double* A, int lda, double* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cublasDtrmm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}
void ctrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cublasCtrmm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}
void ztrmm(char SIDE, char UPLO, char TransA, char DIAG, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

//	cublasStatus_t error = cublasZtrmm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}





//Xtrsm


void strsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float alpha, float* A, int lda, float* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasStrsm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}


void dtrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double alpha, double* A, int lda, double* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasDtrsm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}


void ctrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb)
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasCtrsm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}


void ztrsm(char SIDE, char UPLO, char TransA, char DIAG, int  m, int  n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb) 
{

	cublasHandle_t handle = (cublasHandle_t)init_cublas();

	cublasStatus_t error = cublasZtrsm(handle, convert_side(SIDE), convert_fill(UPLO), convert_to_cublas_trans(TransA), convert_diag(DIAG), m, n, &alpha, A, lda, B, ldb);
}




