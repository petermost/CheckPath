cmake_minimum_required( VERSION 3.0 )

include( ../CppAidKit/cmake/set_general_cmake_options.cmake )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

project( CheckPath )
include( ../CppAidKit/cmake/add_gcc_compile_options.cmake )

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
