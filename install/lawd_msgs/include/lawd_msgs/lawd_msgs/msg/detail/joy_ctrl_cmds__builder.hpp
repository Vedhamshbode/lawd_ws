// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lawd_msgs:msg/JoyCtrlCmds.idl
// generated code does not contain a copyright notice

#ifndef LAWD_MSGS__MSG__DETAIL__JOY_CTRL_CMDS__BUILDER_HPP_
#define LAWD_MSGS__MSG__DETAIL__JOY_CTRL_CMDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lawd_msgs/msg/detail/joy_ctrl_cmds__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lawd_msgs
{

namespace msg
{

namespace builder
{

class Init_JoyCtrlCmds_gait_step
{
public:
  explicit Init_JoyCtrlCmds_gait_step(::lawd_msgs::msg::JoyCtrlCmds & msg)
  : msg_(msg)
  {}
  ::lawd_msgs::msg::JoyCtrlCmds gait_step(::lawd_msgs::msg::JoyCtrlCmds::_gait_step_type arg)
  {
    msg_.gait_step = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lawd_msgs::msg::JoyCtrlCmds msg_;
};

class Init_JoyCtrlCmds_pose
{
public:
  explicit Init_JoyCtrlCmds_pose(::lawd_msgs::msg::JoyCtrlCmds & msg)
  : msg_(msg)
  {}
  Init_JoyCtrlCmds_gait_step pose(::lawd_msgs::msg::JoyCtrlCmds::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_JoyCtrlCmds_gait_step(msg_);
  }

private:
  ::lawd_msgs::msg::JoyCtrlCmds msg_;
};

class Init_JoyCtrlCmds_gait_type
{
public:
  explicit Init_JoyCtrlCmds_gait_type(::lawd_msgs::msg::JoyCtrlCmds & msg)
  : msg_(msg)
  {}
  Init_JoyCtrlCmds_pose gait_type(::lawd_msgs::msg::JoyCtrlCmds::_gait_type_type arg)
  {
    msg_.gait_type = std::move(arg);
    return Init_JoyCtrlCmds_pose(msg_);
  }

private:
  ::lawd_msgs::msg::JoyCtrlCmds msg_;
};

class Init_JoyCtrlCmds_states
{
public:
  Init_JoyCtrlCmds_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoyCtrlCmds_gait_type states(::lawd_msgs::msg::JoyCtrlCmds::_states_type arg)
  {
    msg_.states = std::move(arg);
    return Init_JoyCtrlCmds_gait_type(msg_);
  }

private:
  ::lawd_msgs::msg::JoyCtrlCmds msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lawd_msgs::msg::JoyCtrlCmds>()
{
  return lawd_msgs::msg::builder::Init_JoyCtrlCmds_states();
}

}  // namespace lawd_msgs

#endif  // LAWD_MSGS__MSG__DETAIL__JOY_CTRL_CMDS__BUILDER_HPP_
