#include "dashboard.h"
#include "render.h"
#include <stdio.h>
#include <stdlib.h>

void dashboard::drawDashboard(){
    render r;
    glClearColor(0.0, 0.5, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    size = readFile("scores.txt");
    int max = 0;
    for(int i = 0; i < size; i++){
        if(v[i] > max){
            max = v[i];
        }
    }

    glColor3f(1.0,1.0,1.0);
    glRectf(-0.5, 0.7, 0.5, 0.9);
    glRectf(-0.5, -0.6, 0.5, 0.6);
    glRectf(-0.5, -0.9, 0.5, -0.7);

    glColor3f(0.0, 0.0, 0.0);
    char str[32];
    if(size != 0){
        sprintf(str,"%d",max);
    }
    else{
        str[0] = '0';
        str[1] = '\0';
    }
    r.drawBitmapText("High Score : ",-0.4,0.785,0.0);
    r.drawBitmapText(str,0.05,0.783,0.0);

    r.drawBitmapText("Some Previous Scores : ",-0.4,0.5,0.0);
    for(int i = 0; i < size; i++){
        sprintf(str,"%d",v[i]);
        r.drawBitmapText(str,-0.4,0.4 - (i * 0.1),0.0);
    }

    r.drawBitmapText("Hit space button to play",-0.4,-0.825,0.0);

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
int dashboard::readFile(char * name){
    int val;
    FILE *fp;
    fp = fopen(name,"rb+");
    if(fp == NULL){
        fp = fopen(name,"wb");
    }
    int i = 0;
    while(1){
        if(fscanf(fp,"%d",&val) == EOF){
            break;
        }
        v[i++] = val;
    }
    fclose(fp);
    return i;
}
int * dashboard::getV(){
    return v;
}
int dashboard::getSize(){
    return size;
}
void dashboard::setSize(int value){
    size = value;
}
