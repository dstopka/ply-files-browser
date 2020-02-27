#ifndef OOP_GL_GLWINDOW_HPP
#define OOP_GL_GLWINDOW_HPP
#include <Object.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <utility>
#include <vector>
#include <memory>
#include <glm/mat4x4.hpp>
#include <Toolpack.hpp>
#include <shaderLoader.h>


class GLWindow
{
public:

public:
    GLWindow(const Data &data);
    void initScene(int &argc, char** &argv);
    void display();
    void keyboardInput(GLubyte key, int x, int y);
    void mousePosition(int button, int state, int x, int y);
    void mouseMove(int x, int y);
    void size(int width, int height);
    void idle();
    static void displayWrapper();
    static void keyboardInputWrapper(GLubyte key, int x, int y);
    static void mousePositionWrapper(int button, int state, int x, int y);
    static void mouseMoveWrapper(int x, int y);
    static void idleWrapper();
    static void sizeWrapper(int width, int height);
    void setInstance();

private:
    std::vector<std::shared_ptr<Object>> drawables;
    Dimension<double> cameraPosition;
    Dimension<double> previousCameraPosition;
    Mouse mouse;
    static GLWindow *instance;
    int windowWidth = 640;
    int windowHeight = 480;
    GLuint shader;
};

#endif //OOP_GL_GLWINDOW_HPP
