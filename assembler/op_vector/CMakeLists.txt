cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( asm PUBLIC . )

set( ASM_VEC_SOURCEFILES	op_vector.c
					        op_vector.h
					        op_vector_write_arg.c
					        op_vector_write_arg.h )

PREPEND( ASM_VEC_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${ASM_VEC_SOURCEFILES} )

set( ASM_SOURCES ${ASM_SOURCES} ${ASM_VEC_SRC} PARENT_SCOPE )
