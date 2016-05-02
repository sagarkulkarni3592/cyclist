#include "GL/freeglut.h"
#include "GL/gl.h"

static int special = 0, play = 0, game = 0;
class controller{
    public:
        static void mouseEventHandler(int,int,int,int);
        static void keyboardEventHandler(unsigned char,int,int);
        static void specialKeyEventHandler(int,int,int);
        static void keyUp(int,int,int);
        void reset();
        int getSpecial();
        int getPlay();
        int getGame();
        void setGame(int);
};
