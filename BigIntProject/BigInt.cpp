#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;


BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& BigInt2) const {
    return ((digits == BigInt2.digits) && (negative == BigInt2.negative));
}

bool BigInt::operator>(const BigInt& BigInt2) const {
    if ((negative == true) && (BigInt2.negative == false)) {
        return false;
}
    else if ((negative == false) && (BigInt2.negative == true)) {
        return true;
}
    if (digits.length() > BigInt2.digits.length()) {
	return true;
}
    else if (negative == false && BigInt2.negative == false) {
        for(int i = 0; i < digits.length(); i++) {
	    if(digits[i] > BigInt2.digits[i]) {
	        return true;
}
}
}
    else if (negative == true && BigInt2.negative == true) {
        for(int i = 0; i < digits.length(); i++) {
            if(digits[i] < BigInt2.digits[i]) {
                return true;
}
}
}
}

bool BigInt::operator<(const BigInt& BigInt2) const {

}
bool BigInt::operator>=(const BigInt& BigInt2) const {

}
bool BigInt::operator<=(const BigInt& BigInt2) const {

}
bool BigInt::operator!=(const BigInt& BigInt2) const {
    
}
