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
    std::shared_ptr<unsigned int> VBO;
    const Data data;
    std::vector<std::shared_ptr<Object>> objects;
public:
    const std::vector<std::shared_ptr<Object>> &getObjects() const;
};


#endif //OOP_GL_SHAPE_HPP
