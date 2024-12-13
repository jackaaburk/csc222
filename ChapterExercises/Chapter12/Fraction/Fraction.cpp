#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(int n, int d) {
	numerator = n;
	denominator = d;
	int gcf = gcd(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
	floatvalue = numerator/denominator;
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
	floatvalue = 0;
}

Fraction::Fraction(string s) {
	string slash = "/", s2 = s;
	int slashpos = s.find(slash);
	if (slashpos == -1) { 
		numerator = stoi(s);
		denominator = 1;
		floatvalue = numerator;
}
	else {
		numerator = stoi (s.erase(slashpos));
		denominator = stoi (s2.erase(0,slashpos+1));
		int gcf = gcd(numerator, denominator);
		numerator /= gcf;
		denominator /= gcf;
		floatvalue = numerator/denominator;
}
}


Fraction::Fraction(int n) {
	numerator = n;
	denominator = 1;
	floatvalue = n;
}

string Fraction::to_string() {
	stringstream oss;
	oss << ::to_string(numerator) << "/" << ::to_string(denominator);
	if (denominator == 1) {
		return ::to_string(numerator);
}
	return oss.str();
}

bool Fraction::operator>(Fraction const& obj) {

}

bool Fraction::operator<(Fraction const& obj) {

}

bool Fraction::operator==(Fraction const& obj) {

}

bool Fraction::operator!=(Fraction const& obj) {

}

bool Fraction::operator>=(Fraction const& obj) {

}

bool Fraction::operator<=(Fraction const& obj) {

}



int gcd(int n, int d) {
    if (n == 0)
        return d;
    return gcd(d % n, n);
}
