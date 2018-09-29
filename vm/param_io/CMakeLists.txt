cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_PARAM_IO_SOURCEFILES    param_reader.c
		                        param_reader.h
		                        param_writer.c
		                        param_writer.h )

PREPEND( VM_PARAM_IO_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_PARAM_IO_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_PARAM_IO_SRC} PARENT_SCOPE )
