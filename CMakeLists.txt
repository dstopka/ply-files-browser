cmake_minimum_required(VERSION 3.15)
project(OOP_GL)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS include/GLWindow.hpp include/Object.hpp include/PolygonObject.hpp include/TriangleObject.hpp
        include/GridObject.hpp include/shaderLoader.h include/Toolpack.hpp)
set(SOURCES src/GLWindow.cpp src/PolygonObject.cpp src/TriangleObject.cpp src/GridObject.cpp src/shadersLoader.cpp src/Toolpack.cpp)

add_library(OOP_GL_lib ${HEADERS} ${SOURCES})
target_include_directories(OOP_GL_lib PUBLIC include)
include_directories(${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS})
add_executable(OOP_GL src/main.cpp)
target_link_libraries(OOP_GL OOP_GL_lib)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)
add_dependencies(OOP_GL OpenGL::OpenGL)
target_link_libraries(OOP_GL OpenGL::OpenGL ${GLUT_LIBRARY} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES})
