#ifndef OOP_GL_TRIANGLE_HPP
#define OOP_GL_TRIANGLE_HPP
#include <Polygon.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <memory>

class Triangle : public Polygon
{
public:
    Triangle(const std::vector<int> &elements, std::shared_ptr<unsigned int> VBO, float maxZ);
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

#endif //OOP_GL_TRIANGLE_HPP
