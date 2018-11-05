cmake_minimum_required(VERSION 2.8.3)
project(generic_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslib
  std_msgs
)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -Wpedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

catkin_package(
  CATKIN_DEPENDS 
  roscpp 
  roslib 
  std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(generic_node src/main.cpp)

target_link_libraries(
  generic_node
  ${catkin_LIBRARIES}
)

install(
  TARGETS generic_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

