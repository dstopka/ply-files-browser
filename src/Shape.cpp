#include <Shape.hpp>
#include <GridObject.hpp>
#include <PolygonObject.hpp>
#include <TriangleObject.hpp>
#include <utility>
#include <iostream>

Shape::Shape(Data data) : data(std::move(data))
{
    std::cout << "constructor" << std::endl;
    //this->generateVerticesBuffer();
    this->objects.push_back(std::make_shared<GridObject>(this->data.minMaxValues));
    if(!this->data.triangleElements.empty())
        this->objects.push_back(std::make_shared<TriangleObject>(this->data.triangleElements, this->VBO));
    if(!this->data.polygonElements.empty())
        this->objects.push_back(std::make_shared<PolygonObject>(this->data.polygonElements, this->VBO));
    std::cout << "buffer binding" << std::endl;
//    for(auto &x : this->objects)
//        x->bindBuffers();
}

void Shape::generateVerticesBuffer()
{
    std::cout << "generate buffer" << std::endl;
    glGenBuffers(1, &(this->VBO));
    std::cout << "bind vbo" << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->data.vertices.size() * sizeof(float), this->data.vertices.data(), GL_STATIC_DRAW);
}

const std::vector<std::shared_ptr<Object>> &Shape::getObjects() const
{
    return objects;
}
