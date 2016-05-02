#include "render.h"
#include "../controller/controller.h"
#include "dashboard.h"
#include "road.h"
#include "cycle.h"
#include "cars.h"
#include <stdio.h>

void render::renderFunction(){
    dashboard d;
    controller c;
    render r;

    if(c.getPlay() == 0){
        d.drawDashboard();
    }
    else{
        r.playGame();
    }
}
void render::playGame(){
    render r;
    road rd;
    cycle c;
    cars cr;

    glClearColor(0.0, 0.5, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    rd.drawRoad();

    glLoadIdentity();
    c.drawCycle();
    cr.drawCars();

    r.putScores();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
void render::putScores(){
    render r;
    glColor3f(1.0,1.0,1.0);
    glRectf(0.63, 0.75, 0.95, 0.98);

    glColor3f(0.0, 0.0, 0.0);
    char str[32];
    sprintf(str,"%d",r.getScore());
    r.drawBitmapText("Score",0.65,0.90,0.0);
    r.drawBitmapText(str,0.65,0.80,0.0);
}
void render::drawBitmapText(char *s,float x,float y,float z)
{
	glRasterPos3f(x,y,z);
	for(; *s != '\0'; s++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
    }
}
float render::getDistanceX(){
    return distanceX;
}
float render::getDistanceY(){
    return distanceY;
}
void render::setDistanceX(float value){
    distanceX = value;
}
void render::setDistanceY(float value){
    distanceY = value;
}
int render::getScore(){
    return score;
}
void render::setScore(int value){
    score = value;
}
int render::getLast(){
    return last;
}
void render::setLast(int value){
    last = value;
}
