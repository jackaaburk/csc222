#include <iostream>
#include <string>
#include "Time.h"
using namespace std;


int main() {
    Time t(3600 * 4 + 60 * 11 + 22);
    cout << "Time t is: " << t << endl;

    return 0;
}
