#ifndef OOP_GL_POLYGONOBJECT_HPP
#define OOP_GL_POLYGONOBJECT_HPP
#include <Object.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>

class PolygonObject : public Object
{
public:
    PolygonObject(const std::vector<float> &vertices, const std::vector<int> &elements);
    void draw();
private:
    std::vector<float> vertices;
    std::vector<int> elements;
    unsigned int VBO;
    GLuint ebo;
    unsigned int VAO;
};

#endif //OOP_GL_POLYGONOBJECT_HPP
