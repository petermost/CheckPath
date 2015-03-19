cmake_minimum_required( VERSION 3.0 )
set( CMAKE_WARN_DEPRECATED ON )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( CheckPath )
add_compile_options( -std=c++14 -w -Wall -Wextra -pedantic )

add_executable( CheckPath
	src/main.cpp
	src/util.cpp
)

add_subdirectory( ../CppAidKit ./CppAidKit )
include_directories( ../CppAidKit/headers/ )
link_directories( ./CppAidKit-build )

# Qt5 Setup:

set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
find_package( Qt5Widgets )

target_link_libraries( CheckPath AidKit Qt5::Widgets )
