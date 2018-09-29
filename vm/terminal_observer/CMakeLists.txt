cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_TERMOBS_SOURCEFILES		handlers.c
								handlers_proc.c
								terminal_observer.c
								terminal_observer.h
								terminal_observer_private.h )

PREPEND( VM_TERMOBS_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_TERMOBS_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_TERMOBS_SRC} PARENT_SCOPE )
