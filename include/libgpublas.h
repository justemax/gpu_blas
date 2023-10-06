#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_ROCBLAS
#include <rocblas/rocblas.h>
typedef rocblas_float_complex float_complex ;
typedef rocblas_double_complex double_complex ;
typedef rocblas_half half ;
#elif HAVE_CUBLAS
typedef cuComplex float_complex ;
typedef cuDoubleComplex double_complex ;
typedef __half half ;
#endif



#ifdef __cplusplus
extern "C"
{
#endif
//XGEMM
int gpu_dgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double alpha, double* A, int64_t lda, double* B, int64_t ldb, double beta, double* C, int64_t ldc);


int gpu_sgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, const float alpha, float* A, int64_t lda, float* B, int64_t ldb, const float beta, float* C, int64_t ldc);

int gpu_hgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, half alpha, half* A, int64_t lda, half* B, int64_t ldb, half beta, half* C, int64_t ldc);

int gpu_cgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, float_complex alpha, float_complex* A, int64_t lda, float_complex* B, int64_t ldb, float_complex beta, float_complex* C, int64_t ldc);

int gpu_zgemm(char transA, char transB, int64_t m, int64_t n, int64_t k, double_complex alpha, double_complex* A, int64_t lda, double_complex* B, int64_t ldb, double_complex beta, double_complex* C, int64_t ldc);


//XSYMM


extern "C" int gpu_ssymm(char SIDE, char UPLO, int m, int n, float alpha, float* A, int lda, float* B, int ldb, float beta, float* C, int ldc);

extern "C" int gpu_dsymm(char SIDE, char UPLO, int m, int n, double alpha, double* A, int lda, double* B, int ldb, double beta, double* C, int ldc);

extern "C" int gpu_csymm(char SIDE, char UPLO, int m, int n, float_complex alpha, float_complex* A, int lda, float_complex* B, int ldb, float_complex beta, float_complex* C, int ldc);

extern "C" int gpu_zsymm(char SIDE, char UPLO, int m, int n, double_complex alpha, double_complex* A, int lda, double_complex* B, int ldb, double_complex beta, double_complex* C, int ldc);



#ifdef __cplusplus
}
#endif
