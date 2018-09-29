cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( asm PUBLIC . )

set( ASM_ERR_SOURCEFILES	error_logger.c
					        error_logger.h
					        error_logger_print.c
					        error_logger_print.h )

PREPEND( ASM_ERR_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${ASM_ERR_SOURCEFILES} )

set( ASM_SOURCES ${ASM_SOURCES} ${ASM_ERR_SRC} PARENT_SCOPE )
