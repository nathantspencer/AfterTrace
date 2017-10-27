cmake_minimum_required(VERSION 3.3)
project(NeuroStudio)
set(CMAKE_CXX_STANDARD 14)

message("Executing gl3w_gen.py")
execute_process(COMMAND python gl3w_gen.py --root ${PROJECT_BINARY_DIR}/libs/gl3w
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/gl3w)

#======================# INCLUDES #==========================#
include_directories(libs/imgui)
include_directories(libs/glfw/include)
include_directories(libs/gl3w/include)
include_directories(libs/glm)
include_directories(sources)

#=====================# EXTERNALS #==========================#
add_subdirectory(libs/glfw)
add_subdirectory(libs/gl3w)

#======================# FILTERS #===========================#
file(GLOB_RECURSE SOURCES sources/*.cpp sources/*.h)
file(GLOB_RECURSE SOURCES_MODEL sources/Model/*.cpp sources/Model/*.h)
file(GLOB_RECURSE SOURCES_FILEIO sources/FileIO/*.cpp sources/FileIO/*.h)
file(GLOB_RECURSE SOURCES_GUI_WINDOW sources/GUI/Window/*.cpp sources/GUI/Window/*.h)
file(GLOB_RECURSE SOURCES_IMGUIIMPL sources/ImguiImpl/*.cpp sources/ImguiImpl/*.h)

source_group("" FILES ${SOURCES})
source_group(Model FILES ${SOURCES_MODEL})
source_group(FileIO FILES ${SOURCES_FILEIO})
source_group(GUI\\Window FILES ${SOURCES_GUI_WINDOW})
source_group(ImguiImpl FILES ${SOURCES_IMGUIIMPL})

#======================# TARGETS #===========================#
add_executable(NeuroStudio ${SOURCES})

#======================# LINKAGE #===========================#
file(GLOB IMGUI libs/imgui/*.cpp libs/imgui/*.h)
add_library(imgui ${IMGUI})
target_link_libraries(NeuroStudio imgui glfw gl3w)
