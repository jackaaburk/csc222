#define TIME_H

#include <string>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time();
    Time(int totalSeconds);
    Time(int h, int m, int s = 0);
    string to_string() const;
};
