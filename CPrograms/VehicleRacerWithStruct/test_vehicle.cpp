#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Vehicle.h".h"
using namespace std;

TEST_CASE("Test can create and render Vehicle") {
    Vehicle Car1(1500, 12);
    Vehicle Truck1(3000, 8, 18)
    CHECK(Car1.to_string() == "This is a car with 1500kg and 12 cylinders");
    CHECK(Truck1.to_string() == "This is a truck with 3000kg and 18 cylinders")
}
