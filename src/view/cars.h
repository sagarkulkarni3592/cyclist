#include "GL/freeglut.h"
#include "GL/gl.h"

static int choose[4] = {0};
static float ydist[4] = {1.0, 1.5, 2.0, 2.5};
static float x[4] = {-0.10, -0.25, -0.35, -0.45};
class cars{
    public:
        void drawCars();
        void drawCar();
        float random();
        void setyDist(float ,int);
        float getyDist(int);
        int checkCarLimit();
        void paramsReset();
};
