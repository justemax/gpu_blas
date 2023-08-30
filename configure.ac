AC_PREREQ([2.69])

AC_INIT([gpublas],[0.0.1],[https://github.com/justemax/gpu_blas/issues])
AM_INIT_AUTOMAKE([-Wall subdir-objects])
AM_PROG_AR


AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP

#init Makefile
LT_INIT
AC_PROG_LIBTOOL
AC_CONFIG_MACRO_DIRS([m4])
AC_ENABLE_SHARED
AC_ENABLE_STATIC


#CXXFLAGS="-Iinclude ${CXXFLAGS}"

AC_CHECK_LIB([c], [exit], ,AC_MSG_ERROR([C lib not found]))

AC_ARG_WITH([cublas],
	      [AC_HELP_STRING([--with-cublas],
			      ["Enable cublas, for NVIDIA gpu"])],
	      [have_cublas=yes],
	      [have_cublas=no])

AC_ARG_WITH([rocblas],
	      [AC_HELP_STRING([--with-rocblas],
			      ["Enable rocblas, for AMD or NVIDIA gpu"])],
	      [have_rocblas=yes],
	      [have_rocblas=no])

AC_ARG_WITH([ompblas],
	      [AC_HELP_STRING([--with-ompblas],
			      ["Enable omp blas for all gpu who support openMP offload (no optimisation)"])],
	      [have_ompblas=yes],
	      [have_ompblas=no])


#AS_IF([ test "x$have_cublas" = "xyes" -ne "x$have_rocblas" = "xyes" -ne "x$have_ompblas" = "xyes" ],[], [
#       AC_MSG_ERROR([Can't have multiple blas, choose one])
#])


#by default have omp
#AS_IF([ test "x$have_cublas" = "xyes" -o "x$have_rocblas" = "xyes" -o "x$have_ompblas" = "xyes" ],[], [
#	have_ompblas=yes
#])



AS_IF([ test "x$have_cublas" = "xyes"],[
       AC_DEFINE([HAVE_CUBLAS], [1], [Enable cublas])
       case $CXX in
	       *nvcc*)
			CXXFLAGS="-lcublas"
		;;
		*)
			AC_MSG_NOTICE([You don't use nvcc fgor cublas, don't forget to set the CXX flags])
		;;
	esac
])

AS_IF([ test "x$have_rocblas" = "xyes"],[
       AC_DEFINE([HAVE_ROCBLAS], [1], [Enable rocblas])
       case $CXX in
	       *hipcc*)
			CXXFLAGS="$CXXFLAGS -lrocblas"
		;;
	       *clang++*)
			CXXFLAGS="$CXXFLAGS -lrocblas"
		;;
		*)
			AC_MSG_NOTICE([You don't use hipcc or clang for rocblas, don't forget to set the CXX flags])
		;;
	esac
])

AS_IF([ test "x$have_ompblas" = "xyes"],[
       AC_DEFINE([HAVE_OMPBLAS], [1], [Enable ompblas])
       case $CXX in
		*g++*)
			CFLAGS="$CXXLAGS -fopenmp -foffload=-lm"
			;;
		*nvcc*)
			CFLAGS="$CXXLAGS -mp=gpu,noautopar"
			;;
		*clang++*)
			CFLAGS="$CXXLAGS -fopenmp "
			;;


		*)
			AC_MSG_NOTICE( "Warning : compiler not recognized for OpenMP. Make sure to add necessary offload flags manually.")
		;;
	esac
])



AM_CONDITIONAL([HAVE_CUBLAS], [test "x$have_cublas"])
AM_CONDITIONAL([HAVE_ROCBLAS], [test "x$have_rocblas"])
AM_CONDITIONAL([HAVE_OMPBLAS], [test "x$have_ompblas"])

AC_MSG_NOTICE([
----------------------------------------------
${PACKAGE_NAME} Version ${PACKAGE_VERSION}

Prefix: ${Prefix}

CXX...............: ${CXX}
CUBLAS............: ${have_cublas}
ROCBLAS...........: ${have_rocblas}
ompblas...........: ${have_ompblas}

----------------------------------------------
]
)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
