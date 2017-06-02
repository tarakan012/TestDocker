cmake_minimum_required(VERSION 2.8)

set(project UCORE)

project(${project})

file(GLOB ${project}_SOURCES "*.cpp")
file(GLOB ${project}_HEADERS "*.h")

file(GLOB ${project}_SOURCES_LIST ${project}_SOURCES ${project}_HEADERS)


message(STATUS "${project}_SOURCES_LIST")


add_library(UCORE, STATIC ${SOURCE_LIB})