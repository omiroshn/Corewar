cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

target_include_directories( corewar PUBLIC . )

set( VM_OPERATIONS_SOURCEFILES  operations.h
                                operations.c
                                op_live.c 
                                op_ld.c 
                                op_st.c 
                                op_add.c 
                                op_sub.c 
                                op_and.c 
                                op_or.c 
                                op_xor.c 
                                op_zjmp.c 
                                op_ldi.c 
                                op_sti.c 
                                op_fork.c 
                                op_lld.c 
                                op_lldi.c 
                                op_lfork.c 
                                op_aff.c
                                op_mul.c
                                op_div.c
                                op_cmp.c
                                op_jne.c )

PREPEND( VM_OP_SRC ${CMAKE_CURRENT_SOURCE_DIR} ${VM_OPERATIONS_SOURCEFILES} )

set( COREWAR_SOURCES ${COREWAR_SOURCES} ${VM_OP_SRC} PARENT_SCOPE )
