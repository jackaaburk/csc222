#include "Time.h"
#include <sstream>
using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int totalSeconds) {
      hours=(totalSeconds / 3600);
      minutes=((totalSeconds % 3600) / 60);
      seconds=(totalSeconds % 60);
 }

Time::Time(int h, int m, int s) {
      hours = h;
      minutes = m;
      seconds = s;
}

Time::Time operator+(Time const& obj) {
      Time added_time;
      added_time.hours = hours + obj.hours;
      added_time.minutes = minutes + obj.minutes;
      added_time.seconds = seconds + obj.seconds;
      return added_time;
}

string Time::to_string() const {
    stringstream ss;
    ss << hours << ":";
    if (minutes < 10) ss << "0";
    ss << minutes << ":";
    if (seconds < 10) ss << "0";
    ss << seconds;
    return ss.str();
}
