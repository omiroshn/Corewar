cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( . )
include_directories( ${SHARED_INCLUDE_DIR} )
include_directories( ${HSCOMMONLIB_INCLUDE_DIR} )

add_executable( asm )

set( ASM_SOURCES
     asm.h
     main.c
     job.c
     job.h
     player.c
     player.h
     player_cmd_parser.c
     player_cmd_parser.h
     op_list.c
     op_list.h
     label_map.c
     label_map.h
     cor_file_disassemble.c
     cor_file_disassemble.h )

add_subdirectory( boot )
add_subdirectory( op_line )
add_subdirectory( op_vector )
add_subdirectory( error_logger )
add_subdirectory( token_parser )

foreach( SHARED_FILE ${SHARED_SRC} )
    set(GROUP "shared")
    if ("${SHARED_FILE}" MATCHES ".*\\.c")
       set(GROUP "${GROUP}\\Source Files")
    elseif("${SHARED_FILE}" MATCHES ".*\\.h")
       set(GROUP "${GROUP}\\Header Files")
    endif()
    source_group( "${GROUP}" FILES ${SHARED_FILE} )
endforeach( )

foreach( LIB_HEADER ${HSCOMMONLIB_INCLUDES} )
    source_group( "commonlib" FILES ${LIB_HEADER} )
endforeach( )

GroupSources( ASM_SOURCES )

target_sources( asm PUBLIC
                ${ASM_SOURCES}
                ${SHARED_SRC}
                ${HSCOMMONLIB_INCLUDES} )

target_link_libraries( asm ${HSCOMMONLIB_LIBRARIES} )
