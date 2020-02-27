#ifndef OOP_GL_TOOLPACK_HPP
#define OOP_GL_TOOLPACK_HPP

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>

template<typename T>
struct Dimension
{
    Dimension() {}
    Dimension(T x, T z, T y, T d = 0) : x(x), z(z), y(y), d(d) {}
    T x;
    T z;
    T y;
    T d;
};

struct Data
{
    std::vector<GLfloat> vertices;
    std::vector<int> polygonElements;
    std::vector<int> triangleElements;
    Dimension<std::pair<double, double>> minMaxValues;
};

struct Mouse
{
    int x;
    int y;
    int button;
};

Data readFile(char* path);
Dimension<std::pair<double, double>> findMinMax(std::vector<GLfloat> &vertices);

#endif //OOP_GL_TOOLPACK_HPP
