#include "kdtl/DynamicArray.hpp"
#include "kdtl/StaticArray.hpp"
#include <_strings.h>
#include <array>
#include <iostream>

int main() {
    /* int array[10];
     for(int i=0;i<10;i++){}*/
    // StaticArray<float, 2> array = {2.0f, 3.0f};
    // array.set(0, 5.0f);
    // for (auto& element : array) {
    //     std::cout << element << std::endl;
    // }
    // std::array<int, 3> array2 = {3, 4, 5};
    // for (auto& element : array2) {
    //     std::cout << element << std::endl;
    // }
    // std::cout<<sizeof(StaticArray<float,20>);
    DynamicArray<float> array3 = {1.0f, 2.0f, 6.0f};
    std::cout << array3.get(0) << std::endl;
    std::cout << array3.get(1) << std::endl;
    std::cout << array3.get(2) << std::endl;

    array3.push(3.0f);

    std::cout << array3.get(3) << std::endl;

    std::cout << "lenght " << array3.lenght() << std::endl;
    std::cout << "pop " << array3.pop() << std::endl;
    std::cout << "lenght " << array3.lenght() << std::endl;
}