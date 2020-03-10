#include "Quad.hpp"

#include <utility>

Quad::Quad(std::vector<int> elements, const std::shared_ptr<unsigned int>& VBO, const float& maxZ)
: elements(std::move(elements)), VBO(VBO), maxZ(maxZ)
{}

void Quad::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(VAO);
    glVertexAttrib1f(1, maxZ);
    glDrawElements(GL_QUADS, elements.size(), GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glVertexAttrib1f(1, 0);
    glDrawElements(GL_QUADS, elements.size(), GL_UNSIGNED_INT, 0);
}

void Quad::bindBuffers()
{
    generateEbo();
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
}

void Quad::generateEbo()
{
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(int), elements.data(), GL_STATIC_DRAW);
}

