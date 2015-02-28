
/// System/STL
#include <iostream>
#include <string>
/// ROS
#include <ros/ros.h>
#include <sensor_msgs/CameraInfo.h>


/**
 * Callback for sensor_msgs::CameraInfo message topics, see
 * http://docs.ros.org/api/sensor_msgs/html/msg/CameraInfo.html
 *
 * @param info_message ROS message with camera info
 */
void MyCallbackFunction( const sensor_msgs::CameraInfoConstPtr info_message )
{
  std::cout << "Got a callback! Its timestamp says '"
            << info_message->header.stamp
            << "'"
            << std::endl;
}



int main( int argc, char** argv ) {
  std::cout << "Your generic ROS node says 'Hello World'! :)"
            << std::endl;


  /// Initialize ROS
  ros::init( argc, argv, "GenericRosProjectNode" );

  /// Subscribe to a ROS topic
  ros::NodeHandle nh_;
  ros::Subscriber subscriber;
  std::string rostopic_name = "camera_info";
  std::cout << "Subscribing to topic '" << rostopic_name << "' ..." 
            << std::endl;
  std::string rostopic_resolved_channel_name = nh_.resolveName( rostopic_name );
  subscriber = nh_.subscribe( rostopic_resolved_channel_name,
                              1,
                              MyCallbackFunction
                            );
  

  /// Keep listening for messages until something happens (e.g. ctrl-c)
  ros::spin();

  /// Tidy up
  ros::shutdown();

  /// Bye!
  return 0;
}


