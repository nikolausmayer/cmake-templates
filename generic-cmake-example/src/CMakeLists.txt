cmake_minimum_required( VERSION 2.8 )

## Required software
#find_package( <<<name>>> REQUIRED )

## Sources and headers
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

## Find all source files to be compiled into object files
file( GLOB SOURCES *.cc *.cpp )

## C++ compiler options
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )

## Source file containing the "main" function
set( MAIN_SOURCES main.cpp )
## Specify a name for the generated executable file
set( MAIN_EXE_NAME generic_executable )


## 1. Compile...
add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCES}
                                 ${SOURCES}
              )

## 2. Link...
target_link_libraries( ${MAIN_EXE_NAME} )

## 3. Install...
install( TARGETS ${MAIN_EXE_NAME}
         RUNTIME DESTINATION bin )

