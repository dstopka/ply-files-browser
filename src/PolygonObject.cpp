#include "PolygonObject.hpp"

PolygonObject::PolygonObject(const std::vector<int> &elements, std::shared_ptr<unsigned int> VBO) : elements(elements), VBO(VBO)
{}

void PolygonObject::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(VAO);
    glDrawElements(GL_QUADS, elements.size(), GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_QUADS, elements.size(), GL_UNSIGNED_INT, 0);
}

void PolygonObject::bindBuffers()
{
    generateEbo();
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
}

void PolygonObject::generateEbo()
{
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(int), elements.data(), GL_STATIC_DRAW);
}

