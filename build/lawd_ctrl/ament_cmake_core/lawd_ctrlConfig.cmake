# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lawd_ctrl_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lawd_ctrl_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lawd_ctrl_FOUND FALSE)
  elseif(NOT lawd_ctrl_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lawd_ctrl_FOUND FALSE)
  endif()
  return()
endif()
set(_lawd_ctrl_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lawd_ctrl_FIND_QUIETLY)
  message(STATUS "Found lawd_ctrl: 0.0.0 (${lawd_ctrl_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lawd_ctrl' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${lawd_ctrl_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lawd_ctrl_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${lawd_ctrl_DIR}/${_extra}")
endforeach()
