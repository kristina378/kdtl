#pragma once
#include <kdtl/Common.hpp>
#include <kdtl/Hash.hpp>

namespace kdtl {
    template <class T>
    class BasicString {
      public:
        using char_t           = T;
        using const_char_t     = const T;
        using char_t_ptr       = char_t*;
        using const_char_t_ptr = const_char_t*;

      private:
        size_t     lenght_;
        char_t_ptr data_;

      public:
        BasicString()                   = delete;
        BasicString(const BasicString&) = delete;
        BasicString(BasicString&&)      = delete;

        BasicString& operator=(const BasicString&) = delete;
        BasicString& operator=(BasicString&&)      = delete;

        BasicString(const char* str_) {
            size_t lenght = 0;
            while (str_[lenght] != '\0') {
                lenght++;
            }
            lenght_ = lenght;
            data_   = new char_t[lenght_ + 1];
            for (size_t index = 0; index < lenght + 1; index++) {
                data_[index] = str_[index];
            }
        };

        ~BasicString() {
            delete[] data_;
        }

        char_t_ptr begin() {
            return data_;
        }

        char_t_ptr end() {
            return data_ + lenght_;
        }

        size_t lenght() {
            return lenght_;
        }

        const_char_t_ptr c_str() {
            return data_;
        }

        bool operator==(const BasicString& other) const {
            if (lenght_ != other.lenght_)
                return false;
            for (size_t index = 0; index < lenght_; index++) {
                if (data_[index] != other.data_[index])
                    return false;
            }
            return true;
        };
    };

    using String    = BasicString<char>;
    using WString   = BasicString<short>;
    using U8String  = BasicString<uint8_t>;
    using U16String = BasicString<uint16_t>;
    using U32String = BasicString<uint32_t>;

    template <>
    inline hash_t hash<String>(const String& value) {
        return 0;
    }
} // namespace kdtl
