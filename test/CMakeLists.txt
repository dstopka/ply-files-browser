set(GOOGLETEST ../googletest)

include_directories(${GOOGLETEST}/googletest/include)
link_directories(${GOOGLETEST}/build/lib)

set(TEST_HEADERS include/TestIncludes.h)
set(TEST_SOURCES src/GLWindowTest.cpp)

add_executable(OOP_GL_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(OOP_GL_test PUBLIC include)
target_link_libraries(OOP_GL_test OOP_GL_lib gtest gtest_main pthread)