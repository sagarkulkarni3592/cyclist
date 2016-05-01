#include "GL/freeglut.h"
#include "GL/gl.h"

static int v[10];
static int size = 0;
class dashboard{
    public:
        void drawDashboard();
        int readFile(char *);
        int * getV();
        int getSize();
        void setSize(int );
};
