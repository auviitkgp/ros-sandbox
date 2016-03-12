#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
  
   int a=0;
  
void topic_numbersCallback(const std_msgs::String::ConstPtr& msg)
{
   a =atoi(msg->data.c_str());
   a=a*a;
   
}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "squares_shubhamjena");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, topic_numbersCallback);
  
ros::Publisher sq_num_pub = n.advertise<std_msgs::String>("topic_squares",1000);
 

ros::Rate loop_rate(1);
while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss<<a;
    msg.data = ss.str();
    sq_num_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
   
  }


  ros::spin();

  return 0;
}


