#include "TriangleObject.hpp"
#include <iostream>

TriangleObject::TriangleObject(const std::vector<int> &elements, std::shared_ptr<unsigned int> VBO, float maxZ)
: elements(elements), VBO(VBO), maxZ(maxZ)
{}

void TriangleObject::draw()
{
    std::cout << "triagle draw:" << glGetError() << std::endl;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(VAO);
    std::cout << "triagle:" << glGetError() << std::endl;
    std::cout << "triagle size:" << this->elements.size() << std::endl;
    std::cout << "triagle size:" << maxZ << std::endl;
    glVertexAttrib1f(1, maxZ);
    std::cout << "attr:" << glGetError() << std::endl;
    glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, 0);
    std::cout << "drawn:" << glGetError() << std::endl;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glVertexAttrib1f(1, 0);
    glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, 0);
    std::cout << "triagle:" << glGetError() << std::endl;
}

void TriangleObject::bindBuffers()
{
    std::cout << "triagle:" << std::endl;
    generateEbo();
    glGenVertexArrays(1, &VAO);
    std::cout << "triagle:" << glGetError() << std::endl;
    glBindVertexArray(VAO);
    std::cout << "triagle bafore vbo:" << glGetError() << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    std::cout << "triagle after vbo:" << glGetError() << std::endl;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    std::cout << "triagle:" << glGetError() << std::endl;
    glEnableVertexAttribArray(0);
    std::cout << "triagle:" << glGetError() << std::endl;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    std::cout << "triagle:" << glGetError() << std::endl;
}

void TriangleObject::generateEbo()
{
    glGenBuffers(1, &ebo);
    std::cout << "triagle:" << glGetError() << std::endl;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    std::cout << "triagle:" << glGetError() << std::endl;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(int), elements.data(), GL_STATIC_DRAW);
    std::cout << "triagle ebo end:" << glGetError() << std::endl;
}



