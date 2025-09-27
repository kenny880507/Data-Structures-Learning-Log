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
    int data[5] = {0,1,2,3,4};
    std::cout << "dynamic array implementation"<<std::endl;
    dash("[construct]");
    dynamic_array<int> ary(data,5);
    print_container(ary);
    dash("[insert]");
    for(int i = 0; i < 10; ++i){
        ary.insert(i,ary.getSize());
    }
    dash("[remove]");
    for(int i = 0; i < 10; ++i){
        ary.remove(ary.getSize()-1);
    }
    dash("[access]");
    int index = 3;
    std::cout << "container[" << index << "]=" << access(ary.begin(),index) << std::endl; 
    system("pause");
}