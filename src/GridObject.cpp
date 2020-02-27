#include "GridObject.hpp"

GridObject::GridObject(const Dimension<std::pair<double, double>> &minMaxValues)
{

}

void GridObject::draw()
{
    glBindVertexArray(this->VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, 0);
    glLineStipple(1, 0x1111);
    glEnable(GL_LINE_STIPPLE);
    //glBindVertexArray(VAO[3]);
    //glDrawElements(GL_LINES, dottedElementsSize, GL_UNSIGNED_INT, 0);
    glDisable(GL_LINE_STIPPLE);
}
