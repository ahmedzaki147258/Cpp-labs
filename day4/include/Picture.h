#ifndef PICTURE_H
#define PICTURE_H

class Point {
private:
    int x, y;
public:
    Point(){ x=0; y=0; }
    Point(int x, int y){ this->x = x; this->y = y; }

    int getX() { return x; }
    void setX(int x){ this->x = x; }
    int getY() { return y; }
    void setY(int y){ this->y = y; }
};

class Shape{
protected:
    int color;
public:
    Shape(int color){ this->color = color; }
    int getColor(){ return color; }
    void setColor(int color){ this->color = color; }
    virtual void draw()=0;
};

class Line : public Shape {
protected:
    Point start; // Composition
    Point end;   // Composition
public:
    Line() : start(), end(), Shape(WHITE) {}
    Line(int x1, int y1, int x2, int y2, int color) : start(x1, y1), end(x2, y2), Shape(color) {}

    void draw() {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
        setcolor(WHITE);
    }
};

class Rect : public Shape {
protected:
    Point ul; // Upper-left point  // Composition
    Point lr; // Lower-right point // Composition
public:
    Rect() : ul(), lr(), Shape(WHITE) {}
    Rect(int x1, int y1, int x2, int y2, int color) : ul(x1, y1), lr(x2, y2), Shape(color) {}

    void draw() {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
        setcolor(WHITE);
    }
};

class Circle : public Shape {
public:
    Point center;  // Composition
    int radius;

    Circle() : center(), Shape(WHITE) { radius = 0; }
    Circle(int m, int n, int r, int color) : center(m, n), Shape(color) { radius = r; }

    void draw() {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
        setcolor(WHITE);
    }
};

class Picture{
private:
    Shape** shapes; // Aggregation
    int size, capacity;

public:
    Picture(int capacity){
        size = 0;
        shapes = new Shape*[capacity];
    }

    void addShape(Shape* shape) {
        shapes[size] = shape;
        size++;
    }
    void paint() {
        for (int i = 0; i < size; i++) {
            shapes[i]->draw();
        }
    }

    void updateColors() {
        for (int i = 0; i < size; i++) {
            int newColor = (shapes[i]->getColor() + 1) % 15;
            shapes[i]->setColor(newColor);
        }
    }

    ~Picture() {
        for (int i = 0; i < size; i++) {
            delete shapes[i];
        }
        delete[] shapes;
    }
};

#endif // PICTURE_H
