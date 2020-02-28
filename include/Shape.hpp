#ifndef OOP_GL_SHAPE_HPP
#define OOP_GL_SHAPE_HPP

#include <Toolpack.hpp>
#include <Object.hpp>
#include <memory>

class Shape
{
public:
    explicit Shape(Data data);
    void generateVerticesBuffer();

private:
    unsigned int VBO;
    const Data data;
    std::vector<std::shared_ptr<Object>> objects;
};


#endif //OOP_GL_SHAPE_HPP
