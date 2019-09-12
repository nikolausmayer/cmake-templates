cmake_minimum_required(VERSION 2.8.3)
project(generic_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslib
  std_msgs
  dynamic_reconfigure
)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -Wpedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

generate_dynamic_reconfigure_options(
  cfg/Parameters.cfg
)

catkin_package(
  CATKIN_DEPENDS 
  roscpp 
  roslib 
  dynamic_reconfigure
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(
  generic_node 
  src/main.cpp
)


target_link_libraries(
  generic_node
  ${catkin_LIBRARIES}
)

add_dependencies(
  generic_node 
  ${PROJECT_NAME}_gencfg
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

install(
  TARGETS generic_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

