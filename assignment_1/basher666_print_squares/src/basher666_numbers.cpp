#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc,char **argv)
{
  ros::init(argc,argv,"basher666_numbers"); //initializing the node basher666_numbers

  ros::NodeHandle n;

  ros::Publisher num_pub=n.advertise<std_msgs::Int64>("topic_numbers",1000); //setting the topic_numbers as the topic
  ros::Rate loop_rate(1); //setting loop_rate as 1 hz
  int count=1;
  while(ros::ok())
    {
      std_msgs::Int64 x;
      x.data=count;
      num_pub.publish(x); //publishing the data to the topic
      ROS_INFO("%ld sent to topic_numbers\n",x.data);
      ros::spinOnce();
      loop_rate.sleep();
      count++;
    }
  return 0;
}
