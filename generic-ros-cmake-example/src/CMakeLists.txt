cmake_minimum_required( VERSION 2.8 )

## Required software
#find_package( <PACKAGE_NAME> REQUIRED )

include_directories( ##Source directories of required software go here
                     ${CMAKE_CURRENT_SOURCE_DIR}
                   )

## Compile all .cc and .cpp files using gcc
file( GLOB SOURCES *.cc *.cpp )

## Compile-time definitions
add_definitions( -DHAVE_EIGEN )

## Enable compiler warnings 
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )


## Where's main()?
set( MAIN_SOURCES main.cpp )

## What executable are we building anyway?
set( MAIN_EXECUTABLE_NAME "generic_executable" )


## Compile
rosbuild_add_executable( ${MAIN_EXECUTABLE_NAME} ${MAIN_SOURCES}
                                                 ${CPU_SOURCES}
                       )

## Link against stuff
target_link_libraries( ${MAIN_EXECUTABLE_NAME}
                       ##Libraries of required software go here
                     )
                       
## Install compiled data to ./bin
install( TARGETS ${MAIN_EXECUTABLE_NAME}
         RUNTIME DESTINATION bin )

