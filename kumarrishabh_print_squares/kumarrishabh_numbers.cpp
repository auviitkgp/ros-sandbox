#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  //initializing the node number
  ros::init(argc, argv, "number");

  ros::NodeHandle n;

  // advertising on the topic_numbers
  ros::Publisher topic_numbers_pub = n.advertise<std_msgs::Int64>("topic_numbers", 1000);

  ros::Rate loop_rate(1);

  long int count = 0;

  while (ros::ok())
  {
    std_msgs::Int64 msg;

    msg.data = count;

    ROS_INFO("%ld", msg.data);

    // publishing on the topic_numbers
    topic_numbers_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    ++count;
  }


  return 0;
}
