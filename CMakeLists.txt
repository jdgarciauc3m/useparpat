cmake_minimum_required (VERSION 3.5)
set(PROJECT_NAME_STR useparpat)
project (${PROJECT_NAME_STR})

# Local project include directory
include_directories("${CMAKE_SOURCE_DIR}/include")

# Build binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(WARNFLAGS "-Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
list(APPEND CMAKE_CXX_FLAGS "${WARNFLAGS}")
else()
message(FATAL_ERROR "Unsupported compiler")
endif()

Find_Package(OpenMP REQUIRED)
Find_Package(Boost REQUIRED COMPONENTS thread)

#Process subdirectories
add_subdirectory(src)
