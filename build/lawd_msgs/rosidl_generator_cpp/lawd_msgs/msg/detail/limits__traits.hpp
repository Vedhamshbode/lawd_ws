// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lawd_msgs:msg/Limits.idl
// generated code does not contain a copyright notice

#ifndef LAWD_MSGS__MSG__DETAIL__LIMITS__TRAITS_HPP_
#define LAWD_MSGS__MSG__DETAIL__LIMITS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lawd_msgs/msg/detail/limits__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lawd_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Limits & msg,
  std::ostream & out)
{
  out << "{";
  // member: eular_ang_range
  {
    if (msg.eular_ang_range.size() == 0) {
      out << "eular_ang_range: []";
    } else {
      out << "eular_ang_range: [";
      size_t pending_items = msg.eular_ang_range.size();
      for (auto item : msg.eular_ang_range) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: height_range
  {
    if (msg.height_range.size() == 0) {
      out << "height_range: []";
    } else {
      out << "height_range: [";
      size_t pending_items = msg.height_range.size();
      for (auto item : msg.height_range) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: steplength_range
  {
    if (msg.steplength_range.size() == 0) {
      out << "steplength_range: []";
    } else {
      out << "steplength_range: [";
      size_t pending_items = msg.steplength_range.size();
      for (auto item : msg.steplength_range) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Limits & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: eular_ang_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.eular_ang_range.size() == 0) {
      out << "eular_ang_range: []\n";
    } else {
      out << "eular_ang_range:\n";
      for (auto item : msg.eular_ang_range) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: height_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.height_range.size() == 0) {
      out << "height_range: []\n";
    } else {
      out << "height_range:\n";
      for (auto item : msg.height_range) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: steplength_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.steplength_range.size() == 0) {
      out << "steplength_range: []\n";
    } else {
      out << "steplength_range:\n";
      for (auto item : msg.steplength_range) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Limits & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace lawd_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lawd_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lawd_msgs::msg::Limits & msg,
  std::ostream & out, size_t indentation = 0)
{
  lawd_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lawd_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lawd_msgs::msg::Limits & msg)
{
  return lawd_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lawd_msgs::msg::Limits>()
{
  return "lawd_msgs::msg::Limits";
}

template<>
inline const char * name<lawd_msgs::msg::Limits>()
{
  return "lawd_msgs/msg/Limits";
}

template<>
struct has_fixed_size<lawd_msgs::msg::Limits>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lawd_msgs::msg::Limits>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lawd_msgs::msg::Limits>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LAWD_MSGS__MSG__DETAIL__LIMITS__TRAITS_HPP_
