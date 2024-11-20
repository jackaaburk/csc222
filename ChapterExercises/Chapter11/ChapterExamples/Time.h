#include <string>
#include <vector>
struct Time {
    int hour, minute;
    double second;

    Time(int h, int m, double s) {
    hour = h;
    minute = m;
    second = s;
    }

    Time(double secs);

    void print();
    void increment(double secs);
    double convert_to_seconds() const;
    bool after(const Time& t2) const;
    Time add(const Time& t2) const;
};
