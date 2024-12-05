#include <iostream>
#include "graphics.h"
#include "./include/Picture.h"

using namespace std;

int main(){
    Picture myPic;  
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, ""); 

    Circle cArr[3] = { Circle(50, 50, 50), Circle(200, 100, 100), Circle(420, 50, 30) };
    Rect rArr[2] = { Rect(30, 40, 170, 100), Rect(420, 50, 500, 300) };
    Line lArr[2] = { Line(420, 50, 300, 300), Line(40, 500, 500, 400) };

    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();
    getch();
    closegraph();
    
    return 0;
}
