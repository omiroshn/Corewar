cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_EVENT_SOURCEFILES	event.h
							event_init.c
							event_post.c
							event_post_proc.c
							event_post_update.c
							observer_manager.c )

PREPEND( VM_EVENT_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_EVENT_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_EVENT_SRC} PARENT_SCOPE )
