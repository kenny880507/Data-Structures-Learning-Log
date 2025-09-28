#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "containers.h"
#include <iostream>

// is_sort function
template <typename iterator>
bool is_sort(iterator begin, iterator end){
    if(begin==end){
        return true; // for empty container, return true
    } else {
        iterator it = begin; // prevent to modify input iterator
        auto previous_value = *it;
        ++it;
        while(it != end){
            if(*it < previous_value) return false;
            previous_value = *it;
            ++it;
        }
        return true;
    }
}



















#endif