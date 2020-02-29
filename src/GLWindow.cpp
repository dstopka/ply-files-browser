#include <GLWindow.hpp>
#include <iostream>
#include <GridObject.hpp>
#include <PolygonObject.hpp>
#include <TriangleObject.hpp>
#include <Object.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <shaderLoader.h>

GLWindow* GLWindow::instance = nullptr;

GLWindow::GLWindow(){}

void GLWindow::addShape(Data data)
{
    this->shapes.emplace_back(data);
    std::cout << "shape added" << std::endl;
}

void GLWindow::initScene(int &argc, char** &argv)
{
    setInstance();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(this->windowWidth, this->windowHeight);
    glutCreateWindow(argv[1]);
    glewInit();
    glutReshapeFunc(sizeWrapper);
    glutIdleFunc(idleWrapper);
    glutMouseFunc(mousePositionWrapper);
    glutMotionFunc(mouseMoveWrapper);
    glutDisplayFunc(displayWrapper);
    glutKeyboardFunc(keyboardInputWrapper);
    this->shader = loadShaders("../shaders/vertex_shader.glsl",
                               "../shaders/fragment_shader.glsl");
    glutMainLoop();
}

void GLWindow::keyboardInput(GLubyte key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(1);
        default:
            break;
    }
}

void GLWindow::mousePosition(int button, int state, int x, int y)
{
    mouse.button = button;
    switch (state)
    {
        case GLUT_UP:
            break;
        case GLUT_DOWN:
            mouse.x = x;
            mouse.y = y;
            previousCameraPosition.x = cameraPosition.x;
            previousCameraPosition.y = cameraPosition.y;
            previousCameraPosition.z = cameraPosition.z;
            previousCameraPosition.d = cameraPosition.d;
            break;
        default:
            break;
    }
}

void GLWindow::mouseMove(int x, int y)
{
    if (mouse.button == GLUT_LEFT_BUTTON) {
        cameraPosition.x = previousCameraPosition.x - (mouse.x - x) * 0.1;
        cameraPosition.z = previousCameraPosition.z - (mouse.y - y) * 0.1;
    }
    if (mouse.button == GLUT_RIGHT_BUTTON) {
        cameraPosition.d = previousCameraPosition.d + (mouse.y - y) * 0.1;
        cameraPosition.y = previousCameraPosition.y - (mouse.x - x) * 0.1;
    }
}

void GLWindow::idle()
{
    glutPostRedisplay();
}

void GLWindow::size(int width, int height)
{
    this->windowWidth = width;
    this->windowHeight = height;
    glViewport(0, 0, width, height);
}

void GLWindow::display()
{
    glm::mat4 MV;
    glm::mat4 P;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    std::vector<float> color = { 1,1,1,1 };
    glClearBufferfv(GL_COLOR, 0, color.data());
    MV = glm::mat4(1.0f);
    MV = glm::translate(MV, glm::vec3(0, 0, cameraPosition.d));
    MV = glm::rotate(MV, (float) glm::radians(cameraPosition.z), glm::vec3(1, 0, 0));
    MV = glm::rotate(MV, (float) glm::radians(cameraPosition.x), glm::vec3(0, 1, 0));
    MV = glm::rotate(MV, (float) glm::radians(cameraPosition.y), glm::vec3(0, 0, 1));
    P = glm::perspective(glm::radians(60.0f), (GLfloat) windowWidth / (GLfloat) windowHeight, 1.0f, 1000.0f);
    glm::mat4 MVP = P * MV;
    GLuint MVP_id = glGetUniformLocation(this->shader, "MVP");
    glUniformMatrix4fv(MVP_id, 1, GL_FALSE,
                       &(MVP[0][0]));
    for(auto &x : this->shapes)
        for(auto &y : x.getObjects())
            y->draw();
    glFlush();
    glutSwapBuffers();
}

void GLWindow::displayWrapper()
{
    instance->display();
}

void GLWindow::keyboardInputWrapper(GLubyte key, int x, int y)
{
    instance->keyboardInput(key, x, y);
}

void GLWindow::mousePositionWrapper(int button, int state, int x, int y)
{
    instance->mousePosition(button, state, x, y);
}

void GLWindow::mouseMoveWrapper(int x, int y)
{
    instance->mouseMove(x, y);
}

void GLWindow::idleWrapper()
{
    instance->idle();
}

void GLWindow::sizeWrapper(int width, int height)
{
    instance->size(width, height);
}

void GLWindow::setInstance()
{
    instance = this;
}


