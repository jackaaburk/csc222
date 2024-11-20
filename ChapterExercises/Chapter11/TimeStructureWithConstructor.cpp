#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;

    Time(int h, int m, double s) {
        hour = h;
        minute = m;
        second = s;
        cout << "Constructor 1: Time(" << h << ", " << m << ", " << s << ")" << endl;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
        cout << "Constructor 2: Time(" << h << ", " << m << ", " << s << ")" << endl;
    }

    void print() {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    void increment(double secs);
};

void Time::increment(double secs) {
    second += secs;
    int additionalMinutes = static_cast<int>(second / 60);
    second -= static_cast<int>(second / 60) * 60;
    minute += additionalMinutes;
    int additionalHours = minute / 60;
    minute %= 60;
    hour += additionalHours;
}

int main() {
    Time current_time(9, 14, 3); 
    Time another_time(10, 20, 3.5);
    current_time.increment(500.0);
    current_time.print();

    return 0;
}