#ifndef OOP_GL_TRIANGLEOBJECT_HPP
#define OOP_GL_TRIANGLEOBJECT_HPP
#include <Object.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>

class TriangleObject : public Object
{
public:
    TriangleObject(const std::vector<GLfloat> &vertices, const std::vector<int> &elements);
    void draw();
private:
    std::vector<GLfloat> vertices;
    std::vector<int> elements;
    unsigned int VBO;
    GLuint ebo;
};

#endif //OOP_GL_TRIANGLEOBJECT_HPP
