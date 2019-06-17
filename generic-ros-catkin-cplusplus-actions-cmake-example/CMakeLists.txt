cmake_minimum_required(VERSION 2.8.3)
project(generic_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslib
  std_msgs
  actionlib
  actionlib_msgs
  message_generation
)

find_package(Boost REQUIRED COMPONENTS system)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -Wpedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_action_files(
  FILES
  GenericAction.action
)

generate_messages(
  DEPENDENCIES
  std_msgs
  actionlib_msgs
)

catkin_package(
  CATKIN_DEPENDS 
  roscpp 
  roslib 
  actionlib
  actionlib_msgs
  message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
)

add_executable(
  generic_server 
  src/server.cpp
)
add_executable(
  generic_client 
  src/client.cpp
)

add_dependencies(
  generic_server
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)
add_dependencies(
  generic_client
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(
  generic_server
  ${catkin_LIBRARIES}
)
target_link_libraries(
  generic_client
  ${catkin_LIBRARIES}
)

install(
  TARGETS generic_server generic_client
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(
  DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch                   
)   

