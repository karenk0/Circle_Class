#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "Circle.h"
#include "Point.h"
using namespace std;


bool belongs_circle(const Point& p, const Circle& object) {
    double d = sqrt(pow(object.get_x_coord() - p.get_x_coord_p(), 2) +
        pow(object.get_y_coord() - p.get_y_coord_p(), 2)
    );
    if (d <= object.getRadius()) {
        return true;
    }
    else {
        return false;
    }
}

double Distance_of_2_Circle(const Circle& object1, const Circle& object2) {
    return sqrt(pow(object1.get_x_coord() - object2.get_x_coord(), 2) +
        pow(object1.get_y_coord() - object2.get_y_coord(), 2)
    );
}

int united_points(const Circle& object1, const Circle& object2) {
    double distance_of_centers = Distance_of_2_Circle(object1, object2);
    double r1 = object1.getRadius();
    double r2 = object2.getRadius();
    if (distance_of_centers > r1 + r2 ||
        distance_of_centers < fabs(r1 - r2)) {
        return 0;
    }
    else if (distance_of_centers == r1 + r2 ||
        distance_of_centers == fabs(r1 - r2)) {
        return 1;
    }
    else {
        return 2;
    }
}

double Circle_area(const Circle& object) {
    return  object.r * object.r * 3.14159; //compiler doesnt recognize Pi, so i use value instead
}
double Circle_Length(const Circle& object) {
    return  2 * object.getRadius() * 3.14159;
}

void move_in_x(double x1, Circle& object) {
    double x_now = object.get_x_coord();
    x_now = x_now + x1;
    if (x_now - object.getRadius() > 0) {
        object.getPoint().set_x_coord_p(x_now);
    }
    else {
        throw invalid_argument(" X coordinate was out of range");
    }
}

void move_in_y(double y1, Circle& object) {
    double y_now = object.get_y_coord();
    y_now = y_now + y1;
    if (y_now - object.getRadius() > 0) {
        object.getPoint().set_y_coord_p(y_now);
    }
    else {
        throw invalid_argument(" Y coordinate was out of range");
    }
}

void increase_area_of_circle(double k, Circle& object) {
    if (k > 0) {
        double radius_now = object.getRadius();
        radius_now *= sqrt(k);
        if ((object.get_x_coord() - radius_now) > 0 && (object.get_y_coord() - radius_now) > 0) {
            object.setRadius(radius_now);
        }
        else {
            throw invalid_argument(" k was out of range");
        }
    }
}


Point& operator++(Point& p) { //prefix ++
    double x = p.get_x_coord_p() + 1;
    double y = p.get_y_coord_p() + 1;
    p.set_xy_p(x, y);
    return p;
};

Point& operator--(Point& p) { // prefix --
    double x = p.get_x_coord_p() - 1;
    double y = p.get_y_coord_p() - 1;
    p.set_xy_p(x, y);
    return p;
};

Point operator++(Point& p, int d) { //postfix ++
    Point temp{ p };
    double x = p.get_x_coord_p() + 1;
    double y = p.get_y_coord_p() + 1;
    p.set_xy_p(x, y);
    return temp;
};

Point operator--(Point& p, int d) {//postfix --
    Point temp{ p };
    double x = p.get_x_coord_p() - 1;
    double y = p.get_y_coord_p() - 1;
    p.set_xy_p(x, y);
    return temp;
};


int main(){
    
    try {
        Circle circle_object(4, 5);
        Circle circle_object2(4, 3);
        Circle circle_object3;

        cout << "Enter the coordinants of cirlce in the form of - (x,y,r)\n";
        cin >> circle_object3;

        cout << "Circle class instance count: " << Circle::_count << endl;
        cout << circle_object3.info() << endl << endl;

        circle_object3.setRadius(2).setPoint(4, 4); //cascade call
        cout << circle_object3.info() << endl << endl;

        cout << "united points: " << united_points(circle_object, circle_object2) << endl;
        move_in_x(5, circle_object);
        move_in_y(-1, circle_object);
        cout << circle_object.info() << endl << endl;
        cout << "Distance of centers between 2 circles: " << Distance_of_2_Circle(circle_object, circle_object2) << endl;
        cout << "2nd circle area: " << Circle_area(circle_object2) << endl;
        cout << "2nd circle length: " << Circle_Length(circle_object2) << endl << endl << endl;

        Point p0;
        cout << "Enter point in this format - (x,y):\n";
        cin >> p0;
        cout << endl;
        cout << p0;
        cout << "\nResult of ++p0 : ";
        ++p0;
        cout << p0 << endl;

        Point p1(4, 3);
        cout << "\np1 point: ";
        cout << p1;
        Point p2(4, 3.99);
        Point p3(4, -10);
        cout << "\n\n\n\nx = 4 and y = 3 belongs circle 2 (?): " << belongs_circle(p1, circle_object2) << endl;
        cout << "x = 4 and y = 3.99 belongs circle 2 (?): " << belongs_circle(p2, circle_object2) << endl;
        cout << "x = 4 and y = -10 belongs circle 2 (?): " << belongs_circle(p3, circle_object2) << endl;
        increase_area_of_circle(1.5, circle_object2);
        cout << circle_object2.info() << endl << endl;
        increase_area_of_circle(250, circle_object2);
        cout << circle_object2.info() << endl << endl;
    }
    catch (invalid_argument& e) {
        cerr << "\nException while realising:   " << e.what() << endl;
    }
}