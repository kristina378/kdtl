#pragma once
#include "Common.hpp"
#include "StaticArray.hpp"

namespace kdtl {
    template <typename T, size_t R, size_t C>
    class StaticMatrix {
      public:
        using value_t           = T;
        using const_value_t     = const T;
        using value_t_ptr       = value_t*;
        using const_value_t_ptr = const_value_t*;
        using value_t_ref       = value_t&;
        using const_value_t_ref = const_value_t&;

      private:
        StaticArray<value_t, R * C> data;

       public:
        StaticMatrix()                   = delete;
        StaticMatrix(const StaticMatrix&) = delete;
        StaticMatrix(StaticMatrix&&)      = delete;

        StaticMatrix& operator=(const StaticMatrix&) = delete;
        StaticMatrix& operator=(StaticMatrix&&)      = delete;

        const_value_t_ref get(size_t row_index,size_t column_index){
            return data.get((row_index*C+column_index));
        }
        
    };

} // namespace kdtl