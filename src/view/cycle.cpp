#include "cycle.h"
#include "render.h"
#include "../controller/controller.h"
#include "dashboard.h"
#include <stdio.h>
#include "cars.h"

void cycle::drawCycle(){
    glColor3f(0.5, 0.5, 0.5);
    controller c;
    render r;
    cars cr;
    glRectf(r.getDistanceX() , -0.05, r.getDistanceX() + 0.05, 0.05);
    if(checkLimit() == 0 || cr.checkCarLimit()){
        writeToFile("scores.txt");
        c.setGame(1);
        c.reset();
    }
}
int cycle::checkLimit(){
    render r;
    if(r.getDistanceX() < -0.5 || r.getDistanceX() > -0.05){
        return 0;
    }
    return 1;
}
void cycle::writeToFile(char * name){
    dashboard d;
    render r;

    FILE *fp;
    fp = fopen(name,"w");

    int * arr = d.getV();
    int max = 0,indx = -1;
    for(int i = 0; i < d.getSize(); i++){
        if(arr[i] > max){
            max = arr[i];
            indx = i;
        }
    }
    fprintf(fp,"%d\n",max);
    if(d.getSize() < 10){
        arr[d.getSize()] = r.getScore();
        d.setSize(d.getSize() + 1);
        for(int i = 0; i < 10 && i < d.getSize(); i++){
            if(i == indx){
                continue;
            }
            fprintf(fp,"%d\n",arr[i]);
        }
    }
    else{
        fprintf(fp,"%d\n",r.getScore());
        for(int i = 0; i < 9 && i < d.getSize(); i++){
            if(i == indx){
                continue;
            }
            fprintf(fp,"%d\n",arr[i]);
        }
    }
    fclose(fp);
}
