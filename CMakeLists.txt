cmake_minimum_required(VERSION 3.27)
project(keyboard_re_layout)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

add_executable(keyboard_re_layout main.cpp keyboard_re-layout.cpp keyboard_re-layout.h keyboard_lookup_table.h
        control_panel.cpp control_panel.h keyboard_lookup_table.cpp)
