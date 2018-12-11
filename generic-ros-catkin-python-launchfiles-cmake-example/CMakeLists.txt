cmake_minimum_required(VERSION 2.8.3)
project(generic_package)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roslib
)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS 
  rospy
  roslib 
)

install(
  PROGRAMS generic_node.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch                   
)   

