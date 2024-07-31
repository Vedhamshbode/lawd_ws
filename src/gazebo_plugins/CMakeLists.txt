cmake_minimum_required(VERSION 3.8)
project(gazebo_plugins)

find_package(gazebo REQUIRED)    #for gazebo plugins

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(gazebo REQUIRED)
find_package(gazebo_ros REQUIRED)


include_directories(
  ${GAZEBO_INCLUDE_DIRS}
  ${rclcpp_INCLUDE_DIRS}
  ${gazebo_ros_INCLUDE_DIRS}
  )            
link_directories(${GAZEBO_LIBRARY_DIRS})         
add_compile_options(${GAZEBO_CXX_FLAGS})     
# list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

include_directories(
  include
)


add_library(lift_drag_plugin SHARED src/lift_drag_plugin.cc)
ament_target_dependencies(joint_controller_plugin rclcpp)
target_link_libraries(lift_drag_plugin ${GAZEBO_LIBRARIES})


# Install targets
install(TARGETS lift_drag_plugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Install include directories
install(DIRECTORY include/
  DESTINATION include/
)

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   set(ament_cmake_copyright_FOUND TRUE)
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

ament_package()
