cmake_minimum_required(VERSION 2.8.3)
project(lovishpuri_print_squares)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(numbers_lovishpuri src/numbers_lovishpuri.cpp)
target_link_libraries(numbers_lovishpuri ${catkin_LIBRARIES})
add_dependencies(numbers_lovishpuri lovishpuri_print_squares_generate_messages_cpp)

add_executable(squares_lovishpuri src/squares_lovishpuri.cpp)
target_link_libraries(squares_lovishpuri ${catkin_LIBRARIES})
add_dependencies(squares_lovishpuri lovishpuri_print_squares_generate_messages_cpp)

add_executable(print_lovishpuri src/print_lovishpuri.cpp)
target_link_libraries(print_lovishpuri ${catkin_LIBRARIES})
add_dependencies(print_lovishpuri lovishpuri_print_squares_generate_messages_cpp)
