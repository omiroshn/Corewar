cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( asm PUBLIC . )

set( ASM_BOOT_SOURCEFILES	init.c
                            init.h
                            deinit.c
                            deinit.h )

PREPEND( ASM_BOOT_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${ASM_BOOT_SOURCEFILES} )

set( ASM_SOURCES ${ASM_SOURCES} ${ASM_BOOT_SRC} PARENT_SCOPE )
