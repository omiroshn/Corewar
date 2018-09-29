cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_CTRL_SOURCEFILES	vm_controller.c
							vm_controller.h )

PREPEND( VM_CTRL_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_CTRL_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_CTRL_SRC} PARENT_SCOPE )
