#include "ros/ros.h"
#include "std_msgs/Int64.h"

ros::Publisher sq_pub; //creating the publisher object globally for convenience
void numberscallback(const std_msgs::Int64::ConstPtr& num)
{
  ROS_INFO("heard %ld from topic_numbers \n",num->data);
  std_msgs::Int64 sq;
  sq.data=(num->data)*(num->data);

  if(ros::ok())    //publishing the square only once for each number from topic_numbers
    {
      sq_pub.publish(sq);
      ROS_INFO("sent %ld to topic_squares\n",sq.data);
      ros::spinOnce();
      //loop_rate.sleep();
    }
  
}
int main(int argc,char **argv)
{
  ros::init(argc,argv,"basher666_squares");
  ros::NodeHandle n;
  ros::NodeHandle n2;
  ros::Rate loop_rate(1);
  sq_pub=n2.advertise<std_msgs::Int64>("topic_squares",1000);  //selecting topic_squares as the topic to publish
  ros::Subscriber square=n.subscribe("topic_numbers",1000,numberscallback); //selecting topic_numbers as the topic to subscribe
  ros::spin();
  
  return 0;
}
