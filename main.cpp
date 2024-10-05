#include "kdtl/StaticArray.hpp"
#include <array>
#include <iostream>

int main() {
    /* int array[10];
     for(int i=0;i<10;i++){}*/
    StaticArray<float, 2> array = {2.0f, 3.0f};
    array.set(0, 5.0f);
    for (auto& element : array) {
        std::cout << element << std::endl;
    }
    std::array<int, 3> array2 = {3, 4, 5};
    for (auto& element : array2) {
        std::cout << element << std::endl;
    }
    // std::cout<<sizeof(StaticArray<float,20>);
}