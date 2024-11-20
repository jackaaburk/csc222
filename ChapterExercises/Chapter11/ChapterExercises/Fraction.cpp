#include <iostream>
using namespace std;

struct Fraction {
    int numerator, denominator;
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }
    void print();

};

void Fraction::print()
{
    Fraction fraction = *this;
    cout << fraction.numerator << "/" << fraction.denominator << endl;
}

int main() {
    Fraction current_fraction = {1, 2};
    current_fraction.print();



    return 0;
}