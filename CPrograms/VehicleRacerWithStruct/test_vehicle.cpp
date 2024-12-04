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
    CHECK(racestring == "Car1 (31 seconds) beat Car2 (41 seconds) by 10 seconds.");
}
