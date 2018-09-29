cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( SERVER_SOURCEFILES init.c
						execute.c
						client_manager.c
						multicast.c
						observer.c
                        server.h )

PREPEND( VM_SERVER_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${SERVER_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_SERVER_SRC} PARENT_SCOPE )
