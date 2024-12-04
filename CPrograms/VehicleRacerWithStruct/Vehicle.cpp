#include "Vehicle.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

Vehicle::Vehicle(int w, int c) {
  weight = w;
  cylinders = c;
  num_wheels = 0;
  speed = 0.0;
  }

Vehicle::Vehicle(int w, int c, int nw) {
  weight = w;
  cylinders = c;
  num_wheels = nw;
  speed = 0.0;
  }

string Vehicle::to_string() {
  string outputstring;
  outputstring = "This is a vehicle that's " + ::to_string(weight) + "kg with " + ::to_string(cylinders) + " cylinders";
  return outputstring;
}

float Vehicle::calcspeed() {
  if (num_wheels == 0) {
    num_wheels = 4;
  }
  this->speed = ((static_cast<float>(cylinders * num_wheels) / weight) * 1000);
  return speed;
}

string Vehicle::race(Vehicle vehicle1, Vehicle vehicle2, int distance) {
  vehicle1.calcspeed();
  vehicle2.calcspeed();
  float vehicle1time = static_cast<float>(distance) / vehicle1.speed;
  float vehicle2time = static_cast<float>(distance) / vehicle2.speed;

  if (vehicle1time < vehicle2time) {
    float difference = vehicle2time - vehicle1time;
    ostringstream oss;
    oss << "Vehicle 1 (" << setprecision(2) << vehicle1time <<
           " seconds) beat Vehicle 2 (" <<
           vehicle2time << " seconds) by " <<
           difference << " seconds.";
    return oss.str();

  } else if (vehicle1time > vehicle2time) {
    float difference = vehicle1time - vehicle2time;
    ostringstream oss;
    oss << "Vehicle 2 (" << setprecision(2) << vehicle2time <<
           " seconds) beat Vehicle 1 (" <<
           vehicle1time << " seconds) by " <<
           difference << " seconds.";
    return oss.str();
  } else {
    ostringstream oss;
    oss << "The vehicles tied with a time of " << setprecision(2) << vehicle1time <<
           " seconds.";
    return oss.str();
  }
}
