cmake_minimum_required(VERSION 2.8.3)
project(shubhamjena_print_squares)


find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Generate added messages and services with any dependencies listed here
 generate_messages(DEPENDENCIES std_msgs)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(numbers_shubhamjena src/numbers_shubhamjena.cpp)
target_link_libraries(numbers_shubhamjena ${catkin_LIBRARIES})
add_dependencies(numbers_shubhamjena shubhamjena_print_squares_generate_messages_cpp)

add_executable(squares_shubhamjena src/squares_shubhamjena.cpp)
target_link_libraries(squares_shubhamjena ${catkin_LIBRARIES})
add_dependencies(squares_shubhamjena shubhamjena_print_squares_generate_messages_cpp)

add_executable(print_shubhamjena src/print_shubhamjena.cpp)
target_link_libraries(print_shubhamjena ${catkin_LIBRARIES})
add_dependencies(print_shubhamjena shubhamjena_print_squares_generate_messages_cpp)


