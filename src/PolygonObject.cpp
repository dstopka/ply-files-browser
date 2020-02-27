#include "PolygonObject.hpp"

PolygonObject::PolygonObject(const std::vector<float> &vertices, const std::vector<int> &elements)
                            : vertices(vertices), elements(elements) {}

void PolygonObject::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(this->VAO);
    glDrawElements(GL_QUADS, this->elements.size(), GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_QUADS, this->elements.size(), GL_UNSIGNED_INT, 0);
}

