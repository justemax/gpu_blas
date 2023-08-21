AC_INIT([gpu_blas],[0.0.1],[https://github.com/justemax/gpu_blas/issues],[],[https://github.com/justemax/gpu_blas/issues])
AM_INIT_AUTOMAKE([-Wall subdir-objects])


AC_PROG_CXX
AC_CONFIG_FILS([Makefile])
AC_OUTPUT

#init Makefile
LT_INIT
AC_CINFIG_MACRO_DIRS([m4])
AC_ENABLE_SHARED
AC_ENABLE_STATIC



AC_ARG_ENABLE([cublas],
	      [AC_HELP_STRING([--enable-cublas],
			      [Enable cublas, for NVIDIA gpu])]
	      [enable_cublas=yes],
	      [enable_cublas=no])

AC_ARG_ENABLE([rocblas],
	      [AC_HELP_STRING([--enable-rocblas],
			      [Enable rocblas, for AMD or NVIDIA gpu])]
	      [enable_rocblas=yes],
	      [enable_rocblas=no])

AC_ARG_ENABLE([ompblas],
	      [AC_HELP_STRING([--enable-ompblas],
			      [Enable omp blas for all gpu who support openMP offload (no optimisation)])]
	      [enable_ompblas=yes],
	      [enable_ompblas=no])
AS_IF([ test "x$enable_cublas" = "xyes" -ne "x$enable_rocblas" = "xyes" -ne "x$enable_ompblas" = "xyes" ],[], [
       AC_OUTPUT
       echo \
       "Can't enable multiple blas, choose one"
       exit 1
])


#by default enable omp
AS_IF([ test "x$enable_cublas" = "xyes" -o "x$enable_rocblas" = "xyes" -o "x$enable_ompblas" = "xyes" ],[], [
	enable_ompblas=yes
	])



AS_IF([ test "x$enable_cublas" = "xyes"],[
       AC_DEFINE([HAVE_CUBLAS], [1], [Enable cublas])
       case $CXX in
	       *nvcc*)
			CXXFLAGS="-lcublas"
		;;
		*)
			echo "You don't use nvcc fgor cublas, don't forget to set the CXX flags"
	esac
])

AS_IF([ test "x$enable_rocblas" = "xyes"],[
       AC_DEFINE([HAVE_ROCBLAS], [1], [Enable rocblas])
       case $CXX in
	       *hipcc*)
			CXXFLAGS="-lrocblas"
		;;
	       *clang*)
			CXXFLAGS="-lrocblas"
		;;
		*)
			echo "You don't use hipcc or clang for rocblas, don't forget to set the CXX flags"
	esac
])

AS_IF([ test "x$enable_ompblas" = "xyes"],[
       AC_DEFINE([HAVE_OMPBLAS], [1], [Enable ompblas])
       case $CXX in
		*g++*)
			CFLAGS="$CFLAGS -fopenmp -foffload=-lm"
			;;
		*nvcc*)
			CFLAGS="$CFLAGS -mp=gpu,noautopar"
			;;
		*clang++*)
			CFLAGS="$CFLAGS -fopenmp "
			;;


		*)
			echo "Warning : compiler not recognized for OpenMP. Make sure to add necessary offload flags manually."
	esac
])



AM_CONDITIONAL([HAVE_CUBLAS], [test "x$enable_cublas"])
AM_CONDITIONAL([HAVE_ROCBLAS], [test "x$enable_rocblas"])
AM_CONDITIONAL([HAVE_OMPBLAS], [test "x$enable_ompblas"])


echo\
"----------------------------------------------
${PACKAGE_NAME} Version ${PACKAGE_VERSION}

Prefix: ${Prefix}

CXX...............: ${CXX}
CUBLAS............: ${enable_cublas}
ROCBLAS...........: ${enable_rocblas}
OMPBLAS...........: ${enable_ompblas}

----------------------------------------------"




