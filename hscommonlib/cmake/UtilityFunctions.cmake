macro(GroupSources sources)
	foreach(FILE ${${sources}}) 
	    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

	    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
	    string(REPLACE "/" "\\" GROUP "${GROUP}")

	    # if ("${FILE}" MATCHES ".*\\.cpp|.*\\.c")
	    #    set(GROUP "Source Files${GROUP}")
	    # elseif("${FILE}" MATCHES ".*\\.h")
	    #    set(GROUP "Header Files${GROUP}")
	    # endif()

	    source_group("${GROUP}" FILES "${FILE}")
	endforeach()
endmacro()

FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)
