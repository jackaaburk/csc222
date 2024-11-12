#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
}

TEST_CASE("Testing if vector has other than three elements") {
    vector<int> nums = {1, 3, 7, 10};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7 10";
    CHECK(numstr == expected);
}

TEST_CASE("Testing if vector has 0 elements") {
    vector<int> nums = {};
    string numstr = render_num_vector(nums);
    string expected = "";
    CHECK(numstr == expected);
}

TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
}

TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {2, 3, 7};
    CHECK(42 == num_vector_product(nums));
}