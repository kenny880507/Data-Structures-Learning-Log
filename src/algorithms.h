#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "containers.h"
#include <iostream>

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


// is_sort function
template <typename iterator>
bool is_sort(iterator begin, iterator end){
    if(begin>end){
        std::cout << "[ERROR] begin is lager than end.";
        return false;
    } else if(begin==end) {
        std::cout << "[ERROR] begin equals to end.";
        return false;
    } else {
        auto previous_value = *begin;
        ++begin;
        while(begin < end){
            if(*begin < previous_value) return false;
            previous_value = *begin;
            ++begin;
        }
        return true;
    }
}



















#endif