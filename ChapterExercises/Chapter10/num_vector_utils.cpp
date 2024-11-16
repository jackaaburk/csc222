#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

string render_num_vector(const vector<int>& vect) {
    string s = "", ss;
    for (int i = 0; i < vect.size(); i++){
	s += to_string(vect[i]) + " ";
}
    ss = s.substr(0, s.size()-1);
    return ss;
}

int num_vector_sum(const vector<int>& vect) {
    int s = 0;
    for (int i = 0; i < vect.size(); i++){
        s += vect[i];
}
    return s;
}

int num_vector_product(const vector<int>& vect) {
    int s = vect[0];
    for (int i = 1; i < vect.size(); i++){
        s *= vect[i];
}
    return s;
}

vector<int> only_evens(const vector<int>& vect) {
    vector<int> s;
    int check;
    for (int i = 0; i < vect.size(); i++){
    check = vect[i] % 2;
    if (check == 0){    
	s.push_back(vect[i]);
}
}
    return s;
}

vector<int> only_odds(const vector<int>& vect) {
    vector<int> s;
    int check;
    for (int i = 0; i < vect.size(); i++){
    check = vect[i] % 2;
    if (check != 0){    
	s.push_back(vect[i]);
}
}
    return s;
}

vector<int> nums_between(const vector<int>& vect, int num1, int num2) {
    vector<int> s;
    int check;
    for (int i = 0; i < vect.size(); i++){
    check = vect[i] >= num1 and vect[i] <= num2;
    if (check == 1){    
	s.push_back(vect[i]);
}
}
    return s;
}

double num_vector_mean(const vector<int>& vect) {
    double s = 0;
    for (int i = 0; i < vect.size(); i++){
        s += vect[i];
}
    s /= vect.size();
    return s;
}

double num_vector_median(const vector<int>& vect) {
    int s = 0,ss,dex,num1,num2,num3;
    float medi;
    s+= vect.size();
    ss = s % 2;
    if (ss == 0){
	dex = vect.size()/2;
	num1 = vect[dex-1];
	num2 = vect[dex];
	num3 = num1 + num2;
	medi = num3/2.;
}
    else{
	dex = vect.size()/2;
	medi = vect[dex];
}
    
    return medi;
}

vector<int> num_vector_mode(const vector<int>& nums) {
    unordered_map<int, int> frequencyMap;

    for (int num : nums) {
        frequencyMap[num]++;
    }

    int maxCount = 0;

    for (const auto& entry : frequencyMap) {
        maxCount = max(maxCount, entry.second);
    }

    vector<int> modes;
    for (const auto& entry : frequencyMap) {
        if (entry.second == maxCount) {
            modes.push_back(entry.first);
        }
    }

    return modes;
}
