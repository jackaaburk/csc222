#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Vehicle.h"
using namespace std;

TEST_CASE("Test can create and render Vehicle") {
    Vehicle Car1(1500, 12);
    Vehicle Truck1(3000, 8, 18);
    CHECK(Car1.to_string() == "This is a vehicle that's 1500kg with 12 cylinders");
    CHECK(Truck1.to_string() == "This is a vehicle that's 3000kg with 8 cylinders");
}

TEST_CASE("Test calcspeed") {
    Vehicle Car1(1500, 12);
    float calculated_speed = Car1.calcspeed();
    CHECK(calculated_speed == 32.0);
    Vehicle Truck1(3000, 8, 18);
    float calculated_speed2 = Truck1.calcspeed();
    CHECK(calculated_speed2 == 48.0);
}

TEST_CASE("Test race") {
    Vehicle Car1(1500, 12);
    Car1.calcspeed();
    Vehicle Car2(2000, 12);
    Car2.calcspeed();
    string racestring = Vehicle::race(Car1, Car2, 1000);
    CHECK(racestring == "Vehicle 1 (31.25 seconds) beat Vehicle 2 (41.67 seconds) by 10.42 seconds.");
    
    Vehicle Car3(2000, 8);
    Car3.calcspeed();
    Vehicle Truck1(4000, 6, 18);
    Truck1.calcspeed();
    string racestring2 = Vehicle::race(Car3, Truck1, 2000);
    CHECK(racestring2 == "Vehicle 2 (74.07 seconds) beat Vehicle 1 (125.00 seconds) by 50.93 seconds.");
}
