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
    std::cout << "dynamic array implementation"<<std::endl;
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
    std::cout << "linked list implementation"<<std::endl;
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
    system("pause");
}