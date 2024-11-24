#define TIME_H

#include <string>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time();
    Time(int totalSeconds);
    string to_string() const;
};
