#include <ros/ros.h>
#include <iostream>
#include "std_msgs/String.h"
#include "arm_lib/release_catch_cmd.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "in_catch_release_publisher");

  ros::NodeHandle n;
  ros::Publisher p = n.advertise<arm_lib::release_catch_cmd>("release_catch_pub", 1000);

  arm_lib::release_catch_cmd msg;
  
   std::string release_catch_cmd;
   
   while (ros::ok())
  {
    std::cout << "Do you want to relese or catch the gripper: ";
    std::getline(std::cin, release_catch_cmd);


    msg.release_catch_cmd = release_catch_cmd;
    ROS_INFO("%s", msg.release_catch_cmd);
    p.publish(msg);

    ros::spinOnce();
  }

  return 0;
}	