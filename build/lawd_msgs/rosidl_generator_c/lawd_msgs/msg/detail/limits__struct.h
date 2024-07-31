// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lawd_msgs:msg/Limits.idl
// generated code does not contain a copyright notice

#ifndef LAWD_MSGS__MSG__DETAIL__LIMITS__STRUCT_H_
#define LAWD_MSGS__MSG__DETAIL__LIMITS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Limits in the package lawd_msgs.
/**
  * std_msgs/Header header
 */
typedef struct lawd_msgs__msg__Limits
{
  int16_t eular_ang_range[3];
  int16_t height_range[2];
  int16_t steplength_range[2];
} lawd_msgs__msg__Limits;

// Struct for a sequence of lawd_msgs__msg__Limits.
typedef struct lawd_msgs__msg__Limits__Sequence
{
  lawd_msgs__msg__Limits * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lawd_msgs__msg__Limits__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAWD_MSGS__MSG__DETAIL__LIMITS__STRUCT_H_
