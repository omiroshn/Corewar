cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

project( Corewar )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra" )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake )

include( hscommonlib/cmake/UtilityFunctions.cmake )

get_filename_component( RESOURCES_PATH "resources" REALPATH BASE_DIR "${CMAKE_SOURCE_DIR}" )

add_definitions( -DPROJECT_PATH="${FULL_PATH}" )
add_definitions( -DRESOURCES_PATH="${RESOURCES_PATH}" )

add_subdirectory( hscommonlib )
add_subdirectory( shared )
add_subdirectory( vm )
add_subdirectory( assembler )
