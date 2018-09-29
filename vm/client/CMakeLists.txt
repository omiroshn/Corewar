cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( CLIENT_SOURCEFILES client.h
                        execute.c
                        connect.c
                        tcp_event_wrapper.c
                        tcp_event_wrapper.h
                        event_queue.c
                        event_queue.h )

PREPEND( VM_CLIENT_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${CLIENT_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_CLIENT_SRC} PARENT_SCOPE )
