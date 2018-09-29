cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

include( cmake/UtilityFunctions.cmake )

add_subdirectory( libft )
add_subdirectory( timer )
add_subdirectory( ft_math )
add_subdirectory( dlist )
add_subdirectory( vector )
add_subdirectory( hashmap )
add_subdirectory( thpool )
add_subdirectory( hsnet )

if( CMAKE_VERBOSE )
	message( STATUS "hscommonlib/libft include dir: " ${LIBFT_INCLUDE_DIR} )
	message( STATUS "hscommonlib/timer include dir: " ${TIMER_INCLUDE_DIR} )
	message( STATUS "hscommonlib/ft_math include dir: " ${FT_MATH_INCLUDE_DIR} )
	message( STATUS "hscommonlib/dlist include dir: " ${DLIST_INCLUDE_DIR} )
	message( STATUS "hscommonlib/vector include dir: " ${VECTOR_INCLUDE_DIR} )
	message( STATUS "hscommonlib/hashmap include dir: " ${HASHMAP_INCLUDE_DIR} )
	message( STATUS "hscommonlib/thpool include dir: " ${THPOOL_INCLUDE_DIR} )
	message( STATUS "hscommonlib/hsnet include dir: " ${HSNET_INCLUDE_DIR} )
endif( )

set( HSCOMMONLIB_INCLUDE_DIR	${LIBFT_INCLUDE_DIR}
								${TIMER_INCLUDE_DIR}
								${FT_MATH_INCLUDE_DIR}
								${DLIST_INCLUDE_DIR}
								${VECTOR_INCLUDE_DIR}
								${HASHMAP_INCLUDE_DIR}
								${THPOOL_INCLUDE_DIR}
								${HSNET_INCLUDE_DIR} PARENT_SCOPE )

set( HSCOMMONLIB_INCLUDES	${LIBFT_INCLUDES}
							${TIMER_INCLUDES}
							${FT_MATH_INCLUDES}
							${DLIST_INCLUDES}
							${VECTOR_INCLUDES}
							${HASHMAP_INCLUDES}
							${THPOOL_INCLUDES}
							${HSNET_INCLUDES} PARENT_SCOPE )

set( HSCOMMONLIB_LIBRARIES	libft
	                       	dlist
							hashmap
							thpool
							timer
							ft_math
							vector
							hsnet PARENT_SCOPE )
