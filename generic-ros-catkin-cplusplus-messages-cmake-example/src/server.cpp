#include <chrono>
#include <string>
#include <thread>
// ROS
#include <ros/ros.h>
// THIS PACKAGE'S MESSAGES
#include <generic_package/GenericMessage.h>


typedef generic_package::GenericMessage MSG;


int main(int argc, char** argv)
{
  /// Initialize node
  ros::init(argc, argv, "generic_server");
  ROS_INFO("generic_server initialized");

  /// Setup message publisher
  ros::NodeHandle nh;
  ros::Publisher generic_publisher = nh.advertise<MSG>("generic_topic", 1);

  while (ros::ok()) {
    /// Send a message
    MSG message;
    message.message_content = "GENERIC HELLO!";
    message.header.stamp = ros::Time::now();
    generic_publisher.publish(message);

    /// Spin once to publish
    ros::spinOnce();

    /// Wait one second
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  /// Tidy up
  ROS_INFO("generic_server exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

