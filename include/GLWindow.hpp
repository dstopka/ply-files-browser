#ifndef OOP_GL_GLWINDOW_HPP
#define OOP_GL_GLWINDOW_HPP
#include <Object.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <utility>
#include <vector>
#include <memory>
#include "Toolpack.hpp"

class GLWindow
{
public:
    GLWindow(const Data &data);
    void initScene();
    void drawScene();
    void keyboardInput(GLubyte key, int x, int y);
    void mousePosition(int button, int state, int x, int y);
    void mouseMove(int x, int y);
    void idle();
private:
    std::vector<std::shared_ptr<Object>> drawables;
    Dimension<double> cameraPosition;
    Dimension<double> previousCameraPosition;
};

#endif //OOP_GL_GLWINDOW_HPP
