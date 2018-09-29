cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

add_subdirectory( ncurses )

set( COREWAR_SOURCES ${COREWAR_SOURCES} PARENT_SCOPE )
