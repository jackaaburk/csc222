#define VEHICLE_H
#include <string>
using namespace std;

struct Vehicle {
    int weight;
    int cylinders;
    int num_wheels;
    Vehicle(int weight, int cylinders);

    Vehicle(int weight, int cylinders, int num_wheels);

    string to_string(Vehicle);
};
