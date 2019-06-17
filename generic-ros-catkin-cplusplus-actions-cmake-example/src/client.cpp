#include <string>
// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <actionlib/client/simple_action_client.h>
// THIS PACKAGE'S ACTIONS
#include "generic_package/GenericActionAction.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "generic_client");
  ROS_INFO("generic_client initialized");


  ros::NodeHandle nh;
  actionlib::SimpleActionClient<generic_package::GenericActionAction> action_client(
      "generic_action",
      true);
  ROS_INFO("generic_client waiting for generic_server to come up...");
  action_client.waitForServer();
  ROS_INFO("generic_client found generic_server");

  generic_package::GenericActionGoal goal;
  goal.generic_action_goal_parameter = "HELO from client!";
  action_client.sendGoal(goal);

  bool ok = action_client.waitForResult(ros::Duration(5.0));
  if (not ok) {
    ROS_FATAL("GenericAction did not succeed within 5 seconds");
  }

  generic_package::GenericActionResultConstPtr result_ptr = action_client.getResult();
  ROS_INFO("generic_server responds \"%s\"",
           result_ptr->generic_action_result_parameter.c_str());

  /// Tidy up
  ROS_INFO("generic_node exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

