cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_BOOT_SOURCEFILES    init.c
                            init.h
                            deinit.c
                            deinit.h
                            arg_parsing.c
                            arg_parsing.h )

PREPEND( VM_BOOT_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_BOOT_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_BOOT_SRC} PARENT_SCOPE )
