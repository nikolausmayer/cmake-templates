#!/usr/bin/env python
import rospy


if __name__ == "__main__":        
  rospy.init_node('generic_node', anonymous=True)

  if rospy.has_param('~generic_parameter'):
    rospy.loginfo("'generic_parameter' is %s", 
                  rospy.get_param('~generic_parameter'))

  rospy.loginfo("Hello :)")

