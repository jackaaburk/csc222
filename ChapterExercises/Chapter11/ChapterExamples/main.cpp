#include <iostream>
#include "Time.h"
using namespace std;

struct Point {
    double x, y;
    Point operator+(const Point& other);
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

Point Point::operator+(const Point& other) {
    return Point(x + other.x, y + other.y);
}

int main() {
    Time current_time = {9, 14, 30.0};
    current_time.print();
    current_time.increment(500.0);
    current_time.print();
    cout << current_time.convert_to_seconds() << endl;
    Time done_time = {10, 14, 31.0};
    if (done_time.after(current_time)) {
        cout << "The bread will be done after it starts." << endl;
    }

    Time elapsed_time(3661.5);
    elapsed_time.print();
    Point p1 = Point(3, 4);
    Point p2 = Point(2, 1);
    Point p3 = p1 + p2;
    cout << "p3: (" << p3.x << ", " << p3.y << ")" << endl;
    return 0;
}