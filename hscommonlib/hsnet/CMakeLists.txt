cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

set( HSNET_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include )
set( HSNET_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/hsnet.h )

set( HSNET_INCLUDE_DIR ${HSNET_INCLUDE_DIR} PARENT_SCOPE )
set( HSNET_INCLUDES ${HSNET_INCLUDES} PARENT_SCOPE )

add_subdirectory( src )