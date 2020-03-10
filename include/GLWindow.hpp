#ifndef OOP_GL_GLWINDOW_HPP
#define OOP_GL_GLWINDOW_HPP
#include <Polygon.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <utility>
#include <vector>
#include <memory>
#include <glm/mat4x4.hpp>
#include <Toolpack.hpp>
#include <shaderLoader.h>
#include <Mesh.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class GLWindow
{
public:

public:
    GLWindow();

    void addShape(const Data& data);
    void initScene(int &argc, char** &argv);

private:
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
    static void sizeWrapper(int width, int height);
    static void idleWrapper();
    void setInstance();

private:
    std::vector<Mesh> shapes;
    Dimension<double> cameraPosition;
    Dimension<double> previousCameraPosition;
    Mouse mouse;
    static GLWindow *instance;
    int windowWidth;
    int windowHeight;
    GLuint shader;
};


#endif //OOP_GL_GLWINDOW_HPP
