#ifndef OOP_GL_GRIDOBJECT_HPP
#define OOP_GL_GRIDOBJECT_HPP
#include <Object.hpp>
#include <Toolpack.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>

class GridObject : public Object
{
public:
    explicit GridObject(const Dimension<std::pair<double, double>> &minMaxValues);
    void draw();
private:
    std::vector<float> verticesWrappingLines;
    std::vector<float> verticesDottedLines;
    std::vector<int> elementsWrappingLines;
    std::vector<int> elementsDottedLines;
    unsigned int VBOWrappingLines;
    unsigned int VBODottedLines;
    GLuint eboWrappingLines;
    GLuint eboDottedLines;
};

#endif //OOP_GL_GRIDOBJECT_HPP
