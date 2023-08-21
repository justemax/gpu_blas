###
# Build sources
###

ACLOACL_AMDFLAGS = -I m4 -I include

AM_CPPFLAGS = -I{$(top_builddir)/src -I$(top_builddir)/include

include_HEADERS = include/gpu_dgemm.h

lib_LTLIBRARIES = lib_gpu_blas.h


libgpublas_la_SOURCES = src/gpu_dgemm.cpp

if HAVE_CUBLAS
	libgpublas_la_SOURCES += src/cublas.cpp
endif


if HAVE_ROCBLAS
	libgpublas_la_SOURCES += src/rocblas.cpp

endif

if HAVE_OMPBLAS
	libgpublas_la_SOURCES += src/ompblas.cpp
endif
