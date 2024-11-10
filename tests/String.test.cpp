#include "kdtl/String.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstring>

TEST_CASE("Constructor String", "[String]") {
    kdtl::String s("Hello World!");
}

TEST_CASE("String::begin;String::end", "[String]") {
    kdtl::String s("foo");
    auto         iterator = s.begin();

    // First element
    REQUIRE(*iterator == 'f');
    iterator++;
    // Second element
    REQUIRE(*iterator == 'o');
    iterator++;
    // Third element
    REQUIRE(*iterator == 'o');
    iterator++;
    // End
    REQUIRE(iterator == s.end());
}

TEST_CASE("String::lenght", "[String]") {
    kdtl::String s("foo");
    REQUIRE(s.lenght() == 3);
}

TEST_CASE("String::c_str", "[String]") {
    kdtl::String s("foo");
    REQUIRE(strcmp(s.c_str(), "foo") == 0);
}

TEST_CASE("String::operator== with self", "[String]") {
    kdtl::String s("foo");
    REQUIRE(s == s);
}

TEST_CASE("String::operator== with other", "[String]") {
    kdtl::String s("foo");
    kdtl::String s2("foo");
    REQUIRE(s == s2);
}

TEST_CASE("String::operator== with other not equal", "[String]") {
    kdtl::String s("foo");
    kdtl::String s2("foo2");
    REQUIRE_FALSE(s == s2);
}
