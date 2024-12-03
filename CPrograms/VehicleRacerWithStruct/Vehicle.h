#define VEHICLE_H
struct Vehicle {
    int weight;
    int cylinders;
    int num_wheels;
    Vehicle(int weight, int cylinders);

    Vehicle(int weight, int cylinders, int num_wheels);

};
