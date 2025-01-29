#include <iostream>
#include <string>
#include "BigInt.h"
#define to_num(c) (c-'0')
#define digit_to_char(d) (d+'0')
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

BigInt::BigInt() {
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i) {
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n) {
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const {
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
    return false;
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

BigInt BigInt::operator+(const BigInt& BigInt2) const {
    if ((*this).digits.size() == BigInt2.digits.size()) {
        string raw_sum = sum_common_len_digit_strs((*this).digits, BigInt2.digits);
        if (raw_sum[0] == 'c')
            return BigInt("1" + raw_sum.substr(2));
        return BigInt(raw_sum);
}
        
    const BigInt *longer;
    const BigInt *shorter;
    int common, extra;
    string summed_common_digits, leading_digits;

    if ((*this).digits.size() > BigInt2.digits.size()) {
        longer = this;
        shorter = &BigInt2;
}
        else {
        longer = &BigInt2;
        shorter = this;
};

    common = shorter->digits.size();
    extra = longer->digits.size() - common;
    summed_common_digits = sum_common_len_digit_strs(
       shorter->digits, 
       longer->digits.substr(extra)
    );
    leading_digits = longer->digits.substr(0, extra);

    if (summed_common_digits[0] != 'c')
        return BigInt(leading_digits + summed_common_digits);

    return BigInt(increment_digit_string(leading_digits) +
                  summed_common_digits.substr(2));
}

BigInt BigInt::operator-(const BigInt& BigInt2) const {
    if (this->negative != BigInt2.negative) {
        BigInt temp = BigInt2;
        temp.negative = !BigInt2.negative;
        return *this + temp;
}

    if (*this < BigInt2) {
        BigInt result = BigInt2 - *this;
        result.negative = !this->negative;
        return result;
}

    string result(digits.size(), '0');
    char borrow = 0;
    int this_len = digits.size(), other_len = BigInt2.digits.size();

    for (int i = 0; i < this_len; ++i) {
        int digit1 = to_num(digits[this_len - 1 - i]) - borrow;
        int digit2 = (i < other_len) ? to_num(BigInt2.digits[other_len - 1 - i]) : 0;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
} 
        else {
            borrow = 0;
}

        result[this_len - 1 - i] = digit_to_char(digit1 - digit2);
}

   int pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        result = result.substr(pos);
}
    else {
        result = "0";
}

    return BigInt(this->negative ? "-" + result : result);
}

BigInt BigInt::operator*(const BigInt& BigInt2) const {
    bool productnegative = (this->negative ^ BigInt2.negative); 
    int len1 = this->digits.size();
    int len2 = BigInt2.digits.size();

        string result(len1 + len2, '0');


    for (int i = len1 - 1; i >= 0; --i) {
        int carry = 0;
        int digit1 = to_num(this->digits[i]);
        for (int j = len2 - 1; j >= 0; --j) {
            int digit2 = to_num(BigInt2.digits[j]);
            int temp = to_num(result[i + j + 1]) + digit1 * digit2 + carry;
            result[i + j + 1] = digit_to_char(temp % 10);
            carry = temp / 10;
}
        result[i] = digit_to_char(to_num(result[i]) + carry);
}

    int startpos = result.find_first_not_of('0');
    if (startpos != std::string::npos) {
        result = result.substr(startpos);
}
    else {
        result = "0";
}

    if (productnegative && result != "0") {
        result = "-" + result;
}

    return BigInt(result);
}

