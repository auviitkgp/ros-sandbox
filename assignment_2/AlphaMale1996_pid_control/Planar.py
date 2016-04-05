#!/usr/bin/env python

PKG = 'seabotix'

from pid import PID
import roslib; roslib.load_manifest(PKG)
import rospy
from kraken_msgs.msg import thrusterData6Thruster
from kraken_msgs.msg import thrusterData4Thruster
from kraken_msgs.msg import positionData
from resources import topicHeader
import numpy as np
from math import *
from std_msgs.msg import Float64
from geometry_msgs.msg import Pose
POS = PID()

#Defining global variables
Curr_x    = 0.0
Goal_x    = 0.0
Base_x    = 0.0  
prevError = 0.0
errorI    = 0.0
errorP    = 0.0
errorD    = 0.0
out       = 0.0 
FIRST_ITERATION = True


def posCB(dataIn):
	global Curr_x
	global Base_x
	global prevError
	global errorD
	global errorI
	global errorP
	global FIRST_ITERATION
	global out

	if FIRST_ITERATION:
		Base_x = dataIn.position.x
		FIRST_ITERATION = False
	
	Curr_x = dataIn.position.x
	print 'Position ',Curr_x,' : ',Base_x
	prevError = errorP
	print 'Error ',errorP
	errorP = Goal_x - Curr_x
	errorI = errorP + prevError
	errorD = errorP - prevError
	out = POS.k[0]*errorP + POS.k[1]*errorD + POS.k[2]*errorI

thruster6Data = thrusterData6Thruster()
thruster4Data = thrusterData4Thruster()

def runPLANAR():
	
	global Goal_x
	

	print 'Enter the goal position : '
	Goal_x = float(raw_input())
	rospy.init_node('Control', anonymous=True)	
	sub = rospy.Subscriber("/g500/pose", Pose, posCB)
	pub4 = rospy.Publisher(topicHeader.CONTROL_PID_THRUSTER4, thrusterData4Thruster, queue_size = 2)
	pub6 = rospy.Publisher(topicHeader.CONTROL_PID_THRUSTER6, thrusterData6Thruster, queue_size = 2)
	puberror = rospy.Publisher('ErrorPose', Float64, queue_size = 2)
	r = rospy.Rate(10)

	while not rospy.is_shutdown():

		thruster6Data.data[0] = 0.0
		thruster6Data.data[1] = 0.0
		thruster6Data.data[2] = 0.0
		thruster6Data.data[3] = 0.0

		thruster6Data.data[4] = out
		thruster6Data.data[5] = out

		thruster4Data.data[0] = thruster6Data.data[0]
		thruster4Data.data[1] = thruster6Data.data[1]
		thruster4Data.data[2] = thruster6Data.data[4]
		thruster4Data.data[3] = thruster6Data.data[5]

		pub4.publish(thruster4Data)
		pub6.publish(thruster6Data)
		puberror.publish(errorP)		

		r.sleep()


