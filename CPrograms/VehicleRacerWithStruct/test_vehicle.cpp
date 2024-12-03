#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Vehicle.h"
using namespace std;

TEST_CASE("Test can create and render Vehicle") {
    Vehicle Car1(1500, 12);
    Vehicle Truck1(3000, 8, 18);
    CHECK(Car1.to_string() == "This is a vehicle that's 1500kg with 12 cylinders");
    CHECK(Truck1.to_string() == "This is a vehicle that's 3000kg with 18 cylinders");
}
