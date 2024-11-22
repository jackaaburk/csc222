#include <iostream>
#include "Time.h"
using namespace std;

Time::Time(double secs) {
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}

void Time::to_string() {
    cout << hour << ":" << minute << ":" << second << endl;
}