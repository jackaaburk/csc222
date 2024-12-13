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
    bool operator>(Fraction const& fraction2);
    bool operator==(Fraction const& fraction2);
    bool operator<(Fraction const& fraction2);
    bool operator!=(Fraction const& fraction2);
    bool operator>=(Fraction const& fraction2);
    bool operator<=(Fraction const& fraction2);
};

int gcd(int n, int d);
