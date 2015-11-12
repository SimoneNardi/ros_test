cmake_minimum_required(VERSION 2.8.3)
project(ros_test)

ENABLE_LANGUAGE(CXX)

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include include/${PROJECT_NAME}/
  #LIBRARIES ${PROJECT_NAME}
  #DEPENDS
)

message(WARNING ${catkin_LIBRARIES})

include_directories(include/${PROJECT_NAME}/ ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

add_executable(ros_test_node src/ros_test_node.cpp)
target_link_libraries(ros_test_node ${catkin_LIBRARIES})
add_dependencies(ros_test_node ${PROJECT_NAME}_gencpp)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

## Mark executables and/or libraries for installation
install(TARGETS ros_test_node
   ARCHIVE DESTINATION "${CATKIN_PACKAGE_BIN_DESTINATION}" COMPONENT lib
   RUNTIME DESTINATION "${CATKIN_PACKAGE_BIN_DESTINATION}" COMPONENT bin
   LIBRARY DESTINATION "${CATKIN_PACKAGE_LIB_DESTINATION}" COMPONENT shlib
)