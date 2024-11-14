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

TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);
}

TEST_CASE("Testing only_odds") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> odds = only_odds(nums);
    string expected = "1 3 7 11 27";
    CHECK(render_num_vector(odds) == expected);
}

TEST_CASE("Testing nums_between function") {
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    vector<int> nums2 = nums_between(nums, 10, 20);
    string expected = "11 13 10 19 20 14";
    CHECK(render_num_vector(nums2) == expected);
}

TEST_CASE("Testing num_vector_mean") {
    vector<int> nums = {1, 4, 10};
    CHECK(5 == num_vector_mean(nums));
}
