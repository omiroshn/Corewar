cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_NCURSESOBS_SOURCEFILES		ncurses_observer.h
									ncurses_observer_private.h
									ncurses_observer.c
									handler_helpers.c
									io_handlers.c
									create_handlers.c
									handlers.c )

PREPEND( VM_NCURSESOBS_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_NCURSESOBS_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_NCURSESOBS_SRC} PARENT_SCOPE )
