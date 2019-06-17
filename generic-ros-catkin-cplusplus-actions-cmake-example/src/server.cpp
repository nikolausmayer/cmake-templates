#include <string>
// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <actionlib/server/simple_action_server.h>
// THIS PACKAGE'S ACTIONS
#include "generic_package/GenericActionAction.h"  /// Note the extra "Action"!

void genericActionCallback(
  const generic_package::GenericActionGoalConstPtr& goal_ptr,
  actionlib::SimpleActionServer<generic_package::GenericActionAction>* action_server_ptr)
{
  ROS_INFO("GenericAction server got request: \"%s\"",
           goal_ptr->generic_action_goal_parameter.c_str());

  if (goal_ptr->generic_action_goal_parameter == "HELO from client!") {
    generic_package::GenericActionResult result;
    result.generic_action_result_parameter = "EHLO from server!";
    action_server_ptr->setSucceeded(result);
  } else {
    generic_package::GenericActionResult result;
    result.generic_action_result_parameter = "Oh no";
    action_server_ptr->setAborted(result);
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "generic_server");
  ROS_INFO("generic_server initialized");


  ros::NodeHandle nh;


  actionlib::SimpleActionServer<generic_package::GenericActionAction> action_server(
      nh,
      "generic_action",
      boost::bind(&genericActionCallback, _1, &action_server),
      false);
  action_server.start();

  ros::spin();

  /// Tidy up
  ROS_INFO("generic_server exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

