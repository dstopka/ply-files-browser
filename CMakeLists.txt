cmake_minimum_required(VERSION 3.15)
project(OOP_GL)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS include/GLWindow.hpp include/Object.hpp include/PolygonObject.hpp include/TriangleObject.hpp
        include/GridObject.hpp)
set(SOURCES src/GLWindow.cpp src/PolygonObject.cpp src/TriangleObject.cpp src/GridObject.cpp)

add_library(OOP_GL_lib ${HEADERS} ${SOURCES})
target_include_directories(OOP_GL_lib PUBLIC include)

add_executable(OOP_GL src/main.cpp)
target_link_libraries(OOP_GL OOP_GL_lib)