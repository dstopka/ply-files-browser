#include "PolygonObject.hpp"

PolygonObject::PolygonObject(const std::vector<int> &elements, const unsigned int &VBO) : elements(elements), VBO(VBO)
{}

void PolygonObject::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(this->VAO);
    glDrawElements(GL_QUADS, this->elements.size(), GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_QUADS, this->elements.size(), GL_UNSIGNED_INT, 0);
}

void PolygonObject::bindBuffers()
{
    glGenVertexArrays(1, &(this->VAO));
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
}

void PolygonObject::generateEbo()
{
    glGenBuffers(1, &(this->ebo));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->elements.size() * sizeof(int), this->elements.data(), GL_STATIC_DRAW);
}

