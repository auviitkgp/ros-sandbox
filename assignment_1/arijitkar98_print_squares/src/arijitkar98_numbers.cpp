#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "arijitkar98_numbers");

  ros::NodeHandle num;

  ros::Publisher num_pub = num.advertise<std_msgs::Int64>("topic_numbers", 1000);

  ros::Rate loop_rate(1);

  int i = 0;
  
  while (ros::ok())
  {
    std_msgs::Int64 msg;

    msg.data = ++i;

    num_pub.publish(msg);
    
    ros::spinOnce();

    loop_rate.sleep();
  }
  
  return 0;
}

