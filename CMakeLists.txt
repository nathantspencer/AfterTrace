cmake_minimum_required(VERSION 2.8)
project(AfterTrace)
set(CMAKE_CXX_STANDARD 14)

message("Executing gl3w_gen.py")
execute_process(COMMAND python gl3w_gen.py --root ${PROJECT_BINARY_DIR}/libs/gl3w
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/gl3w)

set(NFD_PATH libs/nativefiledialog)

#======================# INCLUDES #==========================#
include_directories(libs/imgui)
include_directories(libs/glfw/include)
include_directories(libs/gl3w/include)
include_directories(libs/glm)
include_directories(libs/nativefiledialog/src/include)
include_directories(sources)

#=====================# EXTERNALS #==========================#
add_subdirectory(libs/glfw)
add_subdirectory(libs/gl3w)

#======================# FILTERS #===========================#
file(GLOB_RECURSE SOURCES sources/*.cpp sources/*.h)
file(GLOB_RECURSE SOURCES_MODEL sources/Model/*.cpp sources/Model/*.h)
file(GLOB_RECURSE SOURCES_FILEIO sources/FileIO/*.cpp sources/FileIO/*.h)
file(GLOB SOURCES_GUI sources/GUI/*.cpp sources/GUI/*.h)
file(GLOB_RECURSE SOURCES_GUI_WINDOW sources/GUI/Window/*.cpp sources/GUI/Window/*.h)
file(GLOB_RECURSE SOURCES_GUI_MENUBAR sources/GUI/MenuBar/*.cpp sources/GUI/MenuBar/*.h)

file(GLOB IMGUI libs/imgui/*.cpp libs/imgui/*.h)
file(GLOB_RECURSE NFD ${NFD_PATH}/src/*.cpp ${NFD}/src/*.h)

source_group("" FILES ${SOURCES})
source_group(Model FILES ${SOURCES_MODEL})
source_group(FileIO FILES ${SOURCES_FILEIO})
source_group(GUI FILES ${SOURCES_GUI})
source_group(GUI\\Window FILES ${SOURCES_GUI_WINDOW})
source_group(GUI\\MenuBar FILES ${SOURCES_GUI_MENUBAR})

#======================# TARGETS #===========================#
add_executable(AfterTrace ${SOURCES})

#======================# LINKAGE #===========================#
add_library(nativefiledialog ${NFD})
add_library(imgui ${IMGUI})
target_link_libraries(AfterTrace imgui glfw gl3w ${PROJECT_SOURCE_DIR}/${NFD_PATH}/build/lib/Release/x64/libnfd.a)
