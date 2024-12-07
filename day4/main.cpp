#include <iostream>
#include "graphics.h"
#include "./include/Picture.h"
using namespace std;

int main(){
    Picture myPic;  
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, ""); 

    srand(time(0)); // Seed for random number generation

    Circle cArr[3] = { Circle(50, 50, 50, 1), Circle(200, 100, 100, 2), Circle(420, 50, 30, 3) };
    Rect rArr[2] = { Rect(30, 40, 170, 100, 4), Rect(420, 50, 500, 300, 5) };
    Line lArr[2] = { Line(420, 50, 300, 300, 12), Line(40, 500, 500, 400, 14) };

    myPic.setCircles(sizeof(cArr)/sizeof(cArr[0]), cArr);
    myPic.setRects(sizeof(rArr)/sizeof(rArr[0]), rArr);
    myPic.setLines(sizeof(lArr)/sizeof(lArr[0]), lArr);

    float timeStep = 0;
    while (!kbhit()) {
        for (int i = 0; i < 3; i++) {
            float dx = 5;
            float dy = 20 * sin(timeStep + i);
            cArr[i].move(dx, dy);
        }

        for (int i = 0; i < 2; i++) {
            float dx = 5;
            float dy = 15 * sin(timeStep + i);
            rArr[i].move(dx, dy);
        }

        for (int i = 0; i < 2; i++) {
            float dx = 5;
            float dy = 10 * sin(timeStep + i);
            lArr[i].move(dx, dy);
        }

        timeStep += 0.1;
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

// BLACK                   0
// BLUE                    1
// GREEN                   2
// CYAN                    3   
// RED                     4
// MAGENTA                 5
// BROWN                   6 
// LIGHTGRAY               7 
// DARKGRAY                8
// LIGHTBLUE               9
// LIGHTGREEN             10
// LIGHTCYAN              11
// LIGHTRED               12
// LIGHTMAGENTA           13
// YELLOW                 14
// WHITE                  15

    // Circle cArr[] = { 
    //     Circle(50, 50, 50, 1), 
    //     Circle(200, 100, 100, 2), 
    //     Circle(420, 50, 30, 3), 
    //     Circle(300, 300, 70, 4), 
    //     Circle(150, 400, 50, 5) 
    // };
    // Rect rArr[] = { 
    //     Rect(30, 40, 170, 100, 6), 
    //     Rect(420, 50, 500, 300, 7), 
    //     Rect(200, 200, 300, 300, 8), 
    //     Rect(100, 100, 250, 200, 9) 
    // };
    // Line lArr[] = { 
    //     Line(420, 50, 300, 300, 10), 
    //     Line(40, 500, 500, 400, 11), 
    //     Line(150, 150, 450, 150, 12), 
    //     Line(250, 350, 350, 450, 13), 
    //     Line(50, 50, 500, 500, 14) 
    // };