#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point {
    friend ostream& operator<<(ostream &, const Point &);
    friend istream& operator>>(istream &, Point &);
public:
    Point(double, double);
    Point();
    double get_y_coord_p() const;
    double get_x_coord_p() const;
    void set_x_coord_p(double);
    void set_y_coord_p(double);
    void set_xy_p(double, double);
    
    //Point &operator++(); //prototype for prefix
    //Point &operator--(); //prototype for prefix
    //Point operator++(int); //prototype for postfix
    //Point operator--(int); //prototype for prefix
private:
    double x, y;
};
#endif
