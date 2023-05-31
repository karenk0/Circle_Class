#include <iostream>
#include <stdexcept>
#include <sstream>
#include <math.h>
#include "Point.h"
#include "Circle.h"
#include <iomanip>
using namespace std;

size_t Circle::_count = 0;

Circle::Circle():Circle{ 1, 3, 3 } {}
Circle::Circle(double radius) : Circle{ radius , 3, 3 } {}
Circle::Circle(double x_coord, double y_coord) : Circle{ 1 , x_coord, y_coord } {}
Circle::Circle(double radius, double x_coord, double y_coord) {
    setPoint(x_coord, y_coord);
    setRadius(radius);
    _count++;
}
Circle::~Circle() {
    cout << "\nDestructor runs";
    _count--;
}

Circle& Circle::setRadius(double radius) {
    if ((radius > 0) && ((get_x_coord() - radius) > 0) && ((get_y_coord() - radius) > 0)) {
        r = radius;
    }
    else {
        throw invalid_argument(" Radius was out of range");
    }
    return *this;
}
Circle& Circle::setPoint(double x_coord, double y_coord)
{
    if ( ((x_coord - r) > 0) && ((y_coord - r) > 0) ) {
        xy.set_xy_p(x_coord, y_coord);
    }
    else {
        throw invalid_argument(" X or Y were out of range");
    }
    return *this;
}

Circle& Circle::setCircle(double x_coord, double y_coord, double rad)
{
    if (((x_coord - rad) > 0) && ((y_coord - rad) > 0) && rad > 0) {
        xy.set_xy_p(x_coord, y_coord);
        r = rad;
    }
    else {
        throw invalid_argument(" X,Y or R were out of range");
    }
    return *this;
}

size_t Circle::getCount() const {
    return _count;
}
double  Circle::getRadius() const {
    return r;
}
Point Circle::getPoint() const {
    return xy;
}
double  Circle::get_x_coord() const {
    return xy.get_x_coord_p();
}
double  Circle::get_y_coord() const {
    return xy.get_y_coord_p();
}

ostream& operator<<(ostream& output, const Circle& c) {
    output << "Radius: " << c.getRadius() <<
           "\nX coordinate: " << c.get_x_coord() <<
           "\nY coordinate: " << c.get_y_coord();
    return output;
};

istream& operator>>(istream& input, Circle& c) {
    double x, y, r;
    input.ignore(); //skip (
    input >> setw(1) >> x;
    input.ignore(); //slip ,
    input >> setw(1) >> y;
    input.ignore();//skip ,
    input >> setw(1) >> r;
    input.ignore(); //skip )
    c.setCircle(x, y, r);
    return input;
};
