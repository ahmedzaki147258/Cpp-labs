#include <iostream>
#include "graphics.h"
#include "./include/Picture.h"
using namespace std;

int main(){
    Picture myPic(15);  
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, "");

    myPic.addShape(new Circle(50, 50, 50, 1));
    myPic.addShape(new Circle(200, 100, 100, 2));
    myPic.addShape(new Circle(420, 50, 30, 3));
    myPic.addShape(new Circle(300, 300, 70, 4));
    myPic.addShape(new Circle(150, 400, 50, 5));

    myPic.addShape(new Rect(30, 40, 170, 100, 6));
    myPic.addShape(new Rect(420, 50, 500, 300, 7));
    myPic.addShape(new Rect(200, 200, 300, 300, 8));
    myPic.addShape(new Rect(100, 100, 250, 200, 9));

    myPic.addShape(new Line(420, 50, 300, 300, 10));
    myPic.addShape(new Line(40, 500, 500, 400, 11));
    myPic.addShape(new Line(150, 150, 450, 150, 12));
    myPic.addShape(new Line(250, 350, 350, 450, 13));
    myPic.addShape(new Line(50, 50, 500, 500, 14));

    while (!kbhit()) {
        cleardevice();
        myPic.paint();
        delay(700);
        myPic.updateColors();
    }
    
    closegraph();
    return 0;
}

// g++ main.cpp -lSDL_bgi -lSDL2
// ./a.out
