#include <iostream>
#include <string>
// ROS
#include <ros/ros.h>
//#include <std_msgs/String.h>
// THIS PACKAGE'S MESSAGES
#include <generic_package/GenericMessage.h>



/**
 * Callback function for every received message on subscribed topic
 */
void generic_callback(const generic_package::GenericMessageConstPtr& msg_pointer)
{
  std::cout << "message says: " << msg_pointer->message_content << std::endl;
}


int main(int argc, char** argv)
{
  /// Initialize node
  ros::init(argc, argv, "generic_client");
  ROS_INFO("generic_client initialized");

  /// Setup message subscriber
  ros::NodeHandle nh;
  std::string generic_topic = nh.resolveName("generic_topic");
  ros::Subscriber generic_subscriber = nh.subscribe(generic_topic, 1, 
                                                    generic_callback);

  ros::spin();

  /// Tidy up
  ROS_INFO("generic_client exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

