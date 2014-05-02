macro(copy_files GLOBPAT DESTINATION)
  file(GLOB COPY_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${GLOBPAT})

  if(NOT TARGET copy)
    add_custom_target(copy ALL)
  endif(NOT TARGET copy)

  foreach(FILE ${COPY_FILES})
    get_filename_component(FILENAME "${FILE}" NAME)
    set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}")
    set(DST "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${DESTINATION}/${FILENAME}")

    add_custom_command(
      TARGET copy
      COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SRC} ${DST}
      COMMENT "Copying ${CMAKE_CURRENT_SOURCE_DIR}/${FILENAME} to ${DESTINATION}/${FILENAME}"
      )
  endforeach(FILE)
endmacro(copy_files)
