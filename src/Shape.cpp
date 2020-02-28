#include <Shape.hpp>
#include <GridObject.hpp>
#include <PolygonObject.hpp>
#include <TriangleObject.hpp>
#include <utility>

Shape::Shape(Data data) : data(std::move(data))
{
    this->generateVerticesBuffer();
    this->objects.push_back(std::make_shared<GridObject>(this->data.minMaxValues));
    if(!this->data.triangleElements.empty())
        this->objects.push_back(std::make_shared<TriangleObject>(this->data.triangleElements, this->VBO));
    if(!this->data.polygonElements.empty())
        this->objects.push_back(std::make_shared<PolygonObject>(this->data.polygonElements, this->VBO));
}

void Shape::generateVerticesBuffer()
{
    glGenBuffers(1, &(this->VBO));
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, this->data.vertices.size() * sizeof(float), this->data.vertices.data(), GL_STATIC_DRAW);
}
