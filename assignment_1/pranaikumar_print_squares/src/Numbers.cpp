
#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include "std_msgs/String.h"
#include <sstream>
#include<stdlib.h>
#include<time.h>
int main(int argc, char **argv)
{
  //initializing the node called number
  ros::init(argc, argv, "number");

  ros::NodeHandle n1;

  // advertising
  ros::Publisher topic_numbers_pub = n1.advertise<std_msgs::Int64>("topic_numbers", 1000);

  ros::Rate loop_rate(1);
  while (ros::ok())
  {
    std_msgs::Int64 msg;
    srand(time(NULL));
    msg.data = rand() %1000;

    ROS_INFO("%ld", msg.data);

    // publishing on the topic_numbers
    topic_numbers_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    
  }


  return 0;
}
