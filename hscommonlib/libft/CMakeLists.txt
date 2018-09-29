cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

include_directories( ./include/ )
include_directories( ./src/ft_printf/include/ )

set( LIBFT_INCLUDE_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/include 
                         ${CMAKE_CURRENT_SOURCE_DIR}/src/ft_printf/include 
                         ${CMAKE_CURRENT_SOURCE_DIR}/src/ft_printf/src  PARENT_SCOPE )

set( LIBFT_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/libft.h
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/ft_printf/include/ft_printf.h PARENT_SCOPE )

set( LIBFT_FILES    ft_merge.c
                    ft_split_str_to_int.c
                    ft_sizeofnumber.c
                    ft_atoi_base.c
                    ft_countwords.c
                    ft_getword.c
                    ft_isnum.c
                    ft_realloc.c
                    ft_islower.c
                    ft_strsplit.c
                    ft_putnbr_fd.c
                    ft_putstr_fd.c
                    ft_putendl_fd.c
                    ft_putchar_fd.c
                    ft_strtrim.c
                    ft_strjoin.c
                    ft_strsub.c
                    ft_strmapi.c
                    ft_strmap.c
                    ft_striteri.c
                    ft_strlcat.c
                    ft_strrev.c
                    ft_power.c
                    ft_bzero.c
                    ft_memset.c
                    ft_strlen.c
                    ft_strdup.c
                    ft_strcpy.c
                    ft_atoi.c
                    ft_isdigit.c
                    ft_isspace.c
                    ft_strcat.c
                    ft_strncat.c
                    ft_strchr.c
                    ft_strrchr.c
                    ft_strstr.c
                    ft_strnstr.c
                    ft_strcmp.c
                    ft_strncmp.c
                    ft_isalpha.c
                    ft_isalnum.c
                    ft_isascii.c
                    ft_isprint.c
                    ft_toupper.c
                    ft_isupper.c
                    ft_tolower.c
                    ft_memcpy.c
                    ft_memccpy.c
                    ft_memmove.c
                    ft_memchr.c
                    ft_memcmp.c
                    ft_strncpy.c
                    ft_memalloc.c
                    ft_memdel.c
                    ft_strnew.c
                    ft_strdel.c
                    ft_strclr.c
                    ft_striter.c
                    ft_strequ.c
                    ft_strnequ.c
                    ft_putchar.c
                    ft_putstr.c
                    ft_putendl.c
                    ft_putnbr.c
                    ft_itoa.c
                    ft_strisdigit.c
                    ft_strisalpha.c
                    ft_strislower.c
                    ft_strisupper.c
                    ft_strisspaces.c
                    get_next_line.c
                    is_directory.c
                    ft_swap.c
                    pair.c
                    ft_atod.c
                    fs_path_manip.c )

set( PRINTF_FILES   print.c
                    color.c
                    print_character.c
                    print_radix.c
                    print_pointer.c
                    print_string.c
                    print_decimal.c
                    print_float.c
                    itoa_base.c
                    ftoa.c
                    casts/cast3.c
                    casts/cast2.c
                    casts/cast1.c
                    ft_printf.c
                    padding.c
                    flags.c
                    specifier.c
                    sub_specifiers.c
                    buffer_manager.c )

PREPEND(LIBFT_SOURCES src/ ${LIBFT_FILES})
PREPEND(PRINTF_SOURCES src/ft_printf/src/ ${PRINTF_FILES} )

add_library( libft SHARED ${LIBFT_SOURCES} ${PRINTF_SOURCES} )
