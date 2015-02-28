cmake_minimum_required( VERSION 2.8 )

## Required software
find_package( CUDA REQUIRED )

## Sources and headers
include_directories( ${CUDA_INCLUDE_DIRS}
                     ${CMAKE_CURRENT_SOURCE_DIR}
                   )

## Split the source into a GPU part (compiled by nvcc) and a
## CPU part (compiled by e.g. gcc).
## (This may not always be necessary.)
file( GLOB CPU_SOURCES *.cc *.cpp )
file( GLOB GPU_SOURCES *.cu )

## C++ compiler options
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )

## NVCC (CUDA compiler) options
set( CUDA_NVCC_FLAGS -gencode=arch=compute_30,code=sm_30
     CACHE STRING "NVidia CUDA compiler flags"
     FORCE
   )
set( CUDA_NVCC_FLAGS_DEBUG -g -G -O0 )
set( CUDA_NVCC_FLAGS_RELEASE -O3 -lineinfo )

## Source file containing the "main" function
set( MAIN_SOURCES main.cpp )
## Specify a name for the generated executable file
set( MAIN_EXE_NAME generic_executable )

## Link against the NVTX library (optional)
find_library( NVTX_LIBRARY nvToolsExt PATHS ENV LD_LIBRARY_PATH )


## 1. Compile...
cuda_add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCES}
                                      ${CPU_SOURCES}
                                      ${GPU_SOURCES}
                   )
## 2. Link...
target_link_libraries( ${MAIN_EXE_NAME} ${NVTX_LIBRARY}
                                        ${CUDA_CUDART_LIBRARY}
                     )
## 3. Install...
install( TARGETS ${MAIN_EXE_NAME}
         RUNTIME DESTINATION bin )

