cmake_minimum_required(VERSION 2.8)

project(NeuroStudio)

set(CMAKE_CXX_STANDARD 14)


#======================# INCLUDES #==========================#
include_directories(libs/imgui)


#======================# TARGETS #===========================#
file(GLOB_RECURSE SOURCES sources/*.cpp sources/*.h)
file(GLOB IMGUI libs/imgui/*.cpp libs/imgui/*.h)
add_executable(NeuroStudio ${SOURCES})
add_library(imgui ${IMGUI})


#======================# LINKAGE #===========================#
target_link_libraries(NeuroStudio imgui)
