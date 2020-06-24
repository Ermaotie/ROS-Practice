cmake_minimum_required(VERSION 3.0.2)
project(action_learning)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  actionlib_msgs
  actionlib
)


find_package(Boost REQUIRED COMPONENTS system)



add_action_files(
  FILES
  demo.action
)


generate_messages(
  DEPENDENCIES
  actionlib_msgs
  std_msgs
)


catkin_package(
 LIBRARIES action_learning
 CATKIN_DEPENDS roscpp std_msgs actionlib actionlib_msgs
 DEPENDS Boost
)


include_directories(
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)


add_executable(action_server src/action_server.cpp)
add_dependencies(action_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(action_server
  ${catkin_LIBRARIES}
)

add_executable(action_client src/action_client.cpp)
add_dependencies(action_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(action_client
  ${catkin_LIBRARIES}
)
