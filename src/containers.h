#pragma once

#ifndef CONTAINER_H
#define CONTAINER_H


#include <iostream>

// define iterator tag

struct forward_iterator_tag{}; // forward iterator support ++ operation
struct bidirectional_iterator_tag: forward_iterator_tag{}; // bidirectional iterator support ++, -- operation
struct random_access_iterator_tag: bidirectional_iterator_tag{}; // bidirectional iterator support ++, --, [] operation

// access function

template <typename iterator>
typename iterator::value_type access_impl(iterator it, int index, forward_iterator_tag){
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

//modulo function

template <typename T>
T mod(T value, T modulus){
    T residue = value % modulus;
    if(residue>=0) return residue;
    else{return modulus+residue;}
}

// visualization function

template<typename container>
void print_container(container& container_){
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
    dynamic_array(): data{new T[1]}, capacity{1}, size{0}{}
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
    iterator begin(){return iterator(data);}
    iterator end(){return iterator(data)+static_cast<ptrdiff_t>(size);}
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
        using iterator_type = forward_iterator_tag;
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
    iterator begin() {return iterator(head);}
    iterator end() {return iterator(nullptr);}
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

//deque

template <typename T>
class deque{
    public:
    deque(): data{new T[1]}, capacity{1}, size_{0}, front_{0}{}
    deque(T* input, size_t input_size): data{new T[input_size]}, capacity{input_size>0 ? input_size : 1}, size_{input_size}, front_{0}{
        for(size_t i=0; i<size_; ++i){
            data[i] = input[i];
        }
    }
    ~deque(){delete [] data;}
    deque(const deque& other): data{new T[other.capacity]}, capacity{other.capacity}, size_{other.size_}, front_{other.front_}{
        for(size_t i=0; i<size_; ++i){
            size_t position = (front_+i)%capacity;
            data[position] = other.data[position];
        }
    }
    deque& operator=(const deque& other){
        if(this==&other) return *this;
        capacity = other.capacity;
        size_ = other.size_;
        front_ = other.front_;
        delete [] data;
        data = new T[capacity];
        for(size_t i=0; i<size_; ++i){
            size_t position = (front_+i)%capacity;
            data[position] = other.data[position];
        }
        return *this;
    }
    deque(deque&& other) noexcept: data{other.data}, capacity{other.capacity}, size_{other.size_}, front_{other.front_}{
        other.data = nullptr;
        other.capacity = other.size_ = other.front_ = 0;
    }
    deque& operator=(deque&& other) noexcept {
        if (this == &other) return *this;
        delete [] data;
        data = other.data;
        capacity = other.capacity;
        size_ = other.size_;
        front_ = other.front_;
        other.data = nullptr;
        other.capacity = other.size_ = other.front_ = 0;
        return *this;
    }
    class iterator{
        public:
        using value_type = T;
        using iterator_type = random_access_iterator_tag;
        iterator(deque<T>* container_ptr, size_t logic_idx_): deque_ptr{container_ptr}, logic_idx{logic_idx_}{
            if(logic_idx_>=deque_ptr->size_){
                ptr = nullptr;
                return;
            }
            ptr = deque_ptr->data + mod(logic_idx+deque_ptr->front_,deque_ptr->capacity);
        }
        T& operator*() const{return *ptr;}
        T* operator->() const{return ptr;}
        bool operator==(const iterator& other) const{return logic_idx==other.logic_idx;}
        bool operator!=(const iterator& other) const{return logic_idx!=other.logic_idx;}
        bool operator>(const iterator& other) const{return logic_idx>other.logic_idx;}
        bool operator<(const iterator& other) const{return logic_idx<other.logic_idx;}
        bool operator>=(const iterator& other) const{return logic_idx>=other.logic_idx;}
        bool operator<=(const iterator& other) const{return logic_idx<=other.logic_idx;}
        iterator operator+(ptrdiff_t distance){
            ptrdiff_t output_index = static_cast<ptrdiff_t>(logic_idx) + distance;
            if(output_index<0 || output_index>deque_ptr->size_){
                throw std::out_of_range("Iterator offset out of bounds.");
            }
            return iterator(deque_ptr,static_cast<size_t>(output_index));
        }
        iterator& operator+=(ptrdiff_t distance){
            ptrdiff_t output_index = static_cast<ptrdiff_t>(logic_idx) + distance;
            if(output_index<0 || static_cast<size_t>(output_index)>deque_ptr->size_){
                throw std::out_of_range("Iterator offset out of bounds.");
            }
            logic_idx = output_index;
            if(logic_idx<deque_ptr->size_){
                ptr = deque_ptr->data + mod(logic_idx+deque_ptr->front_,deque_ptr->capacity);
            } else {
                ptr = nullptr;
            }
            return *this;
        }
        iterator operator-(ptrdiff_t distance){
            ptrdiff_t output_index = static_cast<ptrdiff_t>(logic_idx) - distance;
            if(output_index<0 || output_index>deque_ptr->size_){
                throw std::out_of_range("Iterator offset out of bounds.");
            }
            return iterator(deque_ptr,static_cast<size_t>(output_index));
        }
        iterator& operator-=(ptrdiff_t distance){
            ptrdiff_t output_index = static_cast<ptrdiff_t>(logic_idx) - distance;
            if(output_index<0 || static_cast<size_t>(output_index)>deque_ptr->size_){
                throw std::out_of_range("Iterator offset out of bounds.");
            }
            logic_idx = output_index;
            if(logic_idx<deque_ptr->size_){
                ptr = deque_ptr->data + mod(logic_idx+deque_ptr->front_,deque_ptr->capacity);
            } else {
                ptr = nullptr;
            }
            return *this;
        }
        ptrdiff_t operator-(const iterator& other){
            return static_cast<ptrdiff_t>(logic_idx) - static_cast<ptrdiff_t>(other.logic_idx);
        }
        iterator& operator++(){
            *this+=1;
            return *this;
        }
        iterator operator++(int){
            iterator temp = *this;
            *this+=1;
            return temp;
        }
        iterator& operator--(){
            *this-=1;
            return *this;
        }
        iterator operator--(int){
            iterator temp = *this;
            *this-=1;
            return temp;
        }
        private:
        T* ptr;
        size_t logic_idx;
        deque<T>* deque_ptr;
    };
    iterator begin(){return iterator(this, 0);}
    iterator end(){return iterator(this, size_);}
    void expand(){
        std::cout << "capacity is expanded from " << capacity <<" to ";
        size_t old_capacity = capacity;
        capacity *= 2;
        T* temp = new T[capacity];
        for(size_t i = 0; i<size_;++i){
            size_t position = (front_+i)%old_capacity;
            temp[i] = data[position];
        }
        delete [] data;
        data = temp;
        front_ = 0;
        std::cout << capacity << std::endl;
    }
    void push_back(const T& value){
        if(size_==capacity) expand();
        size_t physic_idx = (front_+size_)%capacity;
        data[physic_idx] = value;
        ++size_;
    }
    void push_front(const T& value){
        if(size_==capacity) expand();
        front_ = mod(front_-1,capacity);
        data[front_] = value;
        ++size_;
    }
    void pop_back(){
        if(size_==0) return;
        --size_;
    }
    void pop_front(){
        if(size_==0) return;
        --size_;
        front_ = (front_+1)%capacity;
    }
    T back(){
        return *(--end());
    }
    T front(){
        return *(begin());
    }
    size_t size() const {return size_;}
    private:
    T* data;
    size_t capacity;
    size_t size_;
    size_t front_;
};

//stack

template <typename T>
class stack{
    public:
    stack(){}
    stack(T* input, size_t input_size): deque_(input,input_size){}
    stack(const stack& other): deque_(other.deque_){}
    stack& operator=(const stack& other){
        if(this!=&other) deque_ = other.deque_;
        return *this;
    }
    stack(stack&& other) noexcept: deque_(other){}
    stack& operator=(stack&& other) noexcept{
        if(this!=&other) deque_ = std::move(other.deque_);
        return *this;
    }
    void push(const T& value){
        deque_.push_back(value);
    }
    void pop(){
        deque_.pop_back();
    }
    T top(){
        return deque_.back();
    }
    size_t size() const {return deque_.size();}
    bool empty() const {return size()==0;}
    auto begin() { return deque_.begin(); }
    auto end() { return deque_.end(); }
    private:
    deque<T> deque_;
};

//queue

template <typename T>
class queue{
    public:
    queue(){}
    queue(T* input, size_t input_size): deque_(input,input_size){}
    queue(const queue& other): deque_(other){
    }
    queue& operator=(const queue& other){
        if(this!=&other) deque_ = other.deque_;
        return *this;
    }
    queue(queue&& other) noexcept: deque_(other){}
    queue& operator=(queue&& other) noexcept{
        if(this!=&other) deque_ = std::move(other.deque_);
        return *this;
    }
    void enqueue(const T& value){
        deque_.push_back(value);
    }
    void dequeue(){
        deque_.pop_front();
    }
    T back(){
        return deque_.back();
    }
    T front(){
        return deque_.front();
    }
    size_t size() const {return deque_.size();}
    bool empty() const {return size()==0;}
    auto begin() { return deque_.begin(); }
    auto end() { return deque_.end(); }
    private:
    deque<T> deque_;
};

// tree
template <typename T>
class tree{
    public:
    tree(){}
    virtual void insert(const T& data) = 0;
    virtual void remove(const T& data) = 0;
    virtual bool search(const T& data) = 0;
    virtual ~tree() = default;
};

template <typename T>
class BST: public tree<T>{
    public:
    BST(): tree<T>{}, root{nullptr}{}
    BST(const T* input_ary, const size_t ary_size): tree<T>{}, root{nullptr}{
        for(size_t i=0; i<ary_size; ++i) insert(input_ary[i]);
    }
    BST(const BST<T>& other): tree<T>{}{
        root = clone_subtree(other.root);
    }
    BST& operator=(const BST<T>& other){
        if(this!=&other){
            delete_subtree(root);
            root = clone_subtree(other.root);
        }
        return *this;
    }
    BST(BST<T>&& other) noexcept: tree<T>{}, root{nullptr}{
        std::swap(root, other.root);
    }
    BST& operator=(BST<T>&& other) noexcept{
        if(this!=&other){
            delete_subtree(root);
            std::swap(root, other.root);
        }
        return *this;
    }
    ~BST(){
        delete_subtree(root);
    }
    void insert(const T& data) override{
        if(root==nullptr) root = new node(data);
        else{
            node* previous = nullptr;
            node* current = root;
            while(current!=nullptr){
                previous = current;
                if(data==current->value) return;
                else if(data<current->value) current = current->left;
                else current = current->right;
            }
            if(data<previous->value) previous->left = new node(data);
            else previous->right = new node(data);
        }
    }
    void remove(const T& data) override {
        node* previous = nullptr;
        node* current = root;
        while (current != nullptr && current->value != data) {
            previous = current;
            if (data < current->value) current = current->left;
            else current = current->right;
        }
        if (current == nullptr) return; // didn't find.

        if (current->left != nullptr && current->right != nullptr){ // 2 childs
            node* successor = current->right;
            node* successor_prev = current; 
            
            while (successor->left != nullptr) {
                successor_prev = successor;
                successor = successor->left;
            }

            current->value = successor->value; // replace value of current
            
            current = successor; // new node needed to be delete
            previous = successor_prev;
        }
        
        node* child = (current->left != nullptr) ? current->left : current->right;

        if (previous == nullptr){ // current is at root
            root = child;
        } else { // current is not at root
            if (current == previous->left) {
                previous->left = child;
            } else {
                previous->right = child;
            }
        }
        delete current;
    }
    bool search(const T& data) override{
        if(root==nullptr) return false;
        node* current = root;
        while(current!=nullptr){
            if(data==current->value) return true;
            if(data>current->value) current = current->right;
            else current = current->left;
        }
        return false;
    }
    class node{
        public:
        friend class BST;
        node(const T& input): value{input}, left{nullptr}, right{nullptr}{}
        ~node() = default;
        private:
        node* left;
        node* right;
        T value;
    };
    class pre_iterator{ //N>L>R
        public:
        using value_type = T;
        using iterator_type = forward_iterator_tag;
        pre_iterator(): current{nullptr}{}
        pre_iterator(node* start_node): current{start_node}{
            if(current!=nullptr){
                node_stack.push(start_node);
            } 
            next();
        }
        pre_iterator(const pre_iterator& other): current{other.current}, node_stack{other.node_stack}{}
        pre_iterator& operator=(const pre_iterator& other){
            if(this!=&other){
                current = other.current;
                node_stack = other.node_stack;
            }
            return *this;
        }
        T& operator*(){return current->value;}
        T* operator->(){return &current->value;}
        pre_iterator& operator++(){
            this->next();
            return *this;
        }
        pre_iterator operator++(int){
            pre_iterator temp(*this);
            this->next();
            return temp;
        }
        bool operator==(const pre_iterator& other) const {return current == other.current;}
        bool operator!=(const pre_iterator& other) const {return !(*this == other);}
        private:
        node* current;
        stack<node*> node_stack;
        void next(){
            if(node_stack.empty()){ // end condition
                current = nullptr;
                return;
            } 
            current = node_stack.top();
            node_stack.pop();
            if(current->right!=nullptr) node_stack.push(current->right);
            if(current->left!=nullptr) node_stack.push(current->left);
        }
    };
    pre_iterator preorder_begin(){
        pre_iterator it(root);
        return it;
    }
    pre_iterator preorder_end(){
        pre_iterator it;
        return it;
    }
    class in_iterator{ //L>N>R
        public:
        using value_type = T;
        using iterator_type = forward_iterator_tag;
        in_iterator(): current{nullptr}{}
        in_iterator(node* start_node): current{start_node}{
            if(current!=nullptr){
                node_stack.push(start_node);
                node* next_push = start_node->left;
                while(next_push!=nullptr){
                    node_stack.push(next_push);
                    next_push = next_push->left;
                }
            } 
            next();
        }
        in_iterator(const in_iterator& other): current{other.current}, node_stack{other.node_stack}{}
        in_iterator& operator=(const in_iterator& other){
            if(this!=&other){
                current = other.current;
                node_stack = other.node_stack;
            }
            return *this;
        }
        T& operator*(){return current->value;}
        T* operator->(){return &current->value;}
        in_iterator& operator++(){
            this->next();
            return *this;
        }
        in_iterator operator++(int){
            in_iterator temp(*this);
            this->next();
            return temp;
        }
        bool operator==(const in_iterator& other) const {return current == other.current;}
        bool operator!=(const in_iterator& other) const {return !(*this == other);}
        private:
        node* current;
        stack<node*> node_stack;
        void next(){
            if(node_stack.empty()){ // end condition
                current = nullptr;
                return;
            }
            current = node_stack.top();
            node_stack.pop();
            if(current->right!=nullptr){
                node_stack.push(current->right);
                node* next_push = node_stack.top()->left;
                while(next_push!=nullptr){
                    node_stack.push(next_push);
                    next_push = next_push->left;
                }
            }
        }
    };
    in_iterator inorder_begin(){
        in_iterator it(root);
        return it;
    }
    in_iterator inorder_end(){
        in_iterator it;
        return it;
    }
    class post_iterator{ //L>R>N
        public:
        using value_type = T;
        using iterator_type = forward_iterator_tag;
        post_iterator(): current{nullptr}{}
        post_iterator(node* start_node): current{start_node}{
            if(current!=nullptr){
                node_stack.push(start_node);
                node* next_push = start_node->left;
                while(next_push!=nullptr){
                    node_stack.push(next_push);
                    next_push = next_push->left;
                }
            } 
            next();
        }
        post_iterator(const post_iterator& other): current{other.current}, node_stack{other.node_stack}{}
        post_iterator& operator=(const post_iterator& other){
            if(this!=&other){
                current = other.current;
                node_stack = other.node_stack;
            }
            return *this;
        }
        T& operator*(){return current->value;}
        T* operator->(){return &current->value;}
        post_iterator& operator++(){
            this->next();
            return *this;
        }
        post_iterator operator++(int){
            post_iterator temp(*this);
            this->next();
            return temp;
        }
        bool operator==(const post_iterator& other) const {return current == other.current;}
        bool operator!=(const post_iterator& other) const {return !(*this == other);}
        private:
        node* current;
        stack<node*> node_stack;
        node* last_pop;
        void next() {
            while (!node_stack.empty()) {
                node* peek_node = node_stack.top();
                if (peek_node->right == current || peek_node->right == nullptr) {
                    current = peek_node;
                    node_stack.pop();
                    return; 
                } 
                else {
                    node* next_push = peek_node->right;
                    while(next_push != nullptr){
                        node_stack.push(next_push);
                        next_push = next_push->left;
                    }
                }
            }
            current = nullptr;
        }
    };
    post_iterator postorder_begin(){
        post_iterator it(root);
        return it;
    }
    post_iterator postorder_end(){
        post_iterator it;
        return it;
    }
    private:
    node* root;
    void delete_subtree(node* target){
        if(target==nullptr) return;
        delete_subtree(target->left);
        delete_subtree(target->right);
        delete target;
    }
    node* clone_subtree(const node* target){
        if(target==nullptr) return nullptr;
        node* receiver = new node(target->value);
        receiver->left = clone_subtree(target->left);
        receiver->right = clone_subtree(target->right);
        return receiver;
    }
};

// heap

template <typename T>
class heap{
    public:
    heap(): is_max_heap{true}, array_{}{}
    void swim(size_t idx){
        while(true){
            if((array_[idx]>array_[father(idx)]) == is_max_heap){
                std::swap(array_[idx],array_[father(idx)]);
                idx = father(idx);
            }
            else break;
        }
    }
    void sink(size_t idx){
        while(true){
            if((right_child(idx)<array_.getSize() && array_[idx]<array_[right_child(idx)]) == is_max_heap){
                std::swap(array_[idx],array_[right_child(idx)]);
                idx = right_child(idx);
            }
            else if((left_child(idx)<array_.getSize() && array_[idx]<array_[left_child(idx)]) == is_max_heap){
                std::swap(array_[idx],array_[left_child(idx)]);
                idx = left_child(idx);
            }
            else break;
        }
    }
    void insert(const T& input){
        size_t last_idx = array_.getSize();
        array_.insert(T,last_idx);
        swim(last_idx);
    }
    T extract_root(){
        T output = array_[0];
        std::swap(array_[0],array_[array_.getSize()-1]);
        array_.remove(array_.getSize()-1);
        sink(0);
    }
    void setMaxHeap(){is_max_heap=true;}
    void setMinHeap(){is_max_heap=false;}
    size_t father(size_t child_idx){return (child_idx-1)/2;}
    size_t left_child(size_t father_idx){return father_idx*2+1;}
    size_t right_child(size_t father_idx){return father_idx*2+2;}
    private:
    bool is_max_heap;
    dynamic_array<T> array_;
};






#endif