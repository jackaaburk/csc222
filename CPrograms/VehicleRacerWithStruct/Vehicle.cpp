#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;

Vehicle::Vehicle(int w, int c) {
  weight = w;
  cylinders = c;
  }

Vehicle::Vehicle(int w, int c, int nw) {
  weight = w;
  cylinders = c;
  num_wheels = nw;
  }

string Vehicle::to_string() {
  string outputstring;
  outputstring = "This is a vehicle that's " + ::to_string(weight) + "kg with " + ::to_string(cylinders) + " cylinders";
  return outputstring;
}

float Vehicle::calcspeed() {
  if (num_wheels == 0)
  {
    num_wheels = 4;
  }
  this->speed = (((cylinders * num_wheels)/weight) * 1000);
  return this->speed;
}

