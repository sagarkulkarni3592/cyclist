#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>

static float distanceX = -0.45, distanceY = -1.0;
static int score = 0;
class render{
    public:
        static void renderFunction();
        void drawBitmapText(char *s,float x,float y,float z);
        float getDistanceX();
        float getDistanceY();
        void setDistanceX(float);
        void setDistanceY(float);
        int getScore();
        void setScore(int);
        void putScores();
        void playGame();
};
