#include "kdtl/HashMap.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace kdtl;

TEST_CASE("HashMap<char, int>::get; HashMap<char, int>::set", "[HashMap]") {
    HashMap<char, int> map;

    const char key = 'A';
    const int expected = 34567;

    map.set(key, expected);
    REQUIRE(map.get(key) == expected);
};

TEST_CASE("HashMap<char, int>::get (missing key)", "[HashMap]") {
    HashMap<char, int> map;
    const char key = 'A';
    REQUIRE_THROWS(map.get(key));
};

TEST_CASE("HashMap<char, int>::get; HashMap<char, int>::set (many, no collision)", "[HashMap]") {
    HashMap<char, int> map;

    const char key0 = 'A';
    const int expected0 = 34567;

    const char key1 = 'B';
    const int expected1 = 5465;

    map.set(key0, expected0);
    map.set(key1, expected1);

    REQUIRE(map.get(key0) == expected0);
    REQUIRE(map.get(key1) == expected1);
};

TEST_CASE("HashMap<char, int>::get; HashMap<char, int>::set (many, with collision)", "[HashMap]") {
    HashMap<char, int> map;

    const char key0 = 'A';
    const int expected0 = 34567;

    const char key1 = 'I';
    const int expected1 = 5465;

    map.set(key0, expected0);
    map.set(key1, expected1);

    REQUIRE(map.get(key0) == expected0);
    REQUIRE(map.get(key1) == expected1);
};