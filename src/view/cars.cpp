#include "cars.h"
#include "render.h"

void cars::drawCars(){
    render r;
    glColor3f(1.0,0.0,0.0);
    drawCar();

    for(int j = 0; j < 4; j++){
        for(float i = 1.0; i >= -1.0; i--){
            glRectf(x[j] - (2 * x[j]), 0.5 + ydist[j] - 0.1, x[j] - (2 * x[j]) + 0.05, 0.5 + ydist[j]);
        }
    }
}
void cars::drawCar(){
    render r;
    for(int i = 0; i < 4; i++){
        if(choose[i] == 0){
            x[i] = random();
            choose[i] = 1;
        }
        glRectf(x[i], ydist[i], x[i] + 0.05, ydist[i] + 0.1);
        if(ydist[i] < -1.0){
            choose[i] = 0;
            ydist[i] = 1.0;
        }
    }
}
int cars::checkCarLimit(){
    render r;
    for(int i = 0; i < 4; i++){
        if(x[i] <= r.getDistanceX() + 0.05 && x[i] >= r.getDistanceX()){
            if(ydist[i] <= 0.05 && ydist[i] >= -0.05){
                return 1;
            }
        }
        else if(x[i] + 0.05 >= r.getDistanceX() && x[i] + 0.05 <= r.getDistanceX() + 0.05){
            if(ydist[i] <= 0.05 && ydist[i] >= -0.05){
                return 1;
            }
        }
    }
    return 0;
}
float cars::random(){
    float r = -0.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/0.45));
    return r;
}
float cars::getyDist(int index){
    return ydist[index];
}
void cars::setyDist(float value, int index){
    ydist[index] = value;
}
void cars::paramsReset(){
    choose[4] = {0};
    ydist[0] = 1.0;
    ydist[1] = 1.5;
    ydist[2] = 2.0;
    ydist[3] = 2.5;
    x[0] = -0.10;
    x[1] = -0.25;
    x[3] = -0.35;
    x[4] = -0.45;
}
