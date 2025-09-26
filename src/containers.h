#pragma once

#ifndef CONTAINER_H
#define CONTAINER_H

// define iterator tag
struct foward_iterator_tag{}; // foward iterator support ++ operation
struct bidirectional_iterator_tag: foward_iterator_tag{}; // bidirectional iterator support ++, -- operation
struct random_access_iterator_tag: bidirectional_iterator_tag{}; // bidirectional iterator support ++, --, [] operation

template <typename T>
class dynamic_array{
    public:
    dynamic_array<T>(T* input, size_t input_size): size{input_size}, capacity{input_size}{
        if(input_size>0){
            data = new T[capacity];
            for(size_t i = 0; i <input_size; ++i) data[i] = input[i];
        }
    }
    class iterator{
        public:
        using value_type = typename T;
        using iterator_type = typename random_access_iterator_tag;
    }
    void expand(){}
    void insert(const T& data, size_t position){}
    void remove(const T& data, size_t position){}
    private:
    size_t capacity;
    size_t size;
    T* data;
};




















#endif