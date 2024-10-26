#include <cstdint>
#include <initializer_list>

// template<class T,class Allocayor= std::allocator<T>>class vector;
template <class T>
class DynamicArray {
    T*      data;
    int64_t size;

  public:
    /* Ctor with initialization of array with values from different collection. */
    DynamicArray(std::initializer_list<T> initializer) {
        size          = initializer.size();
        data          = new T[size];
        int64_t index = 0;
        for (auto& element : initializer) {
            data[index] = element;
            index++;
        }
    }
    /* Dtor which deallocates heap-allocated data pointer after DynamicArray instance
       is deallocated. */
    ~DynamicArray() {
        delete[] data;
    }
    /* Iterator to first element of array. */
    T* begin() {
        // In this case it is simply a pointer, since pointers support dereferencing
        // and incrementation to walk through consecutive elements.a
        // However! it is possible to use some dedicated class instance to do that,
        // as long as it supports dereferencing and increment, we will try that when we
        // look into implementing `HashMap` in which case it is not possible to just use ptr.
        // https://www.geeksforgeeks.org/dereference-pointer-in-c/
        // https://en.wikipedia.org/wiki/Hash_table
        return data;
    }
    /* Iterator to last element of array. */
    T* end() {
        // End iterator should point to element **after** last element in the array, ie.
        // dereferencing it is not a valid operation! So, it can be used to check
        // when iterator initialized with begin() becomes invalid (saturated), as it
        // should be equivalent to end().
        return data + lenght();
    };
    /* Element getter. Elements returned are strictly const references, they
    can't be directly modified. */
    const T& get(int64_t index) {
        return data[index];
    }
    /* Element setter. Please note that you can not set element outside of the array,
    ie. with indec >= length(). */
    void set(int64_t index, const T& value) {
        data[index] = value;
    }
    /* Add element at the end of the array. This will require resizing array and
    copying all elements, as there is no way to change size of allocation. */
    void push(T value) {
        reallocate(size + 1);
        data[size - 1] = value;
    }
    /* Remove element from the end of the array. */
    T pop() { // render whitespace
        T value = data[size - 1];
        reallocate(size - 1);
        return value;
    }
    /* Length of the array. */
    int64_t lenght() {
        return size;
    }

  private:
    /* Reallocate array to new size. */
    void reallocate(int64_t new_size) {
        T* new_array = new T[new_size];
        int64_t size_to_copy = new_size < size ? new_size : size;
        for (int64_t index = 0; index < size_to_copy; index++) {
            new_array[index] = data[index];
        }
        delete[] data;
        data = new_array;
        size = new_size;
    }
};