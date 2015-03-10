/*
**************************************************
This is the node named numbers.
It will publish on the topic "topic_numbers"
**************************************************
*/
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace std;
using namespace ros;
using namespace std_msgs;

int main(int argc, char **argv)
{
 
 init(argc, argv, "numbers");

 NodeHandle n;

 Publisher topic_numbers_pub = n.advertise<String>("topic_numbers", 1000);//the advertise function publishes stuff of the data type within <>

 Rate loop_rate(1);    //it defines the frequency of publishing
 int count = 1;
 while(ok())
   {
	String msg;
	stringstream ss;
	ss << count ;
	msg.data = ss.str();
	topic_numbers_pub.publish(msg);
	spinOnce;
	loop_rate.sleep(); //the loop halts here for the defined time
	++count;
   }

return 0;

}
