###
# Build sources
###

ACLOCAL_AMFLAGS = -I m4 -I include

AM_CPPFLAGS = -I$(top_builddir)/src -I$(top_builddir)/include

include_HEADERS = include/libgpublas.h

lib_LTLIBRARIES = libgpublas.la


libgpublas_la_SOURCES = "" 
libgpublas_la_SOURCES += src/gpublas.cpp

if HAVE_CUBLAS
	libgpublas_la_SOURCES += src/cublas.cpp
endif


if HAVE_ROCBLAS
	libgpublas_la_SOURCES += src/rocblas.cpp

endif

if HAVE_OMPBLAS
	libgpublas_la_SOURCES += src/ompblas.cpp
endif


METASOURCES=auto

