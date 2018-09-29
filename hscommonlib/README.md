# hscommonlib

List of common C libraries for 42 school projects:
  * dlist - Doubly linked list implementation for general purpose.
  * ft_math - Vectors, Matrix and Quaternions based on SSE2 instructions.
  * hashmap - Basic hashmap implementation, shipped with string-key support, easily extensible.
  * hsnet [WIP] - TCP and UDP Berkley Socket wrappers.
  * libft - Utility functions like memset, strstr, strlen and so on.
  * thpool - Threadpool on POSIX Threads.
  * timer - Minimalistic timer for just tracking time passed between function calls or frames.
  * vector - Not a very good attempt to write similiar container from C++. In most cases, just ignore it.

# Setup

- No dependencies - Ready To Use

# How To Use

- Library shipped with CMake. Usage example:

```
...

add_subdirectory( hscommonlib )

include_directories( ${HSCOMMONLIB_INCLUDE_DIR} )

add_executable( someProjectExecutable ... ${HSCOMMONLIB_INCLUDES} )

target_link_libraries( someProjectExecutable ... ${HSCOMMONLIB_LIBRARIES} )

...

```

