//
// Created by AnGa on 2022-11-10.
//

#include <utility>
#include "int_sorted.h"
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size)
        : buffer(source, size) {}

void int_sorted::insert(int value) {
    int_sorted temp2(&value, 1);
    *this = merge(temp2);
}

const int *int_sorted::begin() const { return buffer.begin(); }
const int *int_sorted::end() const { return buffer.begin() + buffer.size(); }
size_t int_sorted::size() const { return buffer.size(); }

int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    int_sorted c(buffer.begin(),buffer.size() + merge_with.size());
    const int* a_ptr = this->begin();
    const int* b_ptr = merge_with.begin();
    size_t c_index = 0;

    while (  a_ptr != this->end() && b_ptr != merge_with.end() ) {
        if (*a_ptr < *b_ptr){
            c.buffer[c_index++] = *a_ptr++;
        }
        else{
            c.buffer[c_index++] = *b_ptr++;
        }
    }

    while(a_ptr != this->end()) {
        c.buffer[c_index++] = *a_ptr++;
    }
    while(b_ptr != merge_with.end()){
        c.buffer[c_index++] = *b_ptr++;
    }
    return c;
}

void int_sorted::print() const {
    int previous = *buffer.begin();
    const int* LAST_ELEMENT = buffer.end() - 1;

    std::cout << "size[" << buffer.size()<< "]   {";
    for (const int* it = buffer.begin(); it != buffer.end(); it++) {
        std::cout << *it;
        if (it != LAST_ELEMENT ){ std::cout << ", "; }

        if (previous > *it){
            std::cout << "\t listan är ej sorterad!";
            break;
        }
        previous = *it;
    }
    std::cout << "}\n";
}

