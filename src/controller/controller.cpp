#include "controller.h"
#include "../view/render.h"
#include <iostream>
#include "../view/cars.h"
using namespace std;
render r;
cars cr;
void controller::reset(){
    r.setDistanceX(-0.45);
    r.setDistanceY(-1.0);
    r.setLast(r.getScore());
    r.setScore(0);
    special = 0;
    play = 0;
    cr.paramsReset();
}
void controller::keyboardEventHandler(unsigned char key,int x, int y){
    if(key == ' '){
        play = 1;
    }
    if(key == 'r'){
        game = 1;
    }
}
void controller::specialKeyEventHandler(int key,int x,int y){
    //cout << score << " ";
    if(key == GLUT_KEY_UP){
        special = 1;
    }
    else if(key == GLUT_KEY_RIGHT && special == 1){
        //special = 2;
        r.setDistanceX(r.getDistanceX() + 0.05);
    }
    else if(key == GLUT_KEY_LEFT && special == 1){
        //special = 3;
        r.setDistanceX(r.getDistanceX() - 0.05);
    }
    else if(key == GLUT_KEY_RIGHT){
        //special = 2;
        r.setDistanceX(r.getDistanceX() + 0.05);
    }
    else if(key == GLUT_KEY_LEFT){
        //special = 3;
        r.setDistanceX(r.getDistanceX() - 0.05);
    }
    else if(GLUT_KEY_DOWN){
        special = 0;
    }
}
void controller::keyUp(int key,int x,int y){
    if(key == GLUT_KEY_UP){
        special = 0;
    }
}
int controller::getSpecial(){
    return special;
}
int controller::getPlay(){
    return play;
}
int controller::getGame(){
    return game;
}
void controller::setGame(int value){
    game = value;
}
