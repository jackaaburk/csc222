#include <iostream>
#include "Time.h"
using namespace std;


int main() {
    Time current_time = {9, 14, 30.0};
    current_time.print();
    current_time.increment(500.0);
    current_time.print();
    cout << current_time.convert_to_seconds() << endl;
    Time done_time = {10, 14, 31.0};
    if (done_time.after(current_time)) {
        cout << "The bread will be done after it starts." << endl;
    }

    Time elapsed_time(3661.5);
    elapsed_time.print();

    return 0;
}