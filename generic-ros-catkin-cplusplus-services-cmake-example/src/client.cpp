#include <string>
// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
// THIS PACKAGE'S SERVICES
#include "generic_package/GenericService.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "generic_client");
  ROS_INFO("generic_client initialized");


  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<generic_package::GenericService>("generic_service_server");

  generic_package::GenericService request_response_pair;
  request_response_pair.request.request_string = "HELO from client!";

  ros::service::waitForService("generic_service_server", 10000);
  if (not client.call(request_response_pair)) {
    ROS_ERROR("GenericService server did not respond within 10 seconds");
    return EXIT_FAILURE;
  }
  ROS_INFO("Got response from GenericService server: \"%s\"",
           request_response_pair.response.response_string.c_str());


  /// Tidy up
  ROS_INFO("generic_node exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

