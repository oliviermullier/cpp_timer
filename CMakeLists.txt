cmake_minimum_required(VERSION 3.5)

project(cpp_timer VERSION 1.0.0 DESCRIPTION "C++ timer of any scope")
include(GNUInstallDirs)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set(source_dir "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB header_files "${source_dir}/*.h")
add_library(cpp_timer ${source_files})

set_target_properties(cpp_timer PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER ${header_files}
)
    
configure_file(cpp_timer.pc.in cpp_timer.pc @ONLY)

target_include_directories(cpp_timer PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_timer>)

install(TARGETS cpp_timer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/cpp_timer.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)



