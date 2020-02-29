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
    glDrawElements(GL_LINES, elementsWrappingLines.size(), GL_UNSIGNED_INT, 0);
    glLineStipple(1, 0x1111);
    glEnable(GL_LINE_STIPPLE);
    glBindVertexArray(this->VAODottedLines);
    glDrawElements(GL_LINES, elementsDottedLines.size(), GL_UNSIGNED_INT, 0);
    glDisable(GL_LINE_STIPPLE);
    //std::cout << "grid drawn" << std::endl;
}

void GridObject::bindBuffers()
{
    generateVbo();
    generateEbo();
    glGenVertexArrays(1, &(this->VAOWrappingLines));
    glBindVertexArray(this->VAOWrappingLines);
    glBindBuffer(GL_ARRAY_BUFFER, VBOWrappingLines);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboWrappingLines);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );

    glGenVertexArrays(1, &(this->VAODottedLines));
    glBindVertexArray(this->VAODottedLines);
    glBindBuffer(GL_ARRAY_BUFFER, VBODottedLines);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboDottedLines);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
}

void GridObject::generateEbo()
{
    glGenBuffers(1, &(this->eboWrappingLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->eboWrappingLines);
    glBufferData(GL_ARRAY_BUFFER, this->elementsWrappingLines.size() * sizeof(float),
                 this->elementsWrappingLines.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &(this->eboDottedLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->eboDottedLines);
    glBufferData(GL_ARRAY_BUFFER, this->elementsDottedLines.size() * sizeof(float),
                 this->elementsDottedLines.data(), GL_STATIC_DRAW);
}

void GridObject::generateVbo()
{
    glGenBuffers(1, &(this->VBOWrappingLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->VBOWrappingLines);
    glBufferData(GL_ARRAY_BUFFER, this->verticesWrappingLines.size() * sizeof(float),
            this->verticesWrappingLines.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &(this->VBODottedLines));
    glBindBuffer(GL_ARRAY_BUFFER, this->VBODottedLines);
    glBufferData(GL_ARRAY_BUFFER, this->verticesDottedLines.size() * sizeof(float),
            this->verticesDottedLines.data(), GL_STATIC_DRAW);
}

void GridObject::createVertices()
{
    std::array maxLines = {(int)(this->minMaxValues.x.second / 0.1),
                           (int)(this->minMaxValues.y.second / 0.1),
                           (int)(this->minMaxValues.z.second / 0.1)};
    this->verticesWrappingLines = {0, 0, 0,
                                  this->minMaxValues.x.second, 0, 0,
                                  0, this->minMaxValues.y.second, 0,
                                  0, this->minMaxValues.y.second, this->minMaxValues.z.second};

    for(int i = 0; i < maxLines[0]; ++i)
    {
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back(this->minMaxValues.z.second);
    }

    for(int i = 0; i < maxLines[1]; ++i)
    {
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.z.second);
    }

    for(int i = 0; i < maxLines[2]; ++i)
    {
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back(this->minMaxValues.y.second);
        this->verticesDottedLines.push_back((i+1) * 0.1);
        this->verticesDottedLines.push_back(this->minMaxValues.x.second);
        this->verticesDottedLines.push_back(0);
        this->verticesDottedLines.push_back((i+1) * 0.1);
    }
}

void GridObject::createElements()
{
    std::array maxLines = {(int)(this->minMaxValues.x.second / 0.1),
                           (int)(this->minMaxValues.y.second / 0.1),
                           (int)(this->minMaxValues.z.second / 0.1)};
    this->elementsWrappingLines = {1, 0, 0, 2, 2, 3};
    int idx = 0;
    for(int i = 0; i < maxLines[0] + maxLines[1] + maxLines[2]; ++i)
    {
        this->elementsDottedLines.push_back(idx++);
        this->elementsDottedLines.push_back(idx);
        this->elementsDottedLines.push_back(idx++);
        this->elementsDottedLines.push_back(idx++);
    }
}
