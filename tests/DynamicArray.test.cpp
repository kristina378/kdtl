#include "kdtl/DynamicArray.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Constructor DynamicArray<int,5>", "[DynamicArray]") {
    DynamicArray<int> array1 = {1, 2, 3, 4, 5};
    REQUIRE(array1.get(0) == 1);
    REQUIRE(array1.get(1) == 2);
    REQUIRE(array1.get(2) == 3);
    REQUIRE(array1.get(3) == 4);
    REQUIRE(array1.get(3) == 5);
}

TEST_CASE("DynamicArray<int,5>::begin; DynamicArray<int,5>::end", "[DynamicArray]") {
    DynamicArray<int> array1 = {1, 2, 3, 4, 5};
    REQUIRE(array1.get(0) == 1);
    auto iterator = array1.begin();

    // First element
    REQUIRE(*iterator == 1);
    iterator++;
    // Second element
    REQUIRE(*iterator == 2);
    iterator++;
    // Third element
    REQUIRE(*iterator == 3);
    iterator++;
    // Fourth element
    REQUIRE(*iterator == 4);
    iterator++;
    REQUIRE(*iterator == 5);
    iterator++;
    // End
    REQUIRE(iterator == array1.end());
}
