#include <GLWindow.hpp>

void GLWindow::initScene()
{

}

void GLWindow::drawScene()
{

}

void GLWindow::keyboardInput(GLubyte key, int x, int y)
{
//    switch (key)
//    {
//        case 27:
//            exit(1);
//            break;
//        case 'x':
//            dx += 1;
//            break;
//        case '1':
//            cameraX +=1;
//            break;
//        case '2':
//            cameraX -=1;
//            break;
//    }
}

void GLWindow::mousePosition(int button, int state, int x, int y)
{
//    mbutton = button;
//    switch (state) {
//        case GLUT_UP:
//            break;
//        case GLUT_DOWN:
//            mousePositionX = x;
//            mousePositionY = y;
//            previousCameraX = cameraX;
//            previousCameraZ = cameraZ;
//            previousCameraD = cameraD;
//            previousCameraY = cameraY;
//            break;
//    }
}

void GLWindow::mouseMove(int x, int y)
{
//    if (mbutton == GLUT_LEFT_BUTTON) {
//        cameraX = previousCameraX - (mousePositionX - x) * 0.1;
//        cameraZ = previousCameraZ - (mousePositionY - y) * 0.1;
//    }
//    if (mbutton == GLUT_RIGHT_BUTTON) {
//        cameraD = previousCameraD + (mousePositionY - y) * 0.1;
//        cameraY = previousCameraY - (mousePositionX - x) * 0.1;
//    }
}

void GLWindow::idle()
{
    glutPostRedisplay();
}
