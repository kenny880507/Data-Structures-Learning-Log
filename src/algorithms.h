#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "containers.h"

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
    return access_impl(it, index, iterator::type{});
}

// search function


// is_sort function
template <typename iterator>
bool is_sort(iterator begin, iterator end){
    
}



















#endif