# Data Structures and Algorithms Learning Log

This project is used to document the learning journey of data structures and algorithms. I will be documenting my notes and coding exercises here.

# Outline

- [Data Structure](#data-structure)
- [C++](#c++)
- [Git](#git)
- [Reference](#reference)

# Data Structure

This section will introduce common containers in data structure. The content covers the definition of each container and the four fundamental operations: access, search, insert, and delete.
> Since `delete` is a reserved keyword in C++, the `delete()` function is usually replaced with alternative names such as `remove()`.

## Introduction to Data Structure

### Array

![array](documents/images/Data%20Structure/array.png)

- **Definition**: A structure in which elements are arranged contiguously in memory.
- Access: Due to its contiguous layout, it supports random access. The time complexity for access is `O(1)`.
- **Search**: For an unsorted array, searching requires traversal. The time complexity is `O(n)`.
- **Insert**: To insert an element, all data after the insertion point must be shifted one position to the right. The time complexity is `O(n)`. For a sorted array, binary search can be used to reduce the time complexity to `O(log n)`.
- **Delete**: To delete an element, all data after the deleted item must be shifted one position to the left. The time complexity is `O(n)`.

### Linked List

![Linked List](documents/images/Data%20Structure/linked_list.png)

- **Definition**: A linked list consists of a sequence of elements called `nodes`. Each `node` contains its own data and a pointer to the next `node`. Depending on whether `nodes` also include a pointer to the previous `node`, the list is classified as either singly linked or doubly linked.
  >For convenience, define two `nodes` as `previous` and `current`. `previous` is the `node` just before the operation position, while `current` is the `node` to be inserted into or deleted from the linked list. The pointer to the next `node` is defined as `next`.
- **Access**: Linked lists do not support random access. To locate a `node` at a specific position, traversal must begin from the head and proceed sequentially through the list, resulting in a time complexity of `O(n)`.
- **Search**: Similar to access, search requires starting from the head and comparing each node's data one by one until the target is found or the traversal ends. The time complexity is `O(n)`.
- **Insert**: **Once the insertion position is known**, the operation can be completed by updating just a few pointers. Set `current` to point to `previous->next`, then set `previous->next` to point to `current`. The time complexity is `O(1)`.
- **Delete**: Similar to insertion, **if the position of the node to be deleted is known**, the operation can be completed by adjusting the pointers of its surrounding nodes. First, use a variable `temp` to store the address of `current`. Then set `previous->next` to `current->next`, and finally free the `temp` (i.e., the current node). The time complexity is `O(1)`.
  >Without `temp`, it's not possible to free the memory of `current`.

### Queue

![Queue](documents/images/Data%20Structure/queue.png)

- **Definition**: A queue is an abstract data structure (ADT) that can be implemented using either an `array` or a `linked list`. Its core principle is First-In-First-Out (FIFO), and it restricts random access—only allowing operations such as `enqueue`, `dequeue`, `front`, and `back`.
  >- `front`: return the first item of the queue.
  >- `back`: return the last item of the queue.
  >- `enqueue`: place a new item after original `back`, this item becomes a new `back`.
  >- `dequeue`: delete `front` from the queue, the next item becomes a new `front`.

- **Access**: If you want to access `i-th` item in the queue, you need to `dequeue` `(i-1)` times and check `front`. The time complextiy is `O(n)`.
- **Search**: The time complexity is `O(n)`, which is the same as `array` and `linked list`.
- **Insert and Delete**:
  - `Array`-based: In an `array`-based queue, either the `enqueue` or `dequeue` operation (depending on which end is designated as the head) may involve shifting elements, causing the time complexity to degrade to `O(n)`. By introducing the concept of a `circular array`, both `enqueue` and `dequeue` operations can be performed without shifting, maintaining a constant time complexity of `O(1)`.
    > A `circular array` is a clever way to utilize `array` space efficiently. It connects the head and tail of the array to form a logical circle, effectively solving the problem of wasted space and performance issues that arise when handling FIFO (First-In-First-Out) data structures like `queues`, especially after removing elements from the front.
  - `Linked list`-based: Similar to `linked list`, `enqueue` and `dequeue` operations performs a constant time complexity of `O(1)`.

### Stack

![Stack](documents/images/Data%20Structure/stack.png)

- **Definition**: `Stack` is another ADT. It core principle is Last-In-First-Out (LIFO) only allowing actions such as `push`, `pop`, `top`.
  >- `top`: return the last item of the stack.
  >- `pop`: delete `top` from the stack, the previos item becomes a new `top`.
  >- `push`: insert a new item into the stack, this item becomes a new `top`.
- **Access**: If you want to access `i-th` item in the stack, it is essential to `pop` all items above and check `top`. The time complextiy is `O(n)`.
- **Search**: Need to traversal the stack and the time complexity is `O(n)`.
- **Insert**: A single `push` action performs a time complexity of `O(1)`.
- **Delete**: A single `pop` action performs a time complexity of `O(1)`.

### Hash Table

- **Definition**: At the lowest level, the implementation uses an `array`. Data is input as `key`-`value` pairs, where the `key` is typically a string or an integer. A hash function converts the `key` into a `hash value` (a non-negative integer), which is then mapped to an `index` in the underlying array.
  >A good hash function should satisfy the following criteria:
  >- Fast computation: The hash function should be computed as quickly as possible to avoid becoming a performance bottleneck.
  >- Uniform distribution: For a large number of input keys, the hash values generated should be evenly distributed across the hash table’s array space to minimize collisions.
  >- Low collision rate: The probability of different keys producing the same hash value should be as low as possible.

- **Access**: A hash table does not support `value` retrieval by `index`.
- **Search**: 
  - Average case - Since each `value` has a corresponding `key`, converting the `key` into an `index` allows us to determine whether the `value` exists in the hash table. The time complexity is `O(1)`.
  - Worst case - When severe hash collisions occur, many distinct `keys` are mapped to the same `index`. In such cases, we must rely on a collision resolution strategy to handle the situation. If all `keys` are mapped to a single location, searching for a specific key degrades into a linear scan through a long `linked list` or `array`, resulting in a time complexity of `O(n)`.
- **Insert**:
  - Average case - The time required to compute the hash function and assign the `value` to a specific position in the `array` is constant, so the time complexity is `O(1)`.
  - Worst case - Severe hash collisions can cause insertion operations to take additional time to locate an available position. The time complexity degrade to `O(n)`.
- **Delete**:
  - Average case - The time required to compute the hash function and delete the `value` from a specific position in the `array` is constant, so the time complexity is `O(1)`.
  - Worst case - Under severe collisions, it is necessary to linearly traverse all collided entries to locate and delete the target, causing the time complexity to degrade to `O(n)`.

### Tree

![Tree](documents/images/Data%20Structure/tree.png)

- **Definition (General)**: A tree is a non-linear, hierarchical data structure composed of a finite set of `nodes` connected by `edges`. It has the following characteristics:
  1. There is a special `node` called the `root`, which has no `parent`.
  2. Except for the root, every `node` has exactly one `parent`.
  3. Between any two `nodes` in the tree, there exists exactly one simple path—meaning the tree contains no cycles.

- **Term**
  - `root`: The top `node` of a tree, which is the only `node` without `parent`.
  - `parent`: A `node` directly above another `node`, connected to it via an `edge`.
  - `child`: A `node` directly below another `node`, connected to it via an `edge`.
  - `sibling`: `Nodes` that share the same `parent`.
  - `leaf/external node`: A `node` with no `children`.
  - `internal node`: A `node` that has at least one `child` (i.e., not a `leaf`).
  - `degree of node`: The number of `children` a `node` has.
  - `degree of tree`: The maximum degree among all `nodes` in the tree.
  - `depth`: The length of the path (number of edges) from the `root` to a given `node`.
  - `height`: The length of the longest path from a `node` to its farthest `leaf`. The `height` of the tree is the `height` of its `root`.

- **Traversal**
   - Depth-First Search (DFS): This type of traversal explores the branches of a tree as deeply as possible before backtracking, continuing until all `leaves` are reached. There are three main types:

        | Traversal Type | Order (N = Node, L = Left, R = Right) | Description |
        | :--- | :--- | :--- |
        | **Preorder** | N → L → R | Visit the `node` first, then traverse the left and right subtrees. |
        | **Inorder** | L → N → R | Traverse the left subtree, visit the `node`, then traverse the right subtree. |
        | **Postorder** | L → R → N | Traverse both subtrees first, then visit the `node`. |

   - Breadth-First Search (BFS): Commonly referred to as Level Order Traversal, this method visits the `nodes` of a tree level by level, from left to right.

- **Binary Tree**
  
  ![Binary Tree](documents/images/Data%20Structure/binary_tree.png)

  A binary tree is a tree data structure composed of `nodes`, each of which has at most, two `children`, referred to as left and right `nodes`.

- **Types Of Binary Trees**
  - **Full Binary Tree**: A binary tree in which every `node` has either 0 or 2 `children`—no `node` has only one `child`.

    ![Full Binary Tree](documents/images/Data%20Structure/full_binary_tree.png)

  - **Perfect Binary Tree**: A full binary tree in which all internal `nodes` have exactly two children and all `leaves` are at the same depth.

    ![Perfect Binary Tree](documents/images/Data%20Structure/perfect_binary_tree.png)
  
  - **Complete Binary Tree**: A binary tree in which all levels are fully filled except possibly the last, which is filled from left to right.

    ![Complete Binary Tree](documents/images/Data%20Structure/complete_binary_tree.png)

- **Binary Search Tree**
    
    ![Binary Search Tree](documents/images/Data%20Structure/BST.png)
    
  A binery search tree (BST) is also a binary tree. Some rules must be obeyed to call a binary tree binary search tree:
  - The nodes contain a `key` and a `value`.
  - The `key` must be comparable.
  - The `key` of the left child must be less than that of its parent `node`.
  - The `key` of the right child must be greater than that of its parent `node`.
  - The left and the right subtree of a particular `node` will also, in turn, be binary search trees.

- **Balance of BST**
  The structure may differ according to the insertion order of a BST. The nodes in a extremely unbalanced BST may only have right nodes or left nodes. The time complextiy of search operation of balanced and extremely unbalanced tree are `O(log n)` and `O(n)`. Many derived BSTs share similar structures, with differences arising from their distinct balancing strategies.

### Heap

- **Definition**: A heap is a complete tree, meaning all levels are fully filled except possibly the last, which is filled from left to right. Additionally, heaps maintain a hierarchical order—which is reffered to as sorting rule— between parent and child nodes, but not between siblings. In a max heap, the root node is the largest, whereas in a min heap, the root node is the smallest. The heap mentioned in this page focused on binary heap.
- **Access**: Because the position of data in heap is not strictly sorted by insertion or value, accessing a specific index in a heap is meaningless.
- **Search**: A `extract_root` function used to extract the root (extreme data) has an `O(1)` time complexity. Search for a non-extreme data need a traversl, which is `O(n)` time complexity.
- **Insert**: To insert a data into a heap must consider the hierarchical rule. The steps of insertion is shown below:
  1. Insert new data to the end of the heap.
  2. Compare the new node and its father node. If they violate the rule swap their position.
  3. Repeat step 2 until the new node and its father node comply with the sorting rule.
The above operation is called `swim`. Its time complexity is `O(log n)`.
- **Delete**: Deletion of a node in a heap also needs to comply with sorting rule. The below steps called `sink` has a time complexity of `O(log n)`:
  1. Swap the target node and the last node. For convenience, we will refer to the last node as node A.
  2. Delete the target node which is now at the end of the heap.
  3. Compare node A and its child nodes (2 in a binary heap). If they violate the rule swap the bigger one and node A.
  4. Repeat step 3 until node A comply with the sorting rule.

### Graph

![graph](documents/images/Data%20Structure/graph.png)

- **Definition**: A graph consists of nodes and edges. Edges represent for the relationship of nodes. If all edges are bidirectional, it is called undirected graph (left in the above image). Otherwise, it is called directed graph (right in above image). In the right graph, A, C and B form a cycle because you can start at A and finally return to it. Although edges exist between B, C, and E, they do not form a cycle.
- **Application**: Graphs are a fundamental concept used to model connections between objects. They are applied in numerous real-world scenarios. For example, in social networks like Facebook, graphs connect users and suggest friends. In navigation systems like Google Maps, they represent cities and roads to find the shortest route. Search engines also use graphs to rank web pages based on their links, and in biology, graphs help visualize complex interactions between proteins.
  >Graphs differ significantly from the aforementioned data structures; their purpose is not to store data, but to represent relationships between data and solve optimization problems. Therefore, we do not discuss its access, search, insert, or delete operations.

## Cheat Sheet

### Big-O Complexity Chart[^1]

![Big-O Complexity Chart](documents/images/Data%20Structure/Big-O%20Complexity%20Chart.png)

### Common Data Structure Operations[^1]

![Big-O Complexity Chart](documents/images/Data%20Structure/Common%20Data%20Structure%20Operations.png)

### Array Sorting Algorithms[^1]

![Big-O Complexity Chart](documents/images/Data%20Structure/Array%20Sorting%20Algorithms.png)

# C++

This section records the C++ syntax used in my code and demonstrates how to implement different data structures using C++.

The execution strategy is below:

1. ~~A container is responsible for managing its internal data and iterators. It provides member functions such as `begin()` and `end()` to access those iterators.~~
2. ~~The container does not directly implement fundamental data structure operations.~~
3. ~~The four fundamental operations of data structures—access, search, insert, and delete—are implemented using global template functions.~~
4. ~~These functions take iterators as parameters instead of the container itself, allowing operations to be performed through the iterator interface.~~

  >It was observed during execution that arrays and linked lists handle insertions and deletions differently, particularly regarding capacity management, making it unsuitable to use templates for a unified function.


1. Containers not only store data, but also offer member functions like `begin()` and `end()` for iterator access, and `insert()` and ~~`delete()`~~ `remove()` for adding or removing elements.
   >- `begin()`: return the iterator that point to the first data.
   >- `end()`: return the iterator that point to the address just after the final data.
2. The `access()` and `search()` functions are implemented as external template functions that operate on iterators.

## Syntax

### Class

A C++ class acts as a blueprint for an object, defining its attributes (data) and behaviors (functions). It encapsulates both data and the functions that operate on that data into a single, cohesive unit.

```C++
class MyClass {
private:
    // Attributes (data members)
    int my_number;

public:
    // Constructor
    MyClass(int num) : my_number(num) {}

    // Method (member function)
    int getNumber() {
        return my_number;
    }
};
```

### function

A function is a block of code designed to perform a specific task. It can optionally define input parameters to allow the caller to pass arguments and can also return a value as output. In C++, functions can exist independently or as member functions of a class.

```C++
// Function outside of a class
int add(int a, int b) {
    return a + b;
}

// Function inside a class (member function)
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};
```

### Overload

Function overloading allows multiple functions in the same scope to share the same name, as long as they have a different number or type of parameters. The compiler automatically selects the correct function to execute based on the arguments you provide.

```C++
// Overload with different parameter types
void print(int value) {
    // prints an integer
}

void print(double value) {
    // prints a double
}

// Overload with different number of parameters
void print(int a, int b) {
    // prints two integers
}
```

### Template

A template is a tool for generic programming that allows functions or classes to work with multiple data types without needing to rewrite the code for each type. This promotes code reusability. A template declaration starts with the keyword `template`, followed by parameters enclosed in angle brackets `< >`.

```C++
// Template function for adding any two numbers
template<typename T>
T add(T a, T b) {
    return a + b;
}

// Template class for a generic container
template<typename T>
class MyContainer {
private:
    T data;
public:
    MyContainer(T value) : data(value) {}
};
```

### Iterator

An iterator is a pointer-like object used to traverse elements within a container, such as an array or a linked list. Different types of iterators support different operations, such as moving forward, backward, or performing random access. Iterators generalize the concept of a pointer, allowing for uniform interaction with various data structures. Types of iterator used in my code is shown in the table below:

| Feature | Forward Iterator | Bidirectional Iterator | Random Access Iterator |
| :--- | :--- | :--- | :--- |
| **Tag Type** | `forward_iterator_tag` | `bidirectional_iterator_tag` | `random_access_iterator_tag` |
| **Movement** | Single-pass, **Forward Only** (`++`) | **Forward and Backward** (`++`, `--`) | Arbitrary Jumps (Random Access) |
| **Supported Operations** | `*it`, `++it`, `it == end`, `it != end` | All Forward Ops + **`--it`**, **`it--`** | All Bidirectional Ops + **Pointer Arithmetic** (`it+N`), **Comparison** (`<`, `>`), **Indexing** (`it[N]`) |
| **Relative Comparison** | **No** (`<`, `>`) | **No** (`<`, `>`) | **Yes** (`<`, `>`, `<=`, `>=`) |
| **Distance Calculation** | Requires $O(N)$ traversal | Requires $O(N)$ traversal | **$O(1)$** (Constant Time) via subtraction (`end - begin`) |
| **Example Data Structure** | **Linked List** | **Doubly Linked List**, **Tree** | **Array**, **Dynamic Array** |

### Tag Type

Tag type is basically a empty struct. Tag types are used as a mechanism to distinguish between overloaded functions. For example, two tag type is defined:

```C++
struct type1_tag{};
struct type2_tag{};
```

The tag type is passed as a parameter to the overloaded function, enabling different behaviors depending on the tag:

```C++
template<typename Iterator>
typename Iterator::value_type do_something(Iterator it, type1_tag){
    ...
}
template<typename Iterator>
typename Iterator::value_type do_something(Iterator it, type2_tag){
    ...
}
```
The reason for using this syntax is that different iterators support different operations—not all iterators can move forward, backward, or perform random access.

## Implement of Data Structure

As mentioned above, the implement of data structure is via C++ language. The source code splits into three file:

- `container.h`: The definition of classes and some functions about data structure—such as `search` and `access`.
- `algorithms.h`: Contains the sorting functions might be used on data structure.
- `main.cpp`: Main code that uses classes and functions in `container.h` and `algorithms.h` to demonstrates the implementation of data structure.

The following table compares the container classes of different datastructure in C++ STL and this project:

| Data Structure | C++ STL Container | My container | Notes |
| :--- | :--- | :--- | :--- |
| **Array** | `std::array`, `std::vector` | `dynamic_array` | `std::array` has a fixed size at compile time, while `std::vector` can be resized dynamically. |
| **Linked List** | `std::list`, `std::forward_list` | `linked_list` | `std::list` is a doubly linked list, `std::forward_list` is a singly linked list. |
| **Tree** | `std::set`, `std::map`, `std::multiset`, `std::multimap` | - | These are typically implemented using **balanced binary search trees** (e.g., Red-Black Trees) to keep data sorted. |
| **Heap** | `std::priority_queue` | - | The underlying data structure is a heap (by default, a max-heap), providing efficient access to the largest element. |
| **Queue** | `std::queue` | `queue` | A First-In, First-Out (FIFO) container. |
| **Stack** | `std::stack` | `stack` | A Last-In, First-Out (LIFO) container. |
| **Graph** | **No direct equivalent** | - | Often simulated using an **adjacency matrix** (`std::vector<std::vector<int>>`) or an **adjacency list** (`std::vector<std::list<int>>`). |
| **Hash Table** | `std::unordered_set`, `std::unordered_map` | `hash_table` | Provides average O(1) time complexity for lookups, but the data is not sorted. |

## Big 5 of C++ class

For each data structure class in C++, there are three construct method and two assignment method—namely "Big Five"–need to be define. In addition, the destructor is important to prevent memory leak. The following table illustrate the implementation of these function:

| Special Member Function | English Name | Symbol/Prototype | Responsibility |
| :--- | :--- | :--- | :--- |
| **1. Constructor** | Constructor | `MyClass();` | Responsible for object initialization and **resource acquisition** (Acquisition). |
| **2. Destructor** | Destructor | `~MyClass();` | Responsible for object cleanup and **resource release** (Release). Key to the **RAII principle**. |
| **3. Copy Constructor** | Copy Constructor | `MyClass(const MyClass& other);` | Creates a new, independent object from an existing one via **Deep Copy**. |
| **4. Copy Assignment** | Copy Assignment Operator | `MyClass& operator=(const MyClass& other);` | Allows an existing object to be **assigned** the value of another. Requires self-assignment check and memory handling. |
| **5. Move Constructor** | Move Constructor | `MyClass(MyClass&& other);` | **Transfers** resource ownership (e.g., pointers) from a temporary object, typically setting the source to `nullptr`. |
| **6. Move Assignment** | Move Assignment Operator | `MyClass& operator=(MyClass&& other);` | Allows an existing object to be move-assigned (resource transfer) from a temporary object. |

## dynamic_array Implementation Summary

The `dynamic_array` class manages a contiguous block of memory, mimicking the structure and behavior of `std::vector`.

### Private Members

These members manage the internal state and resources of the array.

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `data` | `T*` | **Raw pointer** to the dynamically allocated memory block where all elements are stored. It is the primary resource managed by the class. |
| `capacity` | `size_t` | The **total allocated space** (in terms of elements) currently available in the `data` array. |
| `size` | `size_t` | The **current number of elements** actually stored and initialized in the array. (`size <= capacity`). |

### Public Members (Non-Big Six Functions)

These functions provide the primary interface for users to interact with the array and control its size.

* **`iterator begin()` / `iterator end()`**
    * **Purpose:** Provide the standard iterator interface to enable traversal. `begin()` points to the first element; `end()` points **one position past** the last element.

    ```cpp
    iterator begin(){return iterator(data);}
    iterator end(){return iterator(data)+static_cast<ptrdiff_t>(size);}
    ```

* **`size_t getSize() const`**
    * **Purpose:** Returns the current number of elements in the array (the value of `size`).

    ```cpp
    size_t getSize() const{return size;}
    ```

* **`void insert(const T& target, size_t position)`**
    * **Purpose:** Inserts a new element at the specified `position`. Time complexity is **$O(N)$** due to shifting.
    * **Logic:** Checks if `expand()` is needed. It shifts elements to the right using iterators, places the `target` element at the insertion point, and increments `size`.

    ```cpp
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
        // ... (visualization code omitted)
    }
    ```

#### Inner Class: iterator

The nested `iterator` class implements all operations required for a **Random Access Iterator**.

* **Type Aliases:**
    ```cpp
    using value_type = T;
    using iterator_type = random_access_iterator_tag;
    ```
* **Key Operators:** Implements `operator*()`, `operator->()`, and all comparison operators.
* **Random Access Support:** Implements pointer arithmetic (`operator+`, `operator+=`, `operator-`, `operator-=`) for $O(1)$ jumps and distance calculation.
* **Increment/Decrement:** Implements both pre-fix (`operator++()`) and post-fix (`operator++(int)`) increment/decrement operators.

* **`void remove(size_t position)`**
    * **Purpose:** Deletes the element at the specified `position`. Time complexity is **$O(N)$** due to shifting.
    * **Logic:** Shifts all subsequent elements one position to the left using iterators to close the gap, and decrements `size`.

    ```cpp
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
        // ... (visualization code omitted)
    }
    ```

### Capacity Management

* **`void expand()`**
    * **Purpose:** Increases the memory allocation of the array when it is full (`size == capacity`).
    * **Logic:** Doubles the current `capacity`, allocates a new memory block (`T* temp`), copies the existing data, deletes the old `data` block, and updates the `data` pointer. This ensures **Amortized $O(1)$** insertion time.

    ```cpp
    void expand(){
        if(capacity == size){
            // ... (visualization code omitted)
            capacity *= 2;
            T* temp = new T[capacity];
            for(int i = 0; i<size;++i) temp[i] = data[i];
            delete [] data;
            data = temp;
            // ... (visualization code omitted)
        } else {
            return;
        }
    }
    ```

## linked_list Implementation Summary

The `linked_list` is implemented as a singly linked list, utilizing nodes and pointers for efficient element manipulation.

### Private Members

These members manage the internal state and structure of the list.

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `head` | `node*` | Pointer to the **first node** (the head) of the list. It is `nullptr` if the list is empty. |
| `size` | `size_t` | The **current number of elements** (nodes) in the list. |

### Public Members (Non-Big Six Functions)

These functions provide the primary interface for users to interact with the list.

* **`iterator begin()` / `iterator end()`**
    * **Purpose:** Provide the standard iterator interface. `begin()` returns an iterator pointing to the `head` node. `end()` returns an iterator pointing to `nullptr` (the standard stopping condition).

    ```cpp
    iterator begin() {return iterator(head);}
    iterator end() {return iterator(nullptr);}
    ```

* **`size_t getSize() const`**
    * **Purpose:** Returns the current number of elements in the list (the value of `size`).

    ```cpp
    size_t getSize() const {return size;}
    ```

* **`void insert(const T& target, size_t position)`**
    * **Purpose:** Inserts a new node containing `target` at the specified `position`. Time complexity is **$O(N)$** to find the position, but **$O(1)$** for the actual pointer manipulation.
    * **Logic:** Allocates a new node. If `position == 0`, the new node becomes the new `head`. Otherwise, it traverses to the node *before* the insertion point and updates its `next` pointer. Finally, it increments `size`.

    ```cpp
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
        // ... (visualization code omitted)
    }
    ```

* **`void remove(size_t position)`**
    * **Purpose:** Deletes the node at the specified `position`. Time complexity is **$O(N)$** to find the node, but **$O(1)$** for the pointer manipulation and memory release.
    * **Logic:** Finds the node *before* the target. It then updates the `next` pointer to skip the target node, stores the target node in a temporary pointer (`temp`), and uses `delete temp` to free the memory. Finally, it decrements `size`.

    ```cpp
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
        // ... (visualization code omitted)
    }
    ```

#### Inner Class: iterator

The nested `iterator` class implements the **Forward Iterator** interface.

* **Type Aliases:**
    ```cpp
    using value_type = T;
    using iterator_type = forward_iterator_tag;
    ```
* **Core Operators:** Implements `operator*()`, `operator->()`, and comparison operators (`==`, `!=`).
* **Traversal Support:** Implements the pre-fix (`operator++()`) and post-fix (`operator++(int)`) increment operators, which move the internal pointer (`ptr`) to the next node (`ptr->next`).

#### Inner Class: node

The nested `node` class defines the element structure of the list.

* **Members:** Contains the element data (`T data`) and a pointer to the next node (`node* next = nullptr`).
* **Friendship:** Declares `iterator` and `linked_list` as `friend` classes to allow them to directly access and modify the private `data` and `next` pointer of the node.

## deque (Double-Ended Queue) Implementation Summary

The `deque` is implemented using a **circular array** to achieve constant time complexity for operations at both ends.

### Private Members

These members manage the internal state and circular array logic.

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `data` | `T*` | **Raw pointer** to the dynamically allocated underlying array. |
| `capacity` | `size_t` | The **total allocated space** in the array. |
| `size_` | `size_t` | The **current number of elements** stored in the deque. |
| `front_` | `size_t` | The **physical index** in the array where the first element is located. This index wraps around. |

### Public Members (Non-Big Six Functions)

These functions provide the primary interface for users, focusing on efficient endpoint access.

* **`iterator begin()` / `iterator end()`**
    * **Purpose:** Provide the standard iterator interface. `begin()` points to the first logical element (index 0). `end()` points one position past the last logical element (`size_`).

    ```cpp
    iterator begin(){return iterator(this, 0);}
    iterator end(){return iterator(this, size_);}
    ```

* **`size_t size() const`**
    * **Purpose:** Returns the current number of elements in the deque.

    ```cpp
    size_t size() const {return size_;}
    ```

* **`T back()` / `T front()`**
    * **Purpose:** Returns the value of the last and first elements, respectively, without removal.

    ```cpp
    T back(){
        return *(--end());
    }
    T front(){
        return *(begin());
    }
    ```

* **`void push_back(const T& value)`**
    * **Purpose:** Adds an element to the back (tail) of the deque. Time complexity is **$O(1)$** (Amortized).
    * **Logic:** Checks for `expand()`. Uses modulo arithmetic `(front_ + size_) % capacity` to calculate the insertion index, then increments `size_`.

    ```cpp
    void push_back(const T& value){
        if(size_==capacity) expand();
        size_t physic_idx = (front_+size_)%capacity;
        data[physic_idx] = value;
        ++size_;
    }
    ```

* **`void push_front(const T& value)`**
    * **Purpose:** Adds an element to the front (head) of the deque. Time complexity is **$O(1)$** (Amortized).
    * **Logic:** Checks for `expand()`. Decrements and wraps `front_` using modulo arithmetic, then inserts the value and increments `size_`.

    ```cpp
    void push_front(const T& value){
        if(size_==capacity) expand();
        front_ = mod(front_-1,capacity);
        data[front_] = value;
        ++size_;
    }
    ```

* **`void pop_back()` / `void pop_front()`**
    * **Purpose:** Removes the element from the back or front, respectively. Time complexity is **$O(1)$**.
    * **Logic:** `pop_back` simply decrements `size_`. `pop_front` increments `front_` and decrements `size_`, using modulo arithmetic for wrap-around.

    ```cpp
    void pop_back(){
        if(size_==0) return;
        --size_;
    }
    void pop_front(){
        if(size_==0) return;
        --size_;
        front_ = (front_+1)%capacity;
    }
    ```

* **`void expand()`**
    * **Purpose:** Reallocates memory when the array is full.
    * **Logic:** Doubles capacity, allocates new memory, moves elements to the new block starting at index 0 to simplify the circular structure, deletes the old data, and resets `front_ = 0`. This is an **$O(N)$** operation.

    ```cpp
    void expand(){
        // ... (visualization code omitted)
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
        // ... (visualization code omitted)
    }
    ```

#### Inner Class: iterator

The nested `iterator` class implements the **Random Access Iterator**.

* **Type Aliases:**
    ```cpp
    using value_type = T;
    using iterator_type = random_access_iterator_tag;
    ```
* **Key Members:** Manages the container pointer (`deque_ptr`), **physical pointer** (`T* ptr`), and **logical index** (`size_t logic_idx`).
* **Complexity:** Implements full pointer arithmetic and comparison operators. Requires extensive use of the `mod()` helper function to correctly map the logical index to the physical pointer location within the circular array.

---

## `stack` Implementation Summary

The `stack` class implements the LIFO (Last-In-First-Out) principle by using the `deque` container as an **adapter**.

### Private Members

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `deque_` | `deque<T>` | The underlying container used to store the stack elements. |

### Public Members (Non-Big Six Functions)

All core stack operations are delegated to the `deque`'s $O(1)$ endpoint methods.

* **`void push(const T& value)`**
    * **Purpose:** Adds an element to the top of the stack. Time complexity is **$O(1)$** (Amortized).
    * **Logic:** Delegates to the deque's back insertion: `deque_.push_back(value);`
* **`void pop()`**
    * **Purpose:** Removes the element from the top of the stack. Time complexity is **$O(1)$**.
    * **Logic:** Delegates to the deque's back removal: `deque_.pop_back();`
* **`T top()`**
    * **Purpose:** Returns the value of the top element without removing it.
    * **Logic:** Delegates to the deque's back access: `deque_.back();`
* **`size_t size() const` / `bool empty() const`**
    * **Purpose:** Returns the size and checks if the stack is empty.

---

## `queue` Implementation Summary

The `queue` class implements the FIFO (First-In-First-Out) principle by using the `deque` container as an **adapter**.

### Private Members

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `deque_` | `deque<T>` | The underlying container used to store the queue elements. |

### Public Members (Non-Big Six Functions)

All core queue operations are delegated to the `deque`'s $O(1)$ endpoint methods.

* **`void enqueue(const T& value)`**
    * **Purpose:** Adds an element to the back of the queue. Time complexity is **$O(1)$** (Amortized).
    * **Logic:** Delegates to the deque's back insertion: `deque_.push_back(value);`
* **`void dequeue()`**
    * **Purpose:** Removes the element from the front of the queue. Time complexity is **$O(1)$**.
    * **Logic:** Delegates to the deque's front removal: `deque_.pop_front();`
* **`T front()` / `T back()`**
    * **Purpose:** Returns the value of the front and back elements without removing them.
    * **Logic:** Delegates to the deque's front/back access: `deque_.front()` and `deque_.back()`.
* **`size_t size() const` / `bool empty() const`**
    * **Purpose:** Returns the size and checks if the queue is empty.

---

## `BST` (Binary Search Tree) Implementation Summary

The `BST` implements a fundamental binary search tree structure with distinct iterators for Depth-First Search (DFS) traversals.

### Private Members

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `root` | `node*` | Pointer to the root node of the tree. |
| `delete_subtree` | `void` helper | Recursively cleans up memory for all nodes in a subtree. Essential for the destructor and copy assignment. |
| `clone_subtree` | `node*` helper | Recursively performs deep copying of an entire subtree. Essential for the copy constructor and copy assignment. |

### Public Members (Non-Big Six Functions)

* **`void insert(const T& data)` (Override)**
    * **Purpose:** Inserts a new value while maintaining the BST property (left < parent < right).
    * **Logic:** Traverses the tree to find the correct leaf position. Performance is **$O(\log N)$** (best/average case) or **$O(N)$** (worst-case, unbalanced).
* **`void remove(const T& data)` (Override)**
    * **Purpose:** Deletes a node. Handles zero, one, or two children cases.
    * **Logic:** Finds the node. If the node has two children, it is replaced by its **inorder successor** (the smallest node in the right subtree) to maintain the BST property. Performance is **$O(\log N)$** or **$O(N)$**.
* **`bool search(const T& data)` (Override)**
    * **Purpose:** Finds a value by traversing the tree based on comparison. Performance is **$O(\log N)$** or **$O(N)$**.

#### Inner Class: `node`

The nested `node` class defines the element structure of the BST.

* **Members:** Contains the element value (`T value`) and pointers to the left and right children (`node* left`, `node* right`).

#### Traversal Iterators (`pre_iterator`, `in_iterator`, `post_iterator`)

Three separate classes are defined, all implementing the **Forward Iterator** interface, using an internal `stack<node*>` to manage non-recursive traversal state.

* **`preorder_begin()` / `inorder_begin()` / `postorder_begin()`:**
    * **Purpose:** Returns the respective DFS iterator starting at the root.
* **`preorder_end()` / `inorder_end()` / `postorder_end()`:**
    * **Purpose:** Returns the designated `end` iterator (where `current` is `nullptr`) for loop termination.

---

## `heap` (Binary Heap) Implementation Summary

The `heap` implements a complete binary tree structure (Max-Heap or Min-Heap) using a `dynamic_array` as its base.

### Private Members

| Member | Type | Purpose |
| :--- | :--- | :--- |
| `is_max_heap` | `bool` | Flag that determines the heap type (`true` for Max-Heap, `false` for Min-Heap). |
| `array_` | `dynamic_array<T>` | The underlying container that stores the heap elements in contiguous memory. |

### Public Members (Non-Big Six Functions)

* **`void insert(const T& input)`**
    * **Purpose:** Adds a new element to the heap. Performance is **$O(\log N)$**.
    * **Logic:** Inserts the element at the end of the `array_` (using `array_.insert`) and then calls **`swim(last_idx)`** to restore the heap property by moving the new element up the tree.

    ```cpp
    void insert(const T& input){
        size_t last_idx = array_.getSize();
        array_.insert(input,last_idx);
        swim(last_idx);
    }
    ```

* **`T extract_root()`**
    * **Purpose:** Removes and returns the root element (the extreme value). Performance is **$O(\log N)$**.
    * **Logic:** Swaps the root with the last element, removes the last element (using `array_.remove`), and then calls **`sink(0)`** to restore the heap property by moving the new root down the tree.

* **`void setMaxHeap()` / `void setMinHeap()`**
    * **Purpose:** Changes the `is_max_heap` flag.

    ```cpp
    void setMaxHeap(){is_max_heap=true;}
    void setMinHeap(){is_max_heap=false;}
    ```

* **`size_t father(size_t child_idx)` / `size_t left_child(...)` / `size_t right_child(...)`**
    * **Purpose:** Utility functions to calculate the index of parent or child nodes based on the array's $2i+1$ heap convention.

### Capacity Management

* **`void swim(size_t idx)`**
    * **Purpose:** Restores the heap property by moving an element *up* the tree towards the root. Used after insertion.
    * **Logic:** Compares the element at `idx` with its parent; if they violate the heap rule, they are swapped, and the process repeats. This moves the element at most $\log N$ levels.

* **`void sink(size_t idx)`**
    * **Purpose:** Restores the heap property by moving an element *down* the tree towards the leaves. Used after `extract_root`.
    * **Logic:** Compares the element at `idx` with its largest (or smallest) child; if they violate the rule, it is swapped with the child, and the process repeats. This moves the element at most $\log N$ levels.

# Git

This section will include some notes about usage of Git and GitHub.

## Initialize Local Repository.

**1. Make a new directory named `<project-name>` and change directory**

Open the terminal, and input command below:

```Bash
mkdir <project-name>
cd <project-name>
```

**2. Initialize local git repository**

Use `init` to initialize directory to a Git repository.

```Bash
git init
```

**3. Create any file in the `<project-name>` directory**

Generate any file in project directory.

**4. Use git command to stage and commit changes**

Use `add` to stage the change for the files.
Use `commit` to commit staged changes.

```Bash
git add .   #stage all files
git add <file-name>   #stage specific file
git commit -m "<any-comment>"   #commit the already staged changes with a comment.
```

## Make connection between computer and GitHub

**1. Check if an SSH key already exists on the computer**

Open the terminal (MacOS, Linux) or Git Bash (Windows), and input command below:

```Bash
ls -al ~/.ssh
```

If there are some file like `id_ed25519.pub`, it means the computer already has a public key. Skip to `step 3.`.

If the output is `No such file or directory`, proceed to `step 2.` to create a new key.

**2. Create a new SSH key**

Enter the following command in the terminal to generate a new key pair. Ed25519 algorithm is used here.

```Bash
ssh-keygen -t ed25519 -C "<GitHub-mail>"
```

Once the command is executed, the system will prompt you to specify a location to save the key. Press Enter to accept the default path.

The system will then ask you to enter a passphrase. This serves as an extra layer of protection and is recommended. Each time the key is used, the passphrase will be required. You may choose to set one, or press Enter to leave it empty.

Once completed, two files will be generated in your `.ssh` directory:
- `id_ed25519`: This is your private key. Do not share this file with anyone!
- `id_ed25519.pub`: This is your public key. We will copy the contents of this file to GitHub.

**3. Add public key to your GitHub**

Check the contents of your public key by the following command in terminal or Git Bash:

```Bash
cat ~/.ssh/id_ed25519.pub
```

_Copy_ the contents in `id_ed25519.pub`.

Login to GitHub > Click your profile picture > `Settings` > Click `SSH and GPG keys` in left-hand menu > Click `New SSH key` > Type `<device-name>` in **Title** field > Paste public key contents in **Key** field > Click `Add SSH key`

**4. Veify the SSH connection**

Enter the command below to test:

```Bash
ssh -T git@github.com
```

- The first time you connect, the system will ask if you trust the connection. Type `yes` and press Enter.
- If you previously set a passphrase for your key, you’ll be prompted to enter it now.
- If you see a message like `“Hi <your-username>! You've successfully authenticated...”`, it means your SSH key has been set up successfully!

## Make connection between local repo and GitHub repo

**1. Create a new empty repository on GitHub**

- Log in to GitHub and click the + icon in the top-right corner.
- Select `New repository` from the dropdown menu.
- Enter your repository name `<repository-name>`.
- Do not select any options (e.g., Add a README file), since you already have the files locally.
- Click `Create repository` to finish.

**2. Connect to local repository**

Use the command below in terminal to link local and remote repos:

```Bash
git remote add origin git@github.com:<GitHub-user-name>/<GitHub-repo-name>.git
```

**3. Push local contents to GitHub**

Use `git push` command to upload local contents to GitHub repo.
>- The main branch might be `main` or `master`. Use `git branch` to check.
>- For first push, a `-u origin main` parameter must be added.

```Bash
git push -u origin main
```

## Common Git Commands

~~`git pull`: download the newest changes to local repo and merge to loacal branch. Equivalent to `git fetch` + `git merge`.~~
>Barely using `git pull` is not recommended. Use `git pull --rebase` or `git fetch` + `git rebase` instead.

`git fetch`: download changes from the remote repository.

`git rebase`: moves your local commits to the top of the remote commits. This keeps your commit history clean and linear, without unnecessary merge commits.
>Never use `rebase` on public branches! If you perform a `rebase` on a public branch that others are working on—such as main—you’ll rewrite the commit history of that branch. This can cause other developers’ local histories to diverge from the remote history, leading to major confusion and conflicts.

`git pull --rebase`: equivalent to `git fetch` + `git rebase`.

`git checkout <branch-name>`: change to `<branch-name>` branch.

`git checkout -b <new-branch>`: create a new branch `<new-branch>` and change branch to `<new-branch>`.

`git push -u origin <new-branch>`: `-u` is used for pushing new branch. Git will set up tracking information for this branch on the remote.
>- Git uses origin as a default alias pointing to the remote repo.
>- If the branch already exists on the remote, a simple `git push` is enough.

# Reference

1. <https://www.bigocheatsheet.com/>
2. <https://zerotomastery.io/cheatsheets/data-structures-and-algorithms-cheat-sheet/>

[^1]: [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)