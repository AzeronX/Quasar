cmake_minimum_required (VERSION 2.6) 
project (Quasar)

set( SRC_DIR "${PROJECT_SOURCE_DIR}/src" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include("${PROJECT_SOURCE_DIR}/cmake/macros/HeadersDirectories.cmake")
include("${PROJECT_SOURCE_DIR}/cmake/macros/ProjectGenerator.cmake")
include("${PROJECT_SOURCE_DIR}/cmake/macros/Copy.cmake")

copy_files("src/glsl/*.glsl" "glsl")

if( WIN32 )
    set( BIN_EXTENSION ".exe" )
    copy_files("dep/windows/bin/*.dll" "")
endif()

include_directories("dep/windows/include")

HEADERS_DIRECTORIES(SRC_HEADERS)
include_directories( ${SRC_HEADERS} )


set( GLFW_LIB ${PROJECT_SOURCE_DIR}/dep/windows/lib/glfw3dll.lib)
set( GLEW_LIB ${PROJECT_SOURCE_DIR}/dep/windows/lib/glew32.lib)
set( NOISE_LIB ${PROJECT_SOURCE_DIR}/dep/windows/lib/libnoise.lib)


file(
    GLOB_RECURSE
    SRCS
    ${SRC_DIR}/*
)
GenerateProject( "${SRC_DIR}" "${SRCS}" )


add_executable("Quasar" ${SRCS})
target_link_libraries( "Quasar" ${GLFW_LIB} ${GLEW_LIB} ${NOISE_LIB} opengl32)
