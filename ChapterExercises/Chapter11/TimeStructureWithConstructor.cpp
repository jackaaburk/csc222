#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;

    Time(int h, int m, double s) {
    hour = h;
    minute = m;
    second = s;
    }
    void print();
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

void Time::print() {
    cout << hour << ":" << minute << ":" << second << endl;
}

int main() {
    Time current_time(9, 14, 3);
    current_time.increment(500.0);
    current_time.print();
    return 0;
}