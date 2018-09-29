cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ./include/ )
include_directories( ./src/ )

set( DLIST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE )
set( DLIST_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/dlist.h PARENT_SCOPE )

set( DLIST_FILES constructors.c
				 dlist_private.h
				 element_access.c
				 iterator.c
				 operations.c
				 pop_modifiers.c
				 push_modifiers.c )

PREPEND(DLIST_SOURCES src/ ${DLIST_FILES})

add_library( dlist SHARED ${DLIST_SOURCES} )
