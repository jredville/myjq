cmake_minimum_required (VERSION 3.0)
project (myjq)

find_package(Boost 1.58 COMPONENTS program_options REQUIRED)

add_executable(myjq main.cpp)

target_link_libraries(myjq Boost::program_options)
