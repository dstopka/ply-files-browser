#include <Shape.hpp>
#include <GridObject.hpp>
#include <PolygonObject.hpp>
#include <TriangleObject.hpp>
#include <utility>
#include <iostream>

Shape::Shape(Data data) : data(std::move(data))
{
    std::cout << "constructor" << std::endl;
    VBO = std::make_shared<unsigned int>();
    objects.push_back(std::make_shared<GridObject>(data.minMaxValues));
    if(!this->data.triangleElements.empty())
        objects.push_back(std::make_shared<TriangleObject>(this->data.triangleElements, VBO));
    if(!this->data.polygonElements.empty())
        objects.push_back(std::make_shared<PolygonObject>(this->data.polygonElements, VBO));
    std::cout << "buffer binding" << std::endl;
}

void Shape::generateVerticesBuffer()
{
    std::cout << "generate buffer" << std::endl;
    glGenBuffers(1, VBO.get());
    std::cout << "bind vbo" << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    std::cout << "vbo:" << glGetError() << std::endl;
    glBufferData(GL_ARRAY_BUFFER, data.vertices.size() * sizeof(GLfloat), data.vertices.data(), GL_STATIC_DRAW);
    std::cout << "vbo binded..." << std::endl;
}

const std::vector<std::shared_ptr<Object>> &Shape::getObjects() const
{
    return objects;
}
