#include "../include/libgpublas.h"
#include <omp.h>


int main(void)
{

	double m1[] = {1.4, 3.5, 123, 7.9, 0,
			3.78, 3.789, 67.9, 12.34, 1,\
			0, 0, 0, 12.7, 8,\
			1, 34.3, 12.9, 9, 0,\
			0, 23, 23, 1.1, 0};

	double m2[] = {12, 6, 8.9, 0, 0,\
			1, 45, 78.9, 9.908, -13.7,\
			0, 0, 45.8, 978, 1,\
			2, 3, 0, 0, 13.8,\
			12, 45.8, 98, 8.765, 7};


	double mres[] = {36.1, 189.6, 5922.01, 120328.678, 184.07,\
			85.829, 276.005, 3540.4141, 66452.506412, 193.2827,\
			121.4, 404.5, 784, 70.12, 231.26,\
			64.3, 1576.5, 3305.99, 12956.0444, -332.81,\
			25.2, 1038.3, 2868.1, 22721.884, -276.92};

	double* mresGPU = (double*)malloc(sizeof(double)*5*5);

	double* dm1 = (double*) omp_target_alloc((sizeof(double) * 5 *5), 0);
	double* dm2 = (double*)omp_target_alloc((sizeof(double) * 5 *5), 0);
	double* dmres = (double*)omp_target_alloc((sizeof(double) * 5 *5), 0);


	omp_target_memcpy(dm1, m1, sizeof(double)*5*5, 0, 0, 0, omp_get_initial_device());
	omp_target_memcpy(dm2, m2, sizeof(double)*5*5, 0, 0, 0, omp_get_initial_device());


	gpu_dgemm('N', 'N', 5, 5, 5, 1.0, dm1, 5, dm2, 5, 0.0, dmres, 5); 





	omp_target_memcpy(mresGPU, dmres, sizeof(double)*5*5, 0, 0, omp_get_initial_device(), 0);


	//Compare the two matrix
	
	for(int i=0; i < 5; i++)
	{
		for(int j=0; j < 5; j++)
		{
			if(mresGPU[i*5+j] - mres[i*5+j] > 0.0001)
			{
				printf("marcho pas\n");
				return 1;
			}
		}
	}


	return 0;
}
