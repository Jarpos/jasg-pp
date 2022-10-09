cmake_minimum_required(VERSION 3.1...3.10)

project(jasg-pp VERSION 0.0
        DESCRIPTION "Just Another Snake Game++")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic \
                       -fsanitize=address -g -D_FORTIFY_SOURCE=2 \
                       -D_GLIBCXX_ASSERTIONS -fexceptions -fstack-protector \
                       -fstack-protector-all -g3 -pipe -D_REENTRANT")
     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter -Wno-variadic-macros \
                                         -Wno-unused-variable")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Detect and add SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(psd ${PROJECT_SOURCE_DIR})

set(cd ${psd}/src/logic)
set(logiclib ${cd}/position.cpp)
add_library(logiclib "${logiclib}")

set(cd ${psd}/src/ui)
set(uilib ${cd}/render_birbs.cpp
        ${cd}/render_board.cpp)
add_library(uilib "${uilib}")

add_executable(jasg-pp src/main.cpp)
target_link_libraries(jasg-pp logiclib uilib sfml-graphics sfml-audio)
