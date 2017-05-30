cmake_minimum_required (VERSION 3.0)
project (myjq)

set(CMAKE_CXX_STANDARD 14)

# The version number.
set(myjq_VERSION_MAJOR 0)
set(myjq_VERSION_MINOR 0)
set(myjq_VERSION_PATCH 1)

find_package(Boost 1.58 COMPONENTS
  program_options
  REQUIRED)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/myjq_config.h.in"
  "${PROJECT_BINARY_DIR}/myjq_config.h"
  )

# add the binary tree to the search path for include files
# so that we will find myjq_config.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/parser")
add_subdirectory (parser)

# add the executable
add_executable(myjq main.cpp)

target_link_libraries(myjq Boost::program_options)
target_link_libraries(myjq parser)
