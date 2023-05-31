#include "Point.h"
#include <iomanip>

using namespace std;

Point::Point() : Point{ 3, 3 } {}
Point::Point(double x_coord, double y_coord) {
    set_xy_p(x_coord, y_coord);
}

void Point::set_xy_p(double x_coord, double y_coord) {
    set_x_coord_p(x_coord);
    set_y_coord_p(y_coord);
}
void Point::set_x_coord_p(double x_coord) {
    x = x_coord;
}
void Point::set_y_coord_p(double y_coord) {
    y = y_coord;
}
double Point::get_x_coord_p() const {
    return x;
}
double Point::get_y_coord_p() const {
    return y;
}

/*
Point& Point::operator++() { //prefix ++
    x += 1;
    y += 1;
    return *this;
};

Point& Point::operator--() { // prefix --
    x -= 1;
    y -= 1;
    return *this;
}; 

Point Point:: operator++(int){ //postfix ++
    Point temp{ *this };
    x += 1;
    y += 1;
    return temp;
};

Point Point::operator--(int) {//postfix --
    Point temp{ *this };
    x -= 1;
    y -= 1;
    return temp;
}; 
*/

ostream& operator<<(ostream& output, const Point& p) {
    output << "\nX coordinate: " << p.get_x_coord_p()
        << "\nY coordinate: " << p.get_y_coord_p();
    return output;
};

istream& operator>>(istream& input, Point& p) {
    input.ignore(); //skip (
    input >> setw(1) >> p.x;
    input.ignore(); // skip ,
    input >> setw(1) >> p.y;
    input.ignore(); // skip )
    return input;
};