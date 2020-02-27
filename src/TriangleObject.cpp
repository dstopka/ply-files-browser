#include "TriangleObject.hpp"

TriangleObject::TriangleObject(const std::vector<GLfloat> &vertices, const std::vector<int> &elements)
                                : vertices(vertices), elements(elements) {}

void TriangleObject::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, this->elements.size(), GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, this->elements.size(), GL_UNSIGNED_INT, 0);
}



