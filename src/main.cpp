#include "containers.h"
#include "algorithms.h"
#include <iostream>
#include <string>

void dash(){
    for(int i = 0; i < 10; ++i){
        std::cout << "=";
    }
    std::cout << std::endl;
}
void dash(const std::string str){
    for(int i = 0; i < 10; ++i){
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << str << std::endl;
}

int main(){
    // dynamic_array test
    int data[3] = {0,1,2};
    std::cout << "\ndynamic array implementation"<<std::endl;
    dash("[construct]");
    dynamic_array<int> DA(data,3);
    print_container(DA);
    dash("[insert]");
    for(int i = 0; i < 5; ++i){
        DA.insert(i,DA.getSize());
    }
    dash("[remove]");
    for(int i = 0; i < 3; ++i){
        DA.remove(1);
    }
    dash("[access]");
    int index = 3;
    std::cout << "container[" << index << "]=" << access(DA.begin(),index) << std::endl; 
    dash("[search]");
    int value = 4;
    search(DA.begin(),DA.end(),value);
    value = 500;
    search(DA.begin(),DA.end(),value);
    std::cout<<std::endl;

    // //linked list test
    std::cout << "\nlinked list implementation"<<std::endl;
    dash("[construct]");
    linked_list<int> LL(data,3);
    print_container(LL);
    dash("[insert]");
    for(int i = 0; i < 5; ++i){
        LL.insert(i,LL.getSize());
    }
    dash("[remove]");
    for(int i = 0; i < 3; ++i){
        LL.remove(1);
    }
    dash("[access]");
    index = 3;
    std::cout << "container[" << index << "]=" << access(LL.begin(),index) << std::endl; 
    dash("[search]");
    value = 4;
    search(LL.begin(),LL.end(),value);
    value = 500;
    search(LL.begin(),LL.end(),value);

    // stack test
    std::cout << "\nstack implementation"<<std::endl;
    dash("[construct]");
    stack<int> ST(data,3); // {0, 1, 2}
    print_container(ST);
    dash("[push]");
    for(int i = 0; i < 5; ++i){
        // 堆疊使用 push
        ST.push(i + 3); // push 3, 4, 5, 6, 7
    }
    std::cout << "stack after push: ";
    print_container(ST); 
    dash("[top]");
    std::cout << "stack top: " << ST.top() << std::endl; // 7

    dash("[pop]");
    for(int i = 0; i < 3; ++i){
        std::cout << "pop value: " << ST.top() << std::endl;
        ST.pop();
    }
    std::cout << "stack after pop: ";
    print_container(ST); // {0, 1, 2, 3, 4} (4是頂部)

    // queue test
    std::cout << "\nqueue implementation"<<std::endl;
    dash("[construct]");
    queue<int> QU(data,3); // {0, 1, 2}
    print_container(QU);
    dash("[enqueue]");
    for(int i = 0; i < 5; ++i){
        // 佇列使用 enqueue
        QU.enqueue(i + 3); // enqueue 3, 4, 5, 6, 7
    }
    std::cout << "queue after enqueue: ";
    // 最終內容應為 {0, 1, 2, 3, 4, 5, 6, 7}，0是前端，7是後端
    print_container(QU);
    
    dash("[front]");
    std::cout << "queue front: " << QU.front() << std::endl; // 0

    dash("[dequeue]");
    for(int i = 0; i < 3; ++i){
        std::cout << "dequeue value: " << QU.front() << std::endl;
        QU.dequeue();
    }
    std::cout << "queue after dequeue: ";
    print_container(QU); // {3, 4, 5, 6, 7} (3是前端，7是後端)
    system("pause");
}