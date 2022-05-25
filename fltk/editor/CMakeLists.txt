cmake_minimum_required(VERSION 3.0.0)
project(fltk_editor)

find_package(FLTK REQUIRED)

set(SRC
    main.cpp
)

add_executable(editor ${SRC})
target_link_libraries(editor ${FLTK_LIBRARIES})

