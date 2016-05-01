#include "road.h"
#include "../controller/controller.h"
#include "render.h"

void road::drawRoad(){
    //Road grey color
    glColor3f(0.2, 0.2, 0.2);
    glRectf(-0.5, -1.0, 0.5, 1.0);

    //Divider/sides boundaries color wood
    glColor3f(0.5, 0.1, 0.05);
    glRectf(-0.05, -1.0, 0.05, 1.0);
    glRectf(-0.6, -1.0, -0.5, 1.0);
    glRectf(0.5, -1.0, 0.6, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glRectf(-0.005, -1.0, 0.005, 1.0);

    //Cycle Lane color white left and right side
    glColor3f(0.9, 0.9, 0.9);
    glRectf(-0.5, -1.0, -0.4, 1.0);
    glRectf(0.4, -1.0, 0.5, 1.0);

    //Dotted lane lines
    glColor3f(1.0, 1.0, 1.0);
    controller c;
    render r;
    if(c.getSpecial() != 0){
        r.setDistanceY(r.getDistanceY() - 0.01);
        if(r.getDistanceX() < -0.4){
            r.setScore(r.getScore()+1);
        }
        //std::cout << score << " ";
    }
    for(float i = r.getDistanceY(); i <= 1.0; i += 0.1){
        drawLine(-0.3, i, 0.0, -0.3, i + 0.05, 0.0);
        drawLine(-0.2, i, 0.0, -0.2, i + 0.05, 0.0);
        drawLine(0.2, i, 0.0, 0.2, i + 0.05, 0.0);
        drawLine(0.3, i, 0.0, 0.3, i + 0.05, 0.0);
    }
}
void road::drawLine(float x1,float y1,float z1,float x2,float y2,float z2){
    glBegin(GL_LINES);
        glVertex3f(x1 , y1 , z1);
        glVertex3f(x2 , y2 , z2);
    glEnd();
}
