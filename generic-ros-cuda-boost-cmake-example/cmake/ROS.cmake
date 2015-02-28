cmake_minimum_required( VERSION 2.8 )
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
## Project name (you don't need this)
project( MyProject )


# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

## Tell cmake where to put compiled executables and libraries
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

## Tell cmake where to put stuff from ./src
add_subdirectory(${PROJECT_SOURCE_DIR}/src bin)

