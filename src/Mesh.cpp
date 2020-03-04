#include <Mesh.hpp>
#include <Quad.hpp>
#include <Triangle.hpp>
#include <utility>

Mesh::Mesh(Data data) : data(std::move(data))
{
    VBO = std::make_shared<unsigned int>();
    triangles = nullptr;
    quads = nullptr;
}

void Mesh::generateVerticesBuffer()
{
    glGenBuffers(1, VBO.get());
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, data.vertices.size() * sizeof(GLfloat), data.vertices.data(), GL_STATIC_DRAW);
}

void Mesh::draw()
{
    if(triangles != nullptr)
        triangles->draw();
    if(quads != nullptr)
        quads->draw();
}

void Mesh::createPolygons()
{
    generateVerticesBuffer();
    if(!this->data.triangleElements.empty())
    {
        triangles = std::make_shared<Triangle>(this->data.triangleElements, VBO, data.minMaxValues.z.second);
        triangles->bindBuffers();
    }
    if(!this->data.polygonElements.empty())
    {
        quads = std::make_shared<Quad>(this->data.polygonElements, VBO, data.minMaxValues.z.second);
        quads->bindBuffers();
    }
}
