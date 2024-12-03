#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;

Vehicle::Vehicle(int weight, int cylinders) {
  weight = weight;
  cylinders = cylinders;
  }

Vehicle::Vehicle(int weight, int cylinders, int num_wheels) {
  weight = weight;
  cylinders = cylinders;
  num_wheels = num_wheels;
  }

Vehicle::to_string(Vehicle) {
  string outputstring;
  outputstring = "This is a car that's " + weight + "kg with " + cylinders + "cylinders";
  return outputstring;
}
