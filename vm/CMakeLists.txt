cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

add_executable( corewar )

include_directories( . )
include_directories( ${SHARED_INCLUDE_DIR} )
include_directories( ${HSCOMMONLIB_INCLUDE_DIR} )

find_package( CURSES REQUIRED)
include_directories( ${CURSES_INCLUDE_DIR} )

set( COREWAR_SOURCES    vm.h
                        main.c
                        player.c
                        player.h
                        process.c
                        process_init.c
                        network_common.h
                        process.h
                        check_up.c
                        check_up.h
                        dump.c
                        dump.h )

add_subdirectory( ui )
add_subdirectory( boot )
add_subdirectory( event )
add_subdirectory( client )
add_subdirectory( server )
add_subdirectory( param_io )
add_subdirectory( operations )
add_subdirectory( vm_controller )
add_subdirectory( game_observer )
add_subdirectory( ncurses_observer )
add_subdirectory( terminal_observer )

foreach( SHARED_FILE ${SHARED_SRC} )
    file(RELATIVE_PATH RELATIVE_PATH "${FULL_PATH}/shared" ${SHARED_FILE})
    get_filename_component( GROUP ${RELATIVE_PATH} DIRECTORY )
    string(REPLACE "/" "\\" GROUP "${GROUP}")
    source_group( "shared\\${GROUP}" FILES ${SHARED_FILE} )
endforeach( )

foreach( LIB_HEADER ${HSCOMMONLIB_INCLUDES} )
    source_group( "commonlib" FILES ${LIB_HEADER} )
endforeach( )

GroupSources( COREWAR_SOURCES )

target_sources( corewar PUBLIC  ${COREWAR_SOURCES}
                                ${SHARED_SRC}
                                ${HSCOMMONLIB_INCLUDES} )

target_link_libraries( corewar
                       ${HSCOMMONLIB_LIBRARIES}
                       ${CURSES_LIBRARIES} )
