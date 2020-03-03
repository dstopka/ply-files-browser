#ifndef OOP_GL_POLYGONOBJECT_HPP
#define OOP_GL_POLYGONOBJECT_HPP

#include <Object.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <memory>

class PolygonObject : public Object
{
public:
    PolygonObject(const std::vector<int> &elements, std::shared_ptr<unsigned int>VBO, float maxZ);
    void draw() override;
    void bindBuffers() override;
    void generateEbo() override;
private:
    std::vector<int> elements;
    std::shared_ptr<unsigned int> VBO;
    GLuint ebo;
    unsigned int VAO;
    float maxZ;
};

#endif //OOP_GL_POLYGONOBJECT_HPP
