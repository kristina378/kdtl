#pragma once
#include <cstdint>


namespace kdtl {
    using hash_t = uint64_t;

    template <typename T>
    inline hash_t hash(const T&) {
        throw "hash<T> not implemented";
    }

    template <>
    inline hash_t hash<uint8_t>(const uint8_t& c) {
        return c;
    }

    template <>
    inline hash_t hash<int8_t>(const int8_t& c) {
        return c;
    }

    template <>
    inline hash_t hash<char>(const char& c) {
        return c;
    }

    template <>
    inline hash_t hash<uint32_t>(const uint32_t& i) {
        uint32_t x = i;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
    }

    template <>
    inline hash_t hash<int32_t>(const int32_t& i) {
        return hash(static_cast<uint32_t>(i));
    }

    template <>
    inline hash_t hash<uint64_t>(const uint64_t& i) {
        uint64_t x = i;
        x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
        x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
        x = x ^ (x >> 31);
        return x;
    }

    template <>
    inline hash_t hash<int64_t>(const int64_t& i) {
        return hash(static_cast<uint64_t>(i));
    }
}