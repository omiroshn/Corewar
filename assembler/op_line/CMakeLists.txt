cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( asm PUBLIC . )

set( ASM_OP_LINE_SOURCEFILES	op_line.c
								op_line.h
								op_line_cmd.c
								op_line_cmd.h
								op_line_label.c
								op_line_label.h
								op_line_size.c
								op_line_size.h )

PREPEND( ASM_OP_LINE_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${ASM_OP_LINE_SOURCEFILES} )

set( ASM_SOURCES ${ASM_SOURCES} ${ASM_OP_LINE_SRC} PARENT_SCOPE )
