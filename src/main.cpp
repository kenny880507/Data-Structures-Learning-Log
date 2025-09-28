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
    dynamic_array<int> ary(data,3);
    print_container(ary);
    dash("[insert]");
    for(int i = 0; i < 5; ++i){
        ary.insert(i,ary.getSize());
    }
    dash("[remove]");
    for(int i = 0; i < 3; ++i){
        ary.remove(1);
    }
    dash("[access]");
    int index = 3;
    std::cout << "container[" << index << "]=" << access(ary.begin(),index) << std::endl; 
    dash("[search]");
    int value = 4;
    search(ary.begin(),ary.end(),value);
    value = 500;
    search(ary.begin(),ary.end(),value);
    system("pause");
}