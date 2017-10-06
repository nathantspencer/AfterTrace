cmake_minimum_required(VERSION 2.8)

project(NeuroStudio)

set(CMAKE_CXX_STANDARD 14)

#======================# INCLUDES #==========================#
include_directories(libs/imgui/include)


#======================# TARGETS #===========================#
file(GLOB_RECURSE SOURCES sources/*.cpp sources/*.h)
add_executable(NeuroStudio ${SOURCES})


#======================# LINKAGE #===========================#
target_link_libraries(NeuroStudio imgui)
