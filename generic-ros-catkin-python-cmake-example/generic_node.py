#!/usr/bin/env python
import rospy


if __name__ == "__main__":        
  rospy.init_node('generic_node', anonymous=True)

  rospy.loginfo("Hello :)")

