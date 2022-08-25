cmake_minimum_required(VERSION 3.16)

project(HelloWorld)

include_directories(${PROJECT_SOURCE_DIR})

add_library(hellolib  hellolib.c)

add_executable(hellobin main.c)

target_link_libraries(hellobin hellolib)

install(TARGETS hellolib DESTINATION ${CMAKE_INSTALL_LIBDIR})

#install(FILES ${PROJECT_SOURCE_DIR}/hellolib.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS hellobin DESTINATION ${CMAKE_INSTALL_BINDIR})


