#include <string>
// ROS
#include <ros/ros.h>
#include <ros/package.h>  // finds package paths

int main(int argc, char** argv)
{
  ros::init(argc, argv, "generic_node");
  ROS_INFO("generic_node initialized");

  std::string pkg_path{ros::package::getPath("generic_package")};
  ROS_INFO("The package \"generic_node\" is living at %s", pkg_path.c_str());

  {
    int tmp{0};
    if (ros::param::get("~generic_parameter", tmp)) {
      ROS_INFO("\"generic_parameter\" is %d", tmp);
    }
  }

  /// Tidy up
  ROS_INFO("generic_node exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

