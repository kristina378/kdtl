#pragma once
#include <initializer_list>
#include <kdtl/Common.hpp>


namespace kdtl {
    template <class T, size_t size>
    class StaticArray {
        T data[size];

      public:
        StaticArray(std::initializer_list<T> values) {
            size_t index = 0;
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

        const T& get(size_t index) {
            return data[index];
        }

        void set(size_t index, const T& value) {
            data[index] = value;
        }

        size_t lenght() {
            return size;
        }
    };
} // namespace kdtl