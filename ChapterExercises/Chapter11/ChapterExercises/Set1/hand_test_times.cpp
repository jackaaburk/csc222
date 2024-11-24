#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

Time::() : hours(0), minutes(0), seconds(0) {}

Time::Time(int totalSeconds) {
    hours=(totalSeconds / 3600);
    minutes=((totalSeconds % 3600) / 60);
    seconds=(totalSeconds % 60);
}

ostream& operator<<(ostream& os, const Time& tm) {
    os << tm.hours << ':' << tm.minutes << ':' << tm.seconds;
}

int main() {
    Time t(3600 * 4 + 60 * 11 + 22);
    cout << "Time t is: " << t << endl;

    return 0;
}
