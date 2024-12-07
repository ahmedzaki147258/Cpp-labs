#ifndef PICTURE_H
#define PICTURE_H

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    void setX(int x){ this->x = x; }
    int getY() { return y; }
    void setY(int y){ this->y = y; }
};

class Shape{
protected:
    int color;
public:
    Shape(int color){
        this->color = color;
    }

    int getColor(){
        return color;
    }

    void setColor(int newColor){
        color = newColor;
    }
};

class Line : public Shape {
public:
    Point start;
    Point end;
// public:
    Line() : start(), end(), Shape(WHITE) {}
    Line(int x1, int y1, int x2, int y2, int color) : start(x1, y1), end(x2, y2), Shape(color) {}

    void draw() {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
        setcolor(WHITE);
    }
    void move(int dx, int dy) {
        start.setX(start.getX() + dx);
        start.setY(start.getY() + dy);
        end.setX(end.getX() + dx);
        end.setY(end.getY() + dy);
    }

};

class Rect : public Shape {
public:
    Point ul; // Upper-left point
    Point lr; // Lower-right point
// public:
    Rect() : ul(), lr(), Shape(WHITE) {}
    Rect(int x1, int y1, int x2, int y2, int color) : ul(x1, y1), lr(x2, y2), Shape(color) {}

    void draw() {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
        setcolor(WHITE);
    }
    void move(int dx, int dy) {
        ul.setX(ul.getX() + dx);
        ul.setY(ul.getY() + dy);
        lr.setX(lr.getX() + dx);
        lr.setY(lr.getY() + dy);
    }
};

class Circle : public Shape {
public:
    Point center;
    int radius;

    Circle() : center(), radius(0), Shape(WHITE) {}
    Circle(int m, int n, int r, int color) : center(m, n), radius(r), Shape(color) {}

    void draw() {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
        setcolor(WHITE);
    }
    void move(int dx, int dy) {
        center.setX(center.getX() + dx);
        center.setY(center.getY() + dy);
    }
};

class Picture{
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;

public:
    Picture(){
        cNum=0;
        rNum=0;
        lNum=0;
        pCircles = nullptr;
        pRects = nullptr;
        pLines = nullptr;
    }

    void setCircles(int cn, Circle* pC) {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect* pR) {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line* pL) {
        lNum = ln;
        pLines = pL;
    }

    void paint() {
        for (int i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++) {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++) {
            pLines[i].draw();
        }
    }

    void updateColors() {
        for (int i = 0; i < cNum; i++) {
            int newColor = (pCircles[i].getColor() + 1) % 15;
            pCircles[i].setColor(newColor);
        }
        for (int i = 0; i < rNum; i++) {
            int newColor = (pRects[i].getColor() + 1) % 15;
            pRects[i].setColor(newColor);
        }
        for (int i = 0; i < lNum; i++) {
            int newColor = (pLines[i].getColor() + 1) % 15;
            pLines[i].setColor(newColor);
        }
    }
};

#endif // PICTURE_H
