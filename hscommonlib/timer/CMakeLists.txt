cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ./include/ )

set( TIMER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE )
set( TIMER_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/timer.h PARENT_SCOPE )

set( TIMER_SOURCES src/timer.c )

add_library( timer SHARED ${TIMER_SOURCES} )
