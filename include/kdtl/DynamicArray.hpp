#include <cstdint>
#include <initializer_list>

// template<class T,class Allocayor= std::allocator<T>>class vector;
template <class T>
class DynamicArray {
    T*      data_     = nullptr;
    int64_t length_     = 0;
    int64_t capacity_ = 1;

  public:
    /* Ctor with initialization of array with values from different collection. */
    DynamicArray(std::initializer_list<T> initializer) {
        length_ = initializer.size();
        // Loop until we find power of 2 that is greater than or equal to size.
        for (; capacity_ <= length_; capacity_ <<= 1) {}
        data_ = new T[capacity_];

        int64_t index = 0;
        for (auto& element : initializer) {
            data_[index] = element;
            index++;
        }
    }

    /* Dtor which deallocates heap-allocated data pointer after DynamicArray instance
       is deallocated. */
    ~DynamicArray() {
        delete[] data_;
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
        return data_;
    }

    /* Iterator to last element of array. */
    T* end() {
        // End iterator should point to element **after** last element in the array, ie.
        // dereferencing it is not a valid operation! So, it can be used to check
        // when iterator initialized with begin() becomes invalid (saturated), as it
        // should be equivalent to end().
        return data_ + lenght();
    };

    /* Element getter. Elements returned are strictly const references, they
    can't be directly modified. */
    const T& get(int64_t index) {
        return data_[index];
    }

    /* Element setter. Please note that you can not set element outside of the array,
    ie. with indec >= length(). */
    void set(int64_t index, const T& value) {
        data_[index] = value;
    }

    /* Add element at the end of the array. This will require resizing array and
    copying all elements, as there is no way to change size of allocation. */
    void push(T value) {
        if ((length_ + 1) > capacity_) {
            reallocate(capacity_ << 1);
        }
        data_[length_] = value;
        length_++;
    }

    /* Remove element from the end of the array. */
    T pop() {
        length_--;
        // Technically, we should invoke destructor of the element removed or sth.
        return data_[length_];
    }

    /* Length of the array. */
    int64_t lenght() {
        return length_;
    }

    /* Capacity of the array. */
    int64_t capacity() {
        return capacity_;
    }


  private:
    /* Reallocate array to new size. */
    void reallocate(int64_t new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }
        capacity_ = new_capacity;
        T* new_array = new T[capacity_];

        for (int64_t index = 0; index < length_; index++) {
            new_array[index] = data_[index];
        }

        delete[] data_;
        data_ = new_array;
    }
};