cmake_minimum_required(VERSION 3.16)

project(gtk_tp C)

set(CMAKE_C_STANDARD 99)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(gtk_tp main.c)

TARGET_LINK_LIBRARIES(gtk_tp ${GTK3_LIBRARIES})

#message(STATUS "\n----\nGTK include directories: ${GTK3_INCLUDE_DIRS}\n----\n")