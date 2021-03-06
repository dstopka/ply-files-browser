cmake_minimum_required(VERSION 3.15)
project(OOP_GL)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS include/GLWindow.hpp include/Polygon.hpp include/Quad.hpp include/Triangle.hpp
        include/Toolpack.hpp include/shaderLoader.h include/Mesh.hpp)
set(SOURCES src/GLWindow.cpp src/Quad.cpp src/Triangle.cpp src/Toolpack.cpp
        src/shadersLoader.cpp src/Mesh.cpp test/include/TestIncludes.hpp)

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
add_subdirectory(test)
