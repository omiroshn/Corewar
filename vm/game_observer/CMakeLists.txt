cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( GAME_OBS_SOURCEFILES	game_observer.c
							game_observer.h )

PREPEND( GAME_OBS_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${GAME_OBS_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${GAME_OBS_SRC} PARENT_SCOPE )
