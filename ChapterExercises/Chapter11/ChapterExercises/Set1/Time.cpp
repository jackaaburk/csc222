#include "Time.h"
#include <sstream>
using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int totalSeconds)
    : hours(totalSeconds / 3600),
      minutes((totalSeconds % 3600) / 60),
      seconds(totalSeconds % 60) {}

string Time::to_string() const {
    stringstream ss;
    ss << hours << ":";
    if (minutes < 10) ss << "0";
    ss << minutes << ":";
    if (seconds < 10) ss << "0";
    ss << seconds;
    return ss.str();
}