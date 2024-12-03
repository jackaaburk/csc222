#define VEHICLE_H
#include <string>
using namespace std;

struct Vehicle {
    int weight;
    int cylinders;
    int num_wheels;
    float speed;
    Vehicle(int weight, int cylinders);

    Vehicle(int weight, int cylinders, int num_wheels);

    string to_string();

    float calcspeed();

    string race(Vehicle vehicle1, Vehicle vehicle2, int distance);
};

