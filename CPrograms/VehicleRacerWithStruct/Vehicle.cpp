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

string Vehicle::to_string() {
  string outputstring;
  outputstring = "This is a car that's " + ::to_string(weight) + "kg with " + ::to_string(cylinders) + " cylinders";
  return outputstring;
}
