#include <string>
// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
// THIS PACKAGE'S SERVICES
#include "generic_package/GenericService.h"

bool genericServiceCallback(generic_package::GenericService::Request &request,
                            generic_package::GenericService::Response &response)
{
  ROS_INFO("GenericService server got request: \"%s\"",
           request.request_string.c_str());
  response.response_string = "EHLO back from server!";
  return true;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "generic_server");
  ROS_INFO("generic_server initialized");


  ros::NodeHandle nh;
  ros::ServiceServer server = nh.advertiseService("generic_service_server", 
                                                  genericServiceCallback);


  ros::spin();

  /// Tidy up
  ROS_INFO("generic_server exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

