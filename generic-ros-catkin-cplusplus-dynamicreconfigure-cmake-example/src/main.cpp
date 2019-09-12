#include <string>
// ROS
#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
// THIS PACKAGE'S DYNAMIC-RECONFIGURE
#include <generic_package/ParametersConfig.h>


std::string string_enum_parameter;
std::string string_parameter;
float float_parameter;
int int_parameter;
bool bool_parameter;


/**
 * Dynamic-reconfigure callback
 */
void DynamicReconfigureCallback(generic_package::ParametersConfig& cfg,
                                uint32_t level)
{
  (void) level;

  if (cfg.generic_custom_type_parameter != string_enum_parameter) {
    string_enum_parameter = cfg.generic_custom_type_parameter;
    ROS_INFO("Set 'string_enum_parameter' to '%s'", string_enum_parameter.c_str());
    if (string_enum_parameter == generic_package::Parameters_choice_A_type) {
      ROS_INFO("(this is 'A')");
    } else if (string_enum_parameter == generic_package::Parameters_choice_B_type) {
      ROS_INFO("(this is 'B')");
    }
  }

  if (cfg.generic_string_parameter != string_parameter) {
    string_parameter = cfg.generic_string_parameter;
    ROS_INFO("Set 'string_parameter' to '%s'", string_parameter.c_str());
  }

  if (cfg.generic_float_parameter != float_parameter) {
    float_parameter = cfg.generic_float_parameter;
    ROS_INFO("Set 'float_parameter' to %f", float_parameter);
  }

  if (cfg.generic_int_parameter != int_parameter) {
    int_parameter = cfg.generic_int_parameter;
    ROS_INFO("Set 'int_parameter' to %d", int_parameter);
  }

  if (cfg.generic_bool_parameter != bool_parameter) {
    bool_parameter = cfg.generic_bool_parameter;
    ROS_INFO("Set 'bool_parameter' to %s", (bool_parameter?"True":"False"));
  }
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "generic_node");
  ROS_INFO("generic_node initialized");

  ros::NodeHandle nh;

  dynamic_reconfigure::Server<generic_package::ParametersConfig> dynamic_reconfigure_server;
  dynamic_reconfigure_server.setCallback(boost::bind(&DynamicReconfigureCallback, _1, _2));

  ros::spin();

  /// Tidy up
  ROS_INFO("generic_node exiting...");
  ros::shutdown();

  /// Bye!
  return EXIT_SUCCESS;
}

