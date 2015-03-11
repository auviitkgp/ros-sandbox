cmake_minimum_required(VERSION 2.8.3)
project(aranyadan_print_squares)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg sensor_msgs cv_bridge image_transport)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(numbers_aranyadan src/numbers_aranyadan.cpp)
target_link_libraries(numbers_aranyadan ${catkin_LIBRARIES})
add_dependencies(numbers_aranyadan aranyadan_print_squares_generate_messages_cpp)

add_executable(squares_aranyadan src/squares_aranyadan.cpp)
target_link_libraries(squares_aranyadan ${catkin_LIBRARIES})
add_dependencies(squares_aranyadan aranyadan_print_squares_generate_messages_cpp)

add_executable(print_aranyadan src/print_aranyadan.cpp)
target_link_libraries(print_aranyadan ${catkin_LIBRARIES})
add_dependencies(print_aranyadan aranyadan_print_squares_generate_messages_cpp)
