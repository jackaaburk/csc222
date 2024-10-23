#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
int counter = 0;
    for (int i = 0; i < argc; i++) {
        cout << "Command line argument [" << i << "] is: ";
        cout << argv[i] << endl;
	counter++;
    }

    cout << (argv[counter++] == nullptr ? "NULL" : "Ouch!") << endl;
    cout << (argv[counter++] == nullptr ? "NULL" : "Ouch!") << endl;
    return 0;
}
