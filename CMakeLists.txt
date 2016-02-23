cmake_minimum_required( VERSION 3.0 )
project( CheckPath )

include( ../CppAidKit/cmake/general_cmake_options.cmake )
include( ../CppAidKit/cmake/gcc_compile_options.cmake )
include( ../CppAidKit/cmake/aidkit_build_options.cmake )

add_executable( CheckPath
	src/main.cpp
	src/util.cpp
)

# Qt5 Setup:

set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
find_package( Qt5Widgets )

target_link_libraries( CheckPath AidKit Qt5::Widgets )
