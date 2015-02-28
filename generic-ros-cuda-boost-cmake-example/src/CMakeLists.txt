cmake_minimum_required( VERSION 2.8 )

## Required software
find_package( CUDA REQUIRED )
set( Boost_USE_MULTITHREADED NO )
find_package( Boost REQUIRED COMPONENTS thread system )
#find_package( <PACKAGE_NAME> REQUIRED )

include_directories( ##Source directories of required software go here
                     ${CUDA_INCLUDE_DIRS}
                     ${Boost_INCLUDE_DIRS}
                     ${CMAKE_CURRENT_SOURCE_DIR}
                   )

## Compile all .cc and .cpp files using gcc
file( GLOB CPU_SOURCES *.cc *.cpp )
## Compile all .cu files with nvcc first
file( GLOB GPU_SOURCES *.cu )

## Compile-time definitions
add_definitions( -DHAVE_EIGEN )

## Enable compiler warnings 
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )

## CUDA options
set( CUDA_NVCC_FLAGS -gencode=arch=compute_30,code=sm_30
     CACHE STRING "NVidia CUDA compiler flags"
     FORCE
   )
set( CUDA_NVCC_FLAGS_DEBUG -g -G -O0 )
set( CUDA_NVCC_FLAGS_RELEASE -O3 -lineinfo )


## Where's main()?
set( MAIN_SOURCES main.cpp )

## What executable are we building anyway?
set( MAIN_EXECUTABLE_NAME "generic_executable" )

## Add CUDA's NVTX library
find_library( NVTX_LIBRARY nvToolsExt PATHS ENV LD_LIBRARY_PATH )


## CUDA-compile
cuda_add_executable( ${MAIN_EXECUTABLE_NAME} ${MAIN_SOURCES}
                                             ${CPU_SOURCES}
                                             ${GPU_SOURCES}
                   )
## Non-CUDA compile
rosbuild_add_executable( ${MAIN_EXECUTABLE_NAME} ${MAIN_SOURCES}
                                                 ${CPU_SOURCES}
                       )

## Link against stuff
target_link_libraries( ${MAIN_EXECUTABLE_NAME} ${NVTX_LIBRARY}
                                               ${CUDA_CUDART_LIBRARY}
                       ##Libraries of required software go here
                     )
                       
## Link against Boost library components
rosbuild_link_boost( ${MAIN_EXECUTABLE_NAME} thread system )

## Install compiled data to ./bin
install( TARGETS ${MAIN_EXECUTABLE_NAME}
         RUNTIME DESTINATION bin )

