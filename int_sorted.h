//
// Created by AnGa on 2022-11-10.
//

#ifndef LABB1_ANGA2001_INT_SORTED_H
#define LABB1_ANGA2001_INT_SORTED_H

#include <cstdio>
#include <cstdlib>
#include "int_buffer.h"

class int_sorted {
public:
    int_sorted() = default;
    int_sorted(const int* source, size_t size);
    size_t size() const;
    void insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted& merge_with) const;
    void print() const;
    int_sorted sort(const int *begin, const int *end);
private:
    int_buffer buffer = int_buffer(0);
};

#endif //LABB1_ANGA2001_INT_SORTED_H
