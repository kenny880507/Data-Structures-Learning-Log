#pragma once

#ifndef CONTAINER_H
#define CONTAINER_H


#include <iostream>

// define iterator tag

struct foward_iterator_tag{}; // foward iterator support ++ operation
struct bidirectional_iterator_tag: foward_iterator_tag{}; // bidirectional iterator support ++, -- operation
struct random_access_iterator_tag: bidirectional_iterator_tag{}; // bidirectional iterator support ++, --, [] operation

// access function

template <typename iterator>
typename iterator::value_type access_impl(iterator it, int index, foward_iterator_tag){
    while(index-- > 0) ++it;
    return *it;
}

template <typename iterator>
typename iterator::value_type access_impl(iterator it, int index, random_access_iterator_tag){;
    return *(it + index);
}

template <typename iterator>
typename iterator::value_type access(iterator it, int index){
    return access_impl(it, index, typename iterator::iterator_type{});
}

// search function

template <typename iterator>
size_t search(iterator begin, iterator end, typename iterator::value_type value){
    size_t index = 0;
    for(iterator it = begin; it != end; ++it){
        if(*it == value){
            std::cout<<"the position of the value "<<value<<" is index "<<index<<"."<<std::endl;
            return index;
        }
        ++index;
    }
    std::cout<<"the value "<<value<<" is not in the container."<<std::endl;
    return index;
}

// visualization function

template<typename container>
void print_container(const container& container_){
    auto it = container_.begin();
    auto next_it = ++container_.begin();
    auto stop = container_.end();
    while(next_it != stop){
        ++next_it;
        std::cout << *it++ << ", ";
    }
    std::cout << *it << std::endl;
}

// dynameic array

template <typename T>
class dynamic_array{
    public:
    dynamic_array(T* input, size_t input_size): size{input_size}, capacity{input_size}{
        if(input_size>0){
            data = new T[capacity];
            for(size_t i = 0; i <input_size; ++i) data[i] = input[i];
        }
    }
    ~dynamic_array(){
        delete [] data;
        data = nullptr;
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
    dynamic_array(dynamic_array&& other) noexcept: capacity{other.capacity}, size{other.size}, data{other.data}{
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    dynamic_array& operator=(dynamic_array&& other) noexcept {
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

// linked list 

template <typename T>
class linked_list{
    public:
    linked_list(){}
    linked_list(T* input, size_t input_size): size(input_size){
        head = new node(*input);
        node* current_node = head;
        for(size_t i = 1; i < size; ++i){
            current_node = current_node->next = new node(input[i]);
        }
    }
    ~linked_list(){
        node* current_node = head;
        while(current_node!=nullptr){
            node* next_to_delete = current_node->next;
            delete current_node;
            current_node = next_to_delete;
        }
        head = nullptr;
        size = 0;
    }
    linked_list(const linked_list& other){
        if(other.head == nullptr){
            return;
        }
        head = new node(other.head->data);
        node* current_new = head;
        node* current_other = other.head->next;
        while(current_other != nullptr){
            current_new->next = new node(current_other->data);
            current_other = current_other->next;
            current_new = current_new->next;
        }
        size = other.size;
    }
    linked_list& operator=(const linked_list& other){
        if(this != &other){
            linked_list temp(other);
            std::swap(head,temp.head);
            std::swap(size,temp.size);
        }
        return *this;
    }
    linked_list(linked_list&& other) noexcept
    : head(other.head), size(other.size){
        other.head = nullptr;
        other.size = 0;
    }
    linked_list& operator=(linked_list&& other) noexcept {
        if(this != &other){
            std::swap(head,other.head);
            std::swap(size,other.size);
        }
        return *this;
    }
    class node{
        public:
        friend class iterator;
        friend class linked_list;
        node(const T& node_data): data(node_data){}
        private:
        T data;
        node* next = nullptr;
    };
    class iterator{
        public:
        using value_type = T;
        using iterator_type = foward_iterator_tag;
        iterator(node* node_data = nullptr): ptr(node_data){}
        T* operator->(){return &(ptr->data);}
        T& operator*(){return ptr->data;}
        iterator& operator++(){
            ptr = ptr->next;
            return *this;
        }
        iterator operator++(int){
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const iterator& other){return ptr==other.ptr;}
        bool operator!=(const iterator& other){return ptr!=other.ptr;}
        private:
        node* ptr;
    };
    iterator begin() const {return head;}
    iterator end() const {return nullptr;}
    void insert(const T& target, size_t position){
        if(position>size) return;
        node* new_node = new node(target);
        if(position == 0){
            new_node->next = head;
            head = new_node;
        } else {
            node* previous = head;
            for(size_t i = 0; i<position-1; ++i){
                previous = previous->next;
            }
            new_node->next = previous->next;
            previous->next = new_node;
        }
        size += 1;
        std::cout << "insert value " << target << " to index " << position << "..." << std::endl;
        print_container(*this);
    }
    void remove(size_t position){
        if(size == 0 || position>size-1) return;
        if(position == 0){
            node* temp = head;
            head = head->next;
            delete temp;
        } else {
            node* previous = head;
            for(size_t i = 0; i<position-1; ++i){
                previous = previous->next;
            }
            node* temp = previous->next;
            previous->next = temp->next;
            delete temp;
        }
        --size;
        std::cout << "remove value from index " << position << "..." << std::endl;
        print_container(*this);
    }
    size_t getSize() const {return size;}
    private:
    node* head = nullptr;
    size_t size = 0;
};


















#endif