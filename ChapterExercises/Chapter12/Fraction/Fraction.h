#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Fraction {
    int numerator, denominator;
    Fraction(int n, int d);
    Fraction();
    Fraction(string fraction);
    string to_string();
    int gcd(int n, int d);
};

