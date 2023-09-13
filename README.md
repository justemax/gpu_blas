# gpu_blas

##Description
The objective of GPU BLAS is to provide a uniform interface to the user for the use of the different BLAS libraries on GPU.

The user will not need to know if he should use cublas, rocblas or mkl in his code. A simple call to the library will be necessary. This will make the code more easily portable.

When installing the library, you will need to specify the platform on which it is to be installed.
For example:

--enable-rocblas,  if the server uses an AMD GPU

--enable-cublas, for NVIDIA

--enable-MKL, for Intel

This library is currently only intended for use on GPUs. It does not manage data transfer. The data must be allocated to the GPU from the application calling the library.

The library is not intended to provide a complete offload interface (It does not manage data transfer, data allocation, threads, etc.). Their  goal is to offer a uniform interface for the different BLAS libraries on GPU.

## Installation

To install the library 

<code> 	./autogen.sh
	./configure --enable-[openmp|cublas|rocblas] CXX=[Your compiler] --prefix=[Install directory]
	make; make install </code> 

It is important to specify the compiler. Otherwise it takes the system default.

The default flags to support libs are set to the following combinations:

	- cublas / nvcc
	- rocblas / hipcc
	- rocblas / clang++
	- openmp / hipcc
	- openmp / g++
	- openmp / clang++

For other combinations you have to specified the flags with CXXFLAGS.
