#pragma once

#ifndef CONTAINER_H
#define CONTAINER_H


#include <iostream>

// define iterator tag
struct foward_iterator_tag{}; // foward iterator support ++ operation
struct bidirectional_iterator_tag: foward_iterator_tag{}; // bidirectional iterator support ++, -- operation
struct random_access_iterator_tag: bidirectional_iterator_tag{}; // bidirectional iterator support ++, --, [] operation

// visualization function

template<typename container>
void print_container(const container& container_){
    auto begin = container_.begin();
    auto before_end = container_.end(); --before_end;
    while(begin<before_end){
        std::cout << *begin++ << ", ";
    }
    std::cout << *begin << std::endl;
}

// dynameic array implementation

template <typename T>
class dynamic_array{
    public:
    dynamic_array(T* input, size_t input_size): size{input_size}, capacity{input_size}{
        if(input_size>0){
            data = new T[capacity];
            for(size_t i = 0; i <input_size; ++i) data[i] = input[i];
        }
    }
    dynamic_array(const dynamic_array& other){
            capacity = other.capacity;
            size = other.size;
            if(size>0){
                for(int i = 0; i < size; ++i) data[i] = other.data[i];
            } else {
                data = nullptr;
            }
        }
    ~dynamic_array(){
        delete [] data;
        data = nullptr;
    }
    dynamic_array& operator=(const dynamic_array& other){
        if(this != &other){
            delete [] data;
            capacity = other.capacity;
            size = other.size;
            if(size>0){
                for(int i = 0; i < size; ++i) data[i] = other.data[i];
            } else {
                data = nullptr;
            }
        }
        return *this;
        
    }
    dynamic_array(dynamic_array&& other): capacity{other.capacity}, size{other.size}, data{other.data}{
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    dynamic_array& operator=(dynamic_array&& other){
        if(this != &other)
        {
            delete [] data;
            capacity = other.capacity;
            size = other.size;
            data = other.data;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
    class iterator{
        public:
        using value_type = T;
        using iterator_type = random_access_iterator_tag;
        iterator(T* data_ptr): ptr{data_ptr}{}
        T& operator*() const{return *ptr;}
        T* operator->() const{return ptr;}
        bool operator==(const iterator& other) const{return ptr==other.ptr;}
        bool operator!=(const iterator& other) const{return ptr!=other.ptr;}
        bool operator>(const iterator& other) const{return ptr>other.ptr;}
        bool operator<(const iterator& other) const{return ptr<other.ptr;}
        bool operator>=(const iterator& other) const{return ptr>=other.ptr;}
        bool operator<=(const iterator& other) const{return ptr<=other.ptr;}
        iterator operator+(ptrdiff_t distance){
            return iterator(ptr+distance);
        }
        iterator& operator+=(ptrdiff_t distance){
            ptr += distance;
            return *this;
        }
        iterator& operator-=(ptrdiff_t distance){
            ptr -= distance;
            return *this;
        }
        ptrdiff_t operator-(const iterator& other){
            return (ptr-other.ptr);
        }
        iterator& operator++(){
            ++ptr;
            return *this;
        }
        iterator operator++(int){
            iterator temp = *this;
            ++ptr;
            return temp;
        }
        iterator& operator--(){
            --ptr;
            return *this;
        }
        iterator operator--(int){
            iterator temp = *this;
            --ptr;
            return temp;
        }
        private:
        T* ptr;
    };
    void expand(){
        if(capacity == size){
            std::cout << "capacity is expanded from " << capacity <<" to ";
            capacity *= 2;
            T* temp = new T[capacity];
            for(int i = 0; i<size;++i) temp[i] = data[i];
            delete [] data;
            data = temp;
            std::cout << capacity << std::endl;
        } else {
            return;
        }
    }
    iterator begin() const{return iterator(data);}
    iterator end() const{return iterator(data)+static_cast<ptrdiff_t>(size);}
    void insert(const T& target, size_t position){
        if(position>size) return;
        if(capacity == size) expand();
        iterator giver = end(); --giver;
        iterator receiver = end();
        iterator stop_point = begin() + static_cast<ptrdiff_t>(position);
        while(giver >= stop_point){
            *receiver = *giver;
            --receiver;
            --giver;
        }
        *receiver = target;
        size += 1;
        std::cout << "insert value " << target << " to index " << position << "..." << std::endl;
        print_container(*this);
    }
    void remove(size_t position){
        if(position>=size) return;
        iterator giver = begin() + static_cast<ptrdiff_t>(position); ++giver;
        iterator receiver = begin() + static_cast<ptrdiff_t>(position);
        iterator stop_point = end();
        while(giver < stop_point) {
            *receiver = *giver;
            ++receiver;
            ++giver;
        }
        size -= 1;
        std::cout << "remove value from index " << position << "..." << std::endl;
        print_container(*this);
    }
    size_t getSize() const{return size;}
    private:
    size_t capacity;
    size_t size;
    T* data;
};




















#endif