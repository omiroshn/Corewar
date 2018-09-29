cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ./include/ )
include_directories( ./src/ )
include_directories( ${LIBFT_INCLUDE_DIR} )

set( HASHMAP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE )
set( HASHMAP_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/hashmap.h PARENT_SCOPE )

set( HASHMAP_FILES  init.c
                    io_hashmap.c
                    manage_hashmap.c
                    string_key_funcs.c
                    int_key_funcs.c
                    key_type_descriptors.c
                    size.c )

PREPEND(HASHMAP_SOURCES src/ ${HASHMAP_FILES})

add_library( hashmap SHARED ${HASHMAP_SOURCES} )
target_link_libraries( hashmap libft )
