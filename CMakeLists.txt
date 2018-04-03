# cmake requirements
cmake_minimum_required(VERSION 2.8)

# Build options have to be before PROJECT(...)
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE PATH "Configuration types")
SET(CMAKE_BUILD_TYPE "Release" CACHE PATH "Current build configuration")

# Example Project configuration
PROJECT(TUTORIAL_USELIBRARY)
SET(CMAKE_CXX_FLAGS "-std=c++14")

# Folders
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# Settings
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include")

# demos
option(BUILD_LIB_ROBOT_DEMO "Build LIB Robot Demo" ON)
mark_as_advanced(BUILD_LIB_ROBOT_DEMO)

# find Eigen library
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(-Wno-deprecated -DEIGEN_DONT_VECTORIZE -DEIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT)

# Executable output directory
SET(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin${OUTPUT_DIRECTORY_POSTFIX} CACHE PATH "Executable output directory")
mark_as_advanced(RUNTIME_OUTPUT_DIRECTORY)

if (MSVC)
  SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
endif()


###############################################################################
#
# Eigen DEMO executables
#
###############################################################################

SET(DEMO_SOURCES ./main.cpp)
ADD_EXECUTABLE(eigenDemo ${DEMO_SOURCES})
#TARGET_LINK_LIBRARIES(eigenDemo) Eigen is the C++ template library and we don't have to link against Eigen
