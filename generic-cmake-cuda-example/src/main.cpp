/**
 * Author: Nikolaus Mayer, 2014  (mayern@informatik.uni-freiburg.de)
 * Generic CUDA+cmake example
 */

// System/STL
#include <iostream>
#include <cuda_runtime.h>
// Local files
#include "kernels.h"


/**
 * MAIN
 */
int main( int argc, char** argv ) {
  
  const size_t DATA_SIZE = 16;

  /// Data on host
  float HOST_DATA[DATA_SIZE];
  /// Data on device
  float* DEVICE_DATA;
  /// Allocate GPU memory for device data
  cudaMalloc( (void**)&DEVICE_DATA,
              DATA_SIZE * sizeof(float) );


  /// Initialize host data
  for ( size_t i = 0; i < DATA_SIZE; ++i )
    HOST_DATA[i] = (float)i;

  /// (Debug output)
  std::cout << "Data before CUDA computation:";
  for ( size_t i = 0; i < DATA_SIZE; ++i )
    std::cout << " " << HOST_DATA[i];
  std::cout << std::endl;

  /// Copy host data to device memory
  cudaMemcpy( DEVICE_DATA, 
              HOST_DATA, 
              DATA_SIZE * sizeof(float), 
              cudaMemcpyHostToDevice );
  
  /// Start CUDA computation (double every data entry)
  generic_CUDA_function( DEVICE_DATA, DATA_SIZE );

  /// Copy back results from device into host memory
  cudaMemcpy( HOST_DATA, 
              DEVICE_DATA, 
              DATA_SIZE * sizeof(float), 
              cudaMemcpyDeviceToHost );

  /// (Debug output)
  std::cout << "Data after CUDA computation:";
  for ( size_t i = 0; i < DATA_SIZE; ++i )
    std::cout << " " << HOST_DATA[i];
  std::cout << std::endl;
   

  /// Tidy up
  cudaFree( DEVICE_DATA );

  /// Bye!
  return 0;
}

