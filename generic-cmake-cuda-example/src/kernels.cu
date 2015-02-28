/**
 * Author: Nikolaus Mayer, 2014  (mayern@informatik.uni-freiburg.de)
 * CUDA kernels
 */

#include <cmath>  // std::ceil

/**
 * Kernel
 */
__global__ void generic_CUDA_function__kernel( float* DATA,
                                               size_t data_size
                                             )
{
  const size_t x = blockIdx.x * blockDim.x + threadIdx.x;
  if ( x >= data_size )
    return;

  DATA[x] *= 2.0f;  
}


/**
 * Function
 */
void generic_CUDA_function( float* DATA,
                            size_t data_size
                          )
{
  /// CUDA kernel parameters
  const dim3 block(16, 1, 1);
  const dim3 grid(std::ceil(data_size/(float)block.x), 1, 1);

  /// Call kernel
  generic_CUDA_function__kernel<<<grid,block>>>( DATA, data_size );
}

