cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ./include/ )
include_directories( ./src/ )

set( FT_MATH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE )
set( FT_MATH_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/ft_math.h
					  ${CMAKE_CURRENT_SOURCE_DIR}/include/vecf.h
					  ${CMAKE_CURRENT_SOURCE_DIR}/include/scalar.h
					  ${CMAKE_CURRENT_SOURCE_DIR}/include/quaternion.h
					  ${CMAKE_CURRENT_SOURCE_DIR}/include/matrix.h
					  PARENT_SCOPE )

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-msse3")

set( FT_MATH_FILES 	scalar_geometry.c
					scalar_algebra.c
					scalar_conditional.c
					scalar_signed_conditional.c
					scalar_clamp.c

					vec3_constructors.c
					vec3_base_operations.c
					vec3_scalar_operations.c
					vec3_geometry.c
					vec3_geometry_2.c
					vec3_geometry_3.c
					vec3_compare_operations.c

					vec4_constructors.c
					vec4_base_operations.c
					vec4_scalar_operations.c
					vec4_geometry.c
					vec4_geometry_2.c
					vec4_geometry_3.c
					vec4_compare_operations.c

					quaternion_constructors.c
					quaternion_base_operations.c 

					mat4_constructors.c
					mat4_base_operations.c
					mat4_transform.c
					mat4_mvp.c )

PREPEND(FT_MATH_SOURCES src/ ${FT_MATH_FILES})

add_library( ft_math SHARED ${FT_MATH_SOURCES})
target_link_libraries( ft_math libft )

include_directories( ${LIBFT_INCLUDE_DIR} )

add_executable( ft_math_unit_test src/unit_test.c )
target_link_libraries( ft_math_unit_test ft_math libft )
