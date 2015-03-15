#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <sstream>

int main(int argc, char **argv)
{
ros::init(argc, argv, "numbers");
 ros::NodeHandle n;
  ros::Publisher topic_numbers_pub = n.advertise<std_msgs::Int64>("topics_numbers", 100);
ros::Rate loop_rate(1);
int count = 0;
  while (ros::ok())
  {
 std_msgs::Int64 msg;
msg.data = count+1;
 ROS_INFO("%d", msg.data);
 topic_numbers_pub.publish(msg); 
 ;
 loop_rate.sleep();
 ++count;
    }
     return 0;
    
}
