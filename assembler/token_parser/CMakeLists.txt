cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( asm PUBLIC . )

set( ASM_TOKPAR_SOURCEFILES	token_parser.c
					        token_parser.h
					        token_parser_args.c
					        token_parser_args.h )

PREPEND( ASM_TOKPAR_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${ASM_TOKPAR_SOURCEFILES} )

set( ASM_SOURCES ${ASM_SOURCES} ${ASM_TOKPAR_SRC} PARENT_SCOPE )
