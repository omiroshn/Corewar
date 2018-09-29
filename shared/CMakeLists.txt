cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

set( SHARED_FILES 	op.c op.h
					cor_file.c cor_file.h
					param_parser.c param_parser.h
					operand_input.c operand_input.h
					param.h )

PREPEND( SHARED_SRC_LOCAL ${CMAKE_CURRENT_SOURCE_DIR} ${SHARED_FILES} )

add_subdirectory( utility )

set( SHARED_SRC ${SHARED_SRC} ${SHARED_SRC_LOCAL} PARENT_SCOPE )
set( SHARED_INCLUDE_DIR ${SHARED_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE )
