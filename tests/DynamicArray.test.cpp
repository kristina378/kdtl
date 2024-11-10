#include "kdtl/DynamicArray.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Constructor DynamicArray<int> non empty", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2, 3, 4, 5};

    REQUIRE(array.lenght() == 5);
    REQUIRE(array.capacity() == 8);
}

TEST_CASE("Constructor DynamicArray<int> empty", "[DynamicArray]") {
    DynamicArray<int> array({});

    REQUIRE(array.lenght() == 0);
    REQUIRE(array.capacity() == 1);
}

TEST_CASE("DynamicArray<int>::get", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2, 3, 4, 5};
    REQUIRE(array.get(0) == 1);
    REQUIRE(array.get(1) == 2);
    REQUIRE(array.get(2) == 3);
    REQUIRE(array.get(3) == 4);
    REQUIRE(array.get(4) == 5);
}

TEST_CASE("DynamicArray<int>::begin; DynamicArray<int>::end", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2, 3, 4, 5};
    REQUIRE(array.get(0) == 1);
    auto iterator = array.begin();

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
    // Fifth element
    REQUIRE(*iterator == 5);
    iterator++;
    // End
    REQUIRE(iterator == array.end());
}

TEST_CASE("DynamicArray<int>::set", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2, 3, 4, 5};
    array.set(0, 3);
    array.set(1, 4);
    array.set(2, 5);
    array.set(3, 6);
    array.set(4, 7);

    REQUIRE(array.get(0) == 3);
    REQUIRE(array.get(1) == 4);
    REQUIRE(array.get(2) == 5);
    REQUIRE(array.get(3) == 6);
    REQUIRE(array.get(4) == 7);
};

TEST_CASE("DynamicArray<int>::push", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2, 3, 4, 5};
    array.push(12);
    REQUIRE(array.get(5) == 12);
    array.push(54);
    REQUIRE(array.get(6) == 54);
};

TEST_CASE("DynamicArray<int>::push with reallocate", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2};
    array.push(12);
    array.push(54);
    array.push(77);

    REQUIRE(array.lenght() == 5);
    REQUIRE(array.capacity() == 8);

    REQUIRE(array.get(0) == 1);
    REQUIRE(array.get(1) == 2);
    REQUIRE(array.get(2) == 12);
    REQUIRE(array.get(3) == 54);
    REQUIRE(array.get(4) == 77);
};

TEST_CASE("DynamicArray<int>::pop", "[DynamicArray]") {
    DynamicArray<int> array = {1, 2, 3, 4, 5};
    array.pop();
    REQUIRE(array.lenght() == 4);
    array.pop();
    REQUIRE(array.lenght() == 3);
};

TEST_CASE("DynamicArray<int>::pop from empty array", "[DynamicArray]") {
    DynamicArray<int> array({});
    REQUIRE_THROWS(array.pop());
};

TEST_CASE("DynamicArray<int>::realocate","[DynamicArray]"){
    
};