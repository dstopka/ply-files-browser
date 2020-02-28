#ifndef OOP_GL_OBJECT_HPP
#define OOP_GL_OBJECT_HPP

class Object
{
public:
    virtual void draw() = 0;
    virtual void bindBuffers() = 0;
    virtual void generateEbo() = 0;
};

#endif //OOP_GL_OBJECT_HPP
