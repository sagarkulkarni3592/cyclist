#include "GL/freeglut.h"
#include "GL/gl.h"
#include "controller/controller.h"
#include "view/render.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(650,650);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Ride a bicycle");
    glutKeyboardFunc(controller::keyboardEventHandler);
    glutSpecialFunc(controller::specialKeyEventHandler);
    glutSpecialUpFunc(controller::keyUp);
    glutDisplayFunc(render::renderFunction);
    glutMainLoop();
    return 0;
}
