cmake_minimum_required(VERSION 2.8)

project(ASIO)

set( Boost_USE_STATIC_LIBS OFF )
set( Boost_USE_MULTITHREADED ON )

find_package(Boost 1.64 REQUIRED QUIET COMPONENTS asio)

message(STATUS "${Boost_LIBRARIES}") 

add_executable(ex12 main.cpp)

include_directories( ${Boost_INCLUDE_DIRS})

target_link_libraries(ex12 ${Boost_LIBRARIES})