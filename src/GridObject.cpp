#include "GridObject.hpp"
#include <vector>
#include <array>
#include <iostream>

GridObject::GridObject(const Dimension<std::pair<float, float>> &minMaxValues) : minMaxValues(minMaxValues)
{
    createVertices();
    createElements();
}

void GridObject::draw()
{
    //std::cout << "draw grid" << std::endl;
    glBindVertexArray(this->VAOWrappingLines);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_LINES, this->elementsWrappingLines.size(), GL_UNSIGNED_INT, 0);
    //std::cout << glGetError() << std::endl;
    glLineStipple(1, 0x1111);
    glEnable(GL_LINE_STIPPLE);
    glBindVertexArray(this->VAODottedLines);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, 0);
    glDisable(GL_LINE_STIPPLE);
    //std::cout << "grid drawn" << std::endl;
    //std::cout << glGetError() << std::endl;
}

void GridObject::bindBuffers()
{
    generateVbo();
    generateEbo();

    glGenVertexArrays(1, &(this->VAOWrappingLines));
    glBindVertexArray(this->VAOWrappingLines);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBOWrappingLines);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboWrappingLines);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    std::cout << glGetError() << std::endl;

    glGenVertexArrays(1, &(this->VAODottedLines));
    glBindVertexArray(this->VAODottedLines);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBODottedLines);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboDottedLines);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    std::cout << glGetError() << std::endl;
}

void GridObject::generateEbo()
{
    glGenBuffers(1, &(this->eboWrappingLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->eboWrappingLines);
    glBufferData(GL_ARRAY_BUFFER, this->elementsWrappingLines.size() * sizeof(int),
                 this->elementsWrappingLines.data(), GL_STATIC_DRAW);
    std::cout << glGetError() << std::endl;

    glGenBuffers(1, &(this->eboDottedLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->eboDottedLines);
//    glBufferData(GL_ARRAY_BUFFER, this->elementsDottedLines.size() * sizeof(int),
//                 this->elementsDottedLines.data(), GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, this->elementsDottedLines.size() * sizeof(GLuint),
                 &this->elementsDottedLines[0], GL_STATIC_DRAW);
    std::cout << glGetError() << std::endl;
    std::cout << "el size " <<  this->elementsDottedLines.size() << std::endl;
}

void GridObject::generateVbo()
{
    glGenBuffers(1, &(this->VBOWrappingLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->VBOWrappingLines);
    glBufferData(GL_ARRAY_BUFFER, this->verticesWrappingLines.size() * sizeof(float),
                 this->verticesWrappingLines.data(), GL_STATIC_DRAW);
    std::cout << glGetError() << std::endl;

    glGenBuffers(1, &(this->VBODottedLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->VBODottedLines);
    glBufferData(GL_ARRAY_BUFFER, this->verticesDottedLines.size() * sizeof(float),
                 this->verticesDottedLines.data(), GL_STATIC_DRAW);
    std::cout << glGetError() << std::endl;

    std::cout << "vtx size " <<  this->verticesDottedLines.size() << std::endl;
}

void GridObject::createVertices()
{
    std::array maxLines = {(int) (this->minMaxValues.x.second / 0.1),
                           (int) (this->minMaxValues.y.second / 0.1),
                           (int) (this->minMaxValues.z.second / 0.1)};

    std::cout << "x.max " << this->minMaxValues.x.second << std::endl;
    std::cout << "y.max " << this->minMaxValues.y.second << std::endl;
    std::cout << "z.max " << this->minMaxValues.z.second << std::endl;
    std::cout << "x.min " << this->minMaxValues.x.first << std::endl;
    std::cout << "y.min " << this->minMaxValues.y.first << std::endl;
    std::cout << "z.min " << this->minMaxValues.z.first << std::endl;


    this->verticesWrappingLines = {0, 0, 0,
                                   this->minMaxValues.x.second, 0, 0,
                                   0, this->minMaxValues.y.second, 0,
                                   0, this->minMaxValues.y.second, this->minMaxValues.z.second};

    for (int i = 0; i < maxLines[0]; ++i)
    {
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back(this->minMaxValues.z.second);
    }

    for (int i = 0; i < maxLines[1]; ++i)
    {
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.z.second);
    }

    for (int i = 0; i < maxLines[2]; ++i)
    {
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i + 1) * 0.1);
    }
//    for(auto &x : this->verticesDottedLines)
//        std::cout << "vertex: " << x << std::endl;
    for (int i = 0; i < this->verticesDottedLines.size(); ++i)
    {
        if(!(i%3))

            std::cout << "vertex " << i/3 << std::endl;

        std::cout << this->verticesDottedLines[i] << std::endl;
    }
}

void GridObject::createElements()
{
    std::array maxLines = {(int)(this->minMaxValues.x.second / 0.1),
                           (int)(this->minMaxValues.y.second / 0.1),
                           (int)(this->minMaxValues.z.second / 0.1)};
    this->elementsWrappingLines = {1, 0, 0, 2, 2, 3};
    int idx = 0;
    std::cout << "array \t" << maxLines[0] << "\t" << maxLines[1] << "\t" << maxLines[2] << std::endl;
    for(int i = 0; i < maxLines[0] + maxLines[1] + maxLines[2]; ++i)
    {
//    for(int i = 0; i < maxLines[0]; ++i)
//    {
        this->elementsDottedLines.push_back(idx++);
        this->elementsDottedLines.push_back(idx);
        this->elementsDottedLines.push_back(idx++);
        this->elementsDottedLines.push_back(idx++);
    }
    for(auto &x : this->elementsDottedLines)
        std::cout << "element: " << x << std::endl;
}
