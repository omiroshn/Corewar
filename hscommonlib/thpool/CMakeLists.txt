cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ${DLIST_INCLUDE_DIR} )
include_directories( ./include/ )
include_directories( ./src/ )

set( THPOOL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE )
set( THPOOL_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/thpool.h PARENT_SCOPE )

set( THPOOL_FILES   thpool_init.c
                    thpool_managing.c
                    thpool_bsem.c
                    thpool_bsem_1.c
                    thpool_jobqueue.c
                    thpool_worker.c
                    thpool_private.h )

PREPEND(THPOOL_SOURCES src/ ${THPOOL_FILES})

add_library( thpool SHARED ${THPOOL_SOURCES} )
target_link_libraries( thpool dlist )
