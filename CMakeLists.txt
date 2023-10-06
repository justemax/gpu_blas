cmake_minimum_required(VERSION 3.0)
project(gpu_blas CXX)

file(GLOB_RECURSE sources src/gpublas.cpp include/libgpublas.h)


option(WITH_ROCBLAS "with[out] rocblas")
if(WITH_ROCBLAS)
	file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/rocblas.cpp)
	set(HEADER_FILES ${CMAKE_SOURCE_DIR}/include/rocblas.hpp)
	include_directories(${CMAKE_SOURCE_DIR}/include)
	add_definitions(-DHAVE_ROCBLAS=1)
endif(WITH_ROCBLAS)

option(WITH_CUBLAS "with[out] cublas")
if(WITH_CUBLAS)
	file(GLOB_RECURSE sources src/cublas.cu include/cublas.hpp)
	add_definitions(-DHAVE_CUBLAS=1)
endif(WITH_CUBLAS)

option(WITH_OMP "with[out] omp")
if(WITH_OMP)
	file(GLOB_RECURSE sources src/ompblas.cpp include/ompblas.hpp)
endif(WITH_OMP)

add_library(${PROJECT_NAME} SHARED
	${sources}
	${HEADER_FILES})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/libgpublas.h)


MESSAGE(STATUS "source: ${sources}")

#Compiler options

if(WITH_ROCBLAS)
	if(CMAKE_CXX_COMPILER EQUAL "hipcc")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrocblas")
	elseif(CMAKE_CXX_COMPILER EQUAL "clang++")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrocblas")
	endif()
endif()


if(WITH_CUBLAS)
	if(CMAKE_CXX_COMPILER EQUAL "nvc++")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcublas")
	elseif(CMAKE_CXX_COMPILER EQUAL "clang++")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcublas")
	endif()
endif()

if(WITH_OMP)
	if(CMAKE_CXX_COMPILER EQUAL "g++")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -foffload=-lm")
	elseif(CMAKE_CXX_COMPILER EQUAL "nvcc")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mp=gpu,noautopar")
	elseif(CMAKE_CXX_COMPILER EQUAL "clang++")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
	endif()
endif()



