cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

set( HSNET_SOURCES )
set( HSNET_PRIVATE_INCLUDE_DIR )
add_subdirectory( socket )

include_directories( ${DLIST_INCLUDE_DIR} )
include_directories( ${LIBFT_INCLUDE_DIR} )
include_directories( ${HSNET_INCLUDE_DIR} )
include_directories( ${HSNET_PRIVATE_INCLUDE_DIR} )
include_directories( . )

set( HSNET_SOURCES ${HSNET_SOURCES} utility.c )

GroupSources( HSNET_SOURCES )

set( LIB_HEADERS ${HSNET_INCLUDES} ${DLIST_INCLUDES} ${LIBFT_INCLUDES} )
foreach( HEADER ${LIB_HEADERS} )
    source_group( "Lib Header" FILES ${HEADER} )
endforeach( )

add_library( hsnet SHARED ${HSNET_SOURCES} ${LIB_HEADERS} )
target_link_libraries( hsnet dlist libft )