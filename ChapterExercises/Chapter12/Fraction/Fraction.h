#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Fraction {
    int numerator, denominator;
    float floatvalue;
    Fraction(int n, int d);
    Fraction();
    Fraction(string fraction);
    Fraction(int n);
    string to_string();
    bool operator>(Fraction const& obj);
    bool operator==(Fraction const& obj);
    bool operator<(Fraction const& obj);
    bool operator!=(Fraction const& obj);
    bool operator>=(Fraction const& obj);
    bool operator<=(Fraction const& obj);
};

int gcd(int n, int d);
