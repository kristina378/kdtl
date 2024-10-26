#pragma once
#include <cstdint>
#include <initializer_list>

template <class T, int64_t size>
class StaticArray {
    T data[size];
  public:
    StaticArray(std::initializer_list<T> values) {
        int64_t index = 0;
        for (auto& element : values) {
            data[index] = element;
            index++;
            if (index >= size) {
                break;
            }
        }
    }

    T* begin() {
        return &data[0];
    }

    T* end() {
        return &data[size];
    }

    const T& get(int64_t index) {
        return data[index];
    }

    void set(int64_t index, const T& value) {
        data[index] = value;
    }

    int64_t lenght() {
        return size;
    }
};