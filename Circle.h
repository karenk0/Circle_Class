#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <iostream>
using namespace std;

class Circle {
    friend double Circle_area(const Circle& object); 
    friend ostream& operator<<(ostream& , const Circle&);
    friend istream& operator>>(istream& , Circle& );
public:
    Circle(double, double, double);
    Circle(double, double);
    Circle(double);
    Circle();
    ~Circle();

    double get_y_coord() const;
    double get_x_coord() const;
    double getRadius() const;
    size_t getCount() const;
    Point getPoint() const;
    Circle& setRadius(double);
    Circle& setPoint(double, double);
    Circle& setCircle(double, double, double);

    string info() const {
        ostringstream output;
        output << "radius: " << r << "\nX coordinate: " << xy.get_x_coord_p()
            << "\nY coordinate: " << xy.get_y_coord_p();
        return output.str();
    }
    static size_t _count;
private:
    double r;
    Point xy;
};

#endif