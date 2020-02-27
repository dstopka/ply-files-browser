#ifndef OOP_GL_OBJECT_HPP
#define OOP_GL_OBJECT_HPP

class Object
{
public:
    virtual void drawSolid() = 0;
    virtual void drawOutline() = 0;
};

#endif //OOP_GL_OBJECT_HPP
