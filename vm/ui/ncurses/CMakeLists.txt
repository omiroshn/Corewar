cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( NCURSES_SOURCEFILES	curses.c
							curses.h
							render.c
							render.h
							livebreakdown.c
							livebreakdown.h
							render_arena.c
							render_arena.h )

PREPEND( VM_NCURSES_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${NCURSES_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_NCURSES_SRC} PARENT_SCOPE )
