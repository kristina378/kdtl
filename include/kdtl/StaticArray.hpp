#pragma once
#include <initializer_list>
#include <kdtl/Common.hpp>

namespace kdtl {
    template <class T, size_t size>
    class StaticArray {
      public:
        using value_t           = T;
        using const_value_t     = const T;
        using value_t_ptr       = value_t*;
        using const_value_t_ptr = const_value_t*;
        using value_t_ref       = value_t&;
        using const_value_t_ref = const_value_t&;

      private:
        value_t data[size];

      public:
        StaticArray(std::initializer_list<value_t> values) {
            size_t index = 0;
            for (auto& element : values) {
                data[index] = element;
                index++;
                if (index >= size) {
                    break;
                }
            }
        }

        value_t_ptr begin() {
            return &data[0];
        }

        value_t_ptr end() {
            return &data[size];
        }

        const_value_t_ref get(size_t index) {
            return data[index];
        }

        void set(size_t index, const_value_t_ref value) {
            data[index] = value;
        }

        size_t lenght() {
            return size;
        }
    };
} // namespace kdtl