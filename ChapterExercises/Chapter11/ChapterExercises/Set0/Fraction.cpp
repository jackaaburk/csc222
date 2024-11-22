#include <iostream>
using namespace std;

struct Fraction {
    int numerator, denominator;
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }
    Fraction() {
        numerator = 0;
        denominator = 1;
    }
    void print();
    int times(int n, int d);

};

void Fraction::print() {
    Fraction fraction = *this;
    cout << fraction.numerator << "/" << fraction.denominator << endl;
}

int Fraction::times(int n, int d) {
    numerator *= n;
    denominator *= d;
    return numerator, denominator;
}


int main() {
    Fraction current_fraction(1, 2);
    Fraction parameterless_fraction;
    current_fraction.print();
    parameterless_fraction.print();
    current_fraction.times(10, 2);
    current_fraction.print();



    return 0;
}