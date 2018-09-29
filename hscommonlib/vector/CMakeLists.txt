cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ./include/ )
include_directories( ./src/ )
include_directories( ${FT_MATH_INCLUDE_DIR} )

set( VECTOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE )
set( VECTOR_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/vector.h PARENT_SCOPE )

set( VECTOR_FILES constructors.c
				  vector_private.h
				  modifiers.c
				  capacity.c
				  vector_type_8bit.c
				  vector_type_16bit.c
				  vector_type_32bit.c
				  vector_type_64bit.c )

PREPEND(VECTOR_SOURCES src/ ${VECTOR_FILES})

add_library( vector SHARED ${VECTOR_SOURCES} )
