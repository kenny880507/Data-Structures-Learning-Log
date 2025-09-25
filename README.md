# Data Structure Learning Log

This project is used to document the learning journey of data structures. I will be documenting my notes and coding exercises here.


## Outline

- [Data Structure](#data-structure)
- [C++](#c++)
- [Git](#git)
- [Reference](#reference)

## Data Structure

This section will introduce common containers in data structure. The content covers the definition of each container and the four fundamental operations: access, search, insert, and delete.

### Introduction to Data Structure

#### Array

- Definition: A structure in which elements are arranged contiguously in memory.
- Access: Due to its contiguous layout, it supports random access. The time complexity for access is `O(1)`.
- Search: For an unsorted array, searching requires traversal. The time complexity is `O(n)`.
- Insert: To insert an element, all data after the insertion point must be shifted one position to the right. The time complexity is `O(n)`. For a sorted array, binary search can be used to reduce the time complexity to `O(log n)`.
- Delete: To delete an element, all data after the deleted item must be shifted one position to the left. The time complexity is `O(n)`.

#### Linked List

- Definition: A linked list consists of a sequence of elements called `nodes`. Each `node` contains its own data and a pointer to the next `node`. Depending on whether `nodes` also include a pointer to the previous `node`, the list is classified as either singly linked or doubly linked.
  >For convenience, define two `nodes` as `previous` and `current`. `previous` is the `node` just before the operation position, while `current` is the `node` to be inserted into or deleted from the linked list. The pointer to the next `node` is defined as `next`.
- Access: Linked lists do not support random access. To locate a `node` at a specific position, traversal must begin from the head and proceed sequentially through the list, resulting in a time complexity of `O(n)`.
- Search: Similar to access, search requires starting from the head and comparing each node's data one by one until the target is found or the traversal ends. The time complexity is `O(n)`.
- Insert: **Once the insertion position is known**, the operation can be completed by updating just a few pointers. Set `current` to point to `previous->next`, then set `previous->next` to point to `current`. The time complexity is `O(1)`.
- Delete: Similar to insertion, **if the position of the node to be deleted is known**, the operation can be completed by adjusting the pointers of its surrounding nodes. First, use a variable `temp` to store the address of `current`. Then set `previous->next` to `current->next`, and finally free the `temp` (i.e., the current node). The time complexity is `O(1)`.
  >Without `temp`, it's not possible to free the memory of `current`.

#### Queue

- Definition: A queue is an abstract data structure (ADT) that can be implemented using either an `array` or a `linked list`. Its core principle is First-In-First-Out (FIFO), and it restricts random access—only allowing operations such as `enqueue`, `dequeue`, `front`, and `back`.
  >- `front`: return the first item of the queue.
  >- `back`: return the last item of the queue.
  >- `enqueue`: place a new item after original `back`, this item becomes a new `back`.
  >- `dequeue`: delete `front` from the queue, the next item becomes a new `front`.

- Access: If you want to access `i-th` item in the queue, you need to `dequeue` `(i-1)` times and check `front`. The time complextiy is `O(n)`.
- Search: The time complexity is `O(n)`, which is the same as `array` and `linked list`.
- Insert and Delete:
  - `Array`-based: In an `array`-based queue, either the `enqueue` or `dequeue` operation (depending on which end is designated as the head) may involve shifting elements, causing the time complexity to degrade to `O(n)`. By introducing the concept of a `circular array`, both `enqueue` and `dequeue` operations can be performed without shifting, maintaining a constant time complexity of `O(1)`.
    > A `circular array` is a clever way to utilize `array` space efficiently. It connects the head and tail of the array to form a logical circle, effectively solving the problem of wasted space and performance issues that arise when handling FIFO (First-In-First-Out) data structures like `queues`, especially after removing elements from the front.
  - `Linked list`-based: Similar to `linked list`, `enqueue` and `dequeue` operations performs a constant time complexity of `O(1)`.

#### Stack

- Definition: `Stack` is another ADT. It core principle is Last-In-First-Out (LIFO) only allowing actions such as `push`, `pop`, `top`.
  >- `top`: return the last item of the stack.
  >- `pop`: delete `top` from the stack, the previos item becomes a new `top`.
  >- `push`: insert a new item into the stack, this item becomes a new `top`.
- Access: If you want to access `i-th` item in the stack, it is essential to `pop` all items above and check `top`. The time complextiy is `O(n)`.
- Search: Need to traversal the stack and the time complexity is `O(n)`.
- Insert: A single `push` action performs a time complexity of `O(1)`.
- Delete: A single `pop` action performs a time complexity of `O(1)`.

#### Hash Table

- Definition: At the lowest level, the implementation uses an `array`. Data is input as `key`-`value` pairs, where the `key` is typically a string or an integer. A hash function converts the `key` into a `hash value` (a non-negative integer), which is then mapped to an `index` in the underlying array.
  >A good hash function should satisfy the following criteria:
  >- Fast computation: The hash function should be computed as quickly as possible to avoid becoming a performance bottleneck.
  >- Uniform distribution: For a large number of input keys, the hash values generated should be evenly distributed across the hash table’s array space to minimize collisions.
  >- Low collision rate: The probability of different keys producing the same hash value should be as low as possible.

- Access: A hash table does not support `value` retrieval by `index`.
- Search: 
  - Average case - Since each `value` has a corresponding `key`, converting the `key` into an `index` allows us to determine whether the `value` exists in the hash table. The time complexity is `O(1)`.
  - Worst case - When severe hash collisions occur, many distinct `keys` are mapped to the same `index`. In such cases, we must rely on a collision resolution strategy to handle the situation. If all `keys` are mapped to a single location, searching for a specific key degrades into a linear scan through a long `linked list` or `array`, resulting in a time complexity of `O(n)`.
- Insert:
  - Average case - The time required to compute the hash function and assign the `value` to a specific position in the `array` is constant, so the time complexity is `O(1)`.
  - Worst case - Severe hash collisions can cause insertion operations to take additional time to locate an available position. The time complexity degrade to `O(n)`.
- Delete:
  - Average case - The time required to compute the hash function and delete the `value` from a specific position in the `array` is constant, so the time complexity is `O(1)`.
  - Worst case - Under severe collisions, it is necessary to linearly traverse all collided entries to locate and delete the target, causing the time complexity to degrade to `O(n)`.

#### Tree

- Definition:
- Access:
- Search:
- Insert:
- Delete:

#### Heap

- Definition:
- Access:
- Search:
- Insert:
- Delete:

#### Graph

- Definition:
- Access:
- Search:
- Insert:
- Delete:

### Cheat Sheet

#### Big-O Complexity Chart[^1]

![Big-O Complexity Chart](documents/images/Data%20Structure/Big-O%20Complexity%20Chart.png)

#### Common Data Structure Operations[^1]

![Big-O Complexity Chart](documents/images/Data%20Structure/Common%20Data%20Structure%20Operations.png)[^1]

#### Array Sorting Algorithms[^1]

![Big-O Complexity Chart](documents/images/Data%20Structure/Array%20Sorting%20Algorithms.png)

## C++

This section records the C++ syntax used in my code and demonstrates how to implement different data structures using C++.

The execution strategy is below:

1. A container is responsible for managing its internal data and iterators. It provides member functions such as  and  to access those iterators.
2. The container does not directly implement fundamental data structure operations.
3. The four fundamental operations of data structures—access, search, insert, and delete—are implemented using global template functions.
4. These functions take iterators as parameters instead of the container itself, allowing operations to be performed through the iterator interface.

### Syntax

#### Class

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

#### function

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

#### Overload

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

#### Template

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

#### Iterator

An iterator is a pointer-like object used to traverse elements within a container, such as an array or a linked list. Different types of iterators support different operations, such as moving forward, backward, or performing random access. Iterators generalize the concept of a pointer, allowing for uniform interaction with various data structures.

```C++
#include <vector>

std::vector<int> numbers = {1, 2, 3, 4, 5};

// Get an iterator to the beginning of the vector
std::vector<int>::iterator it = numbers.begin();

// Move the iterator forward
it++;

// Access the element the iterator points to
int value = *it;
```

#### Tag Type

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

### Implement of Data Structure

### Data Structure vs. C++ STL Container

| Data Structure | C++ STL Container | Notes |
| :--- | :--- | :--- |
| **Array** | `std::array`, `std::vector` | `std::array` has a fixed size at compile time, while `std::vector` can be resized dynamically. |
| **Linked List** | `std::list`, `std::forward_list` | `std::list` is a doubly linked list, `std::forward_list` is a singly linked list. |
| **Tree** | `std::set`, `std::map`, `std::multiset`, `std::multimap` | These are typically implemented using **balanced binary search trees** (e.g., Red-Black Trees) to keep data sorted. |
| **Heap** | `std::priority_queue` | The underlying data structure is a heap (by default, a max-heap), providing efficient access to the largest element. |
| **Queue** | `std::queue` | A First-In, First-Out (FIFO) container. |
| **Stack** | `std::stack` | A Last-In, First-Out (LIFO) container. |
| **Graph** | **No direct equivalent** | Often simulated using an **adjacency matrix** (`std::vector<std::vector<int>>`) or an **adjacency list** (`std::vector<std::list<int>>`). |
| **Hash Table** | `std::unordered_set`, `std::unordered_map` | Provides average O(1) time complexity for lookups, but the data is not sorted. |

## Git

This section will include some notes about usage of Git and GitHub.

### Initialize Local Repository.

#### 1. Make a new directory named `<project-name>` and change directory

Open the terminal, and input command below:

```Bash
mkdir <project-name>
cd <project-name>
```

#### 2. Initialize local git repository

Use `init` to initialize directory to a Git repository.

```Bash
git init
```

#### 3. Create any file in the `<project-name>` directory

Generate any file in project directory.

#### 4. Use git command to stage and commit changes

Use `add` to stage the change for the files.
Use `commit` to commit staged changes.

```Bash
git add .   #stage all files
git add <file-name>   #stage specific file
git commit -m "<any-comment>"   #commit the already staged changes with a comment.
```

### Make connection between computer and GitHub

#### 1. Check if an SSH key already exists on the computer

Open the terminal (MacOS, Linux) or Git Bash (Windows), and input command below:

```Bash
ls -al ~/.ssh
```

If there are some file like `id_ed25519.pub`, it means the computer already has a public key. Skip to `step 3.`.

If the output is `No such file or directory`, proceed to `step 2.` to create a new key.

#### 2. Create a new SSH key

Enter the following command in the terminal to generate a new key pair. Ed25519 algorithm is used here.

```Bash
ssh-keygen -t ed25519 -C "<GitHub-mail>"
```

Once the command is executed, the system will prompt you to specify a location to save the key. Press Enter to accept the default path.

The system will then ask you to enter a passphrase. This serves as an extra layer of protection and is recommended. Each time the key is used, the passphrase will be required. You may choose to set one, or press Enter to leave it empty.

Once completed, two files will be generated in your `.ssh` directory:
- `id_ed25519`: This is your private key. Do not share this file with anyone!
- `id_ed25519.pub`: This is your public key. We will copy the contents of this file to GitHub.

#### 3. Add public key to your GitHub

Check the contents of your public key by the following command in terminal or Git Bash:

```Bash
cat ~/.ssh/id_ed25519.pub
```

_Copy_ the contents in `id_ed25519.pub`.

Login to GitHub > Click your profile picture > `Settings` > Click `SSH and GPG keys` in left-hand menu > Click `New SSH key` > Type `<device-name>` in **Title** field > Paste public key contents in **Key** field > Click `Add SSH key`

#### 4. Veify the SSH connection

Enter the command below to test:

```Bash
ssh -T git@github.com
```

- The first time you connect, the system will ask if you trust the connection. Type `yes` and press Enter.
- If you previously set a passphrase for your key, you’ll be prompted to enter it now.
- If you see a message like `“Hi <your-username>! You've successfully authenticated...”`, it means your SSH key has been set up successfully!

### Make connection between local repo and GitHub repo

#### 1. Create a new empty repository on GitHub

- Log in to GitHub and click the + icon in the top-right corner.
- Select `New repository` from the dropdown menu.
- Enter your repository name `<repository-name>`.
- Do not select any options (e.g., Add a README file), since you already have the files locally.
- Click `Create repository` to finish.

#### 2. Connect to local repository

Use the command below in terminal to link local and remote repos:

```Bash
git remote add origin git@github.com:<GitHub-user-name>/<GitHub-repo-name>.git
```

#### 3. Push local contents to GitHub

Use `git push` command to upload local contents to GitHub repo.
>- The main branch might be `main` or `master`. Use `git branch` to check.
>- For first push, a `-u origin main` parameter must be added.

```Bash
git push -u origin main
```

### Common Git Commands

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

## Reference

[^1]: [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)