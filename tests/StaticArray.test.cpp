#include "kdtl/StaticArray.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Construct StaticArray<int, 4>", "[StaticArray]") {
    // first step: setup
    StaticArray<int, 4> array{0, 1, 2, 3};
}

TEST_CASE("StaticArray<int, 4>::get", "[StaticArray]") {
    // first step: setup
    StaticArray<int, 4> array{0, 1, 2, 3};

    REQUIRE(array.get(0) == 0);
    REQUIRE(array.get(1) == 1);
    REQUIRE(array.get(2) == 2);
    REQUIRE(array.get(3) == 3);
}

TEST_CASE("StaticArray<int, 4>::set", "[StaticArray]") {
    StaticArray<int, 4> array{0, 0, 0, 0};

    array.set(0, 3);
    array.set(1, 4);
    array.set(2, 5);
    array.set(3, 6);

    REQUIRE(array.get(0) == 3);
    REQUIRE(array.get(1) == 4);
    REQUIRE(array.get(2) == 5);
    REQUIRE(array.get(3) == 6);
}

TEST_CASE("StaticArray<int, 4>::begin;StaticArray<int, 4>::end", "[StaticArray]") {
    StaticArray<int, 4> array{0, 1, 2, 3};

    auto iterator = array.begin();

    // First element
    REQUIRE(*iterator == 0);
    iterator++;
    // Second element
    REQUIRE(*iterator == 1);
    iterator++;
    // Third element
    REQUIRE(*iterator == 2);
    iterator++;
    // Fourth element
    REQUIRE(*iterator == 3);
    iterator++;

    // End
    REQUIRE(iterator == array.end());
}

TEST_CASE("StaticArray<int, 4>::lenght", "[StaticArray]") {
    StaticArray<int, 4> array{0, 1, 2, 3};
    REQUIRE(array.lenght() == 4);
}