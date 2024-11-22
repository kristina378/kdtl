#pragma once
#include "kdtl/Common.hpp"
#include "kdtl/Hash.hpp"
#include <stdexcept>

namespace kdtl {
    template <class K, class V>
    class HashMap {
      public:
        using key_t           = K;
        using const_key_t     = const K;
        using key_t_ptr       = key_t*;
        using const_key_t_ptr = const_key_t*;

        using value_t           = V;
        using const_value_t     = const V;
        using value_t_ptr       = value_t*;
        using const_value_t_ptr = const_value_t*;

        struct BucketInfo {
            bool   is_occupied = false;
            hash_t hash;
            key_t  key;
        };

        class KeyError : public std::runtime_error {
          public:
            KeyError() :
                std::runtime_error("Missing key!") {}
        };

      private:
        BucketInfo* bucket_info_array = nullptr;
        value_t_ptr values            = nullptr;
        size_t      capacity          = 0;
        size_t      occupancy         = 0;

      public:
        HashMap() {
            capacity          = 8;
            bucket_info_array = new BucketInfo[capacity];
            values            = new value_t[capacity];
        }

        HashMap(const HashMap&) = delete;
        HashMap(HashMap&&)      = delete;

        HashMap& operator=(const HashMap&) = delete;
        HashMap& operator=(HashMap&&)      = delete;

        ~HashMap() {
            delete[] bucket_info_array;
            delete[] values;
        }

        void set(const_key_t& key, const_value_t& value) {
            hash_t hash_value   = hash(key);
            size_t bucket_index = hash_value % capacity;

            while (true) {
                if (bucket_info_array[bucket_index].is_occupied) {
                    if (bucket_info_array[bucket_index].hash == hash_value and
                        bucket_info_array[bucket_index].key == key) {
                        break;
                    }
                    bucket_index = (bucket_index + 1) % capacity;
                } else {
                    break;
                }
            }

            bucket_info_array[bucket_index].is_occupied = true;
            bucket_info_array[bucket_index].hash        = hash_value;
            bucket_info_array[bucket_index].key         = key;
            values[bucket_index]                        = value;

            occupancy++;
        }

        const_value_t& get(const_key_t& key) {
            hash_t hash_value   = hash(key);
            size_t bucket_index = hash_value % capacity;

            if (bucket_info_array[bucket_index].is_occupied) {
                return values[bucket_index];
            }
            throw KeyError();
        }
    };
} // namespace kdtl