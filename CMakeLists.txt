cmake_minimum_required( VERSION 3.0 )
set( CMAKE_WARN_DEPRECATED ON )
set( CMAKE_VERBOSE_MAKEFILE ON )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

project( CheckPath )
add_compile_options( -std=c++14 -w -Wall -Wextra -pedantic )

add_executable( CheckPath
	src/main.cpp
	src/util.cpp
)

add_subdirectory( ../CppAidKit ./CppAidKit )
include_directories( ../CppAidKit/src/ )
link_directories( ./CppAidKit )

# Qt5 Setup:

set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
find_package( Qt5Widgets )

target_link_libraries( CheckPath AidKit Qt5::Widgets )
