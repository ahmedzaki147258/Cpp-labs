#include <iostream>
#include <cmath>
using namespace std;

class GeoShape{
protected:
    double x;
    double y;
public:
    GeoShape(double x, double y){ this->x=x; this->y=y; }
    void setX(double x){ this->x=x; }
    void setY(double y){ this->x=x; }
    double getX(){ return x; }
    double getY(){ return y; }
    virtual double calculateArea()=0;
};

class Rect: public GeoShape{ // protected
public:
    Rect(double x, double y): GeoShape(x,y){}
    void setX(double x){ GeoShape::setX(x); }
    void setY(double y){ GeoShape::setY(y); }
    double getX(){ return GeoShape::getX(); }
    double getY(){ return GeoShape::getX(); }
    double calculateArea(){ return x*y; }
};

class Circle: public GeoShape{ // private
public:
    Circle(double radius): GeoShape(radius,radius){}
    void setRadius(double radius){ x=radius; y=radius; }
    double getRadius(){ return x; }
    double calculateArea(){ return M_PI*x*y; }
};

class Square: public Rect{ // private
public:
    Square(double x): Rect(x, x){}
    void setSquareDim(double x){ this->x=x; this->y=x; }
    double getSquareDim(){ return x; }
    double calculateArea(){ return Rect::calculateArea(); }
};

double sumOfAreas(GeoShape* shape1, GeoShape* shape2, GeoShape* shape3){
    return shape1->calculateArea() + shape2->calculateArea() + shape3->calculateArea();
}

int main(){
    Circle c(5);
    cout << "Area of circle: " << c.calculateArea() << endl;

    Rect rect(5,8);
    cout << "Area of rectangle: " << rect.calculateArea() << endl;

    Square square(5);
    cout << "Area of square: " << square.calculateArea() << endl;

    cout << "Sum of areas: " << sumOfAreas(&c, &rect, &square) << endl;
    return 0;
}
