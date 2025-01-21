#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

string increment_digit_string(const string &digit_string) {
    string digits = digit_string;
    int pos = digits.size() - 1;
    char next_digit = digits[pos] + 1;

    while (next_digit > '9' && pos >= 0) {
        digits[pos] = '0';
        next_digit = digits[--pos] + 1;
    }

    if (pos >= 0)
        digits[pos] = next_digit;
    else
        digits = "1" + digits;

    return digits;
}

string sum_common_len_digit_strs(const string &s1, const string &s2) {
    char digit_sum, carry = 0;
    string sum = s1;

    for (int i = s1.size() - 1; i >= 0; i--) {
        digit_sum = to_num(s1[i]) + to_num(s2[i]) + carry;
        sum[i] = digit_to_char(digit_sum % 10);
        carry = digit_sum > 9 ? 1 : 0;
    }

    return carry ? "c+" + sum : sum;
}



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
    if ((digits.length() > BigInt2.digits.length()) && (negative == false)){
	    return true;
}
    if ((digits.length() > BigInt2.digits.length()) && (negative == true)){
	    return false;
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
    return !((this->operator==(BigInt2)) || (this->operator>(BigInt2)));
}

bool BigInt::operator!=(const BigInt& BigInt2) const {
    return !(this->operator==(BigInt2));
}

bool BigInt::operator>=(const BigInt& BigInt2) const {
    return ((this->operator==(BigInt2)) || (this->operator>(BigInt2)));
}

bool BigInt::operator<=(const BigInt& BigInt2) const {
    return ((this->operator==(BigInt2)) || (this->operator<(BigInt2)));
}

BigInt BigInt::operator+(const BigInt& BigInt2) const{
    return 0;
}
