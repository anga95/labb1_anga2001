//
// Created by AnGa on 2022-11-02.
//

#ifndef LABB1_ANGA2001_INT_BUFFER_H
#define LABB1_ANGA2001_INT_BUFFER_H

#include <iostream>
#include <cstdlib>
#define log(x) std::cout << x << "\n"

class int_buffer {
public:
    explicit int_buffer(size_t size);
    int_buffer(const int* source , size_t size);
    int_buffer(const int_buffer& rhs); // copyconstruct
    int_buffer(int_buffer&& rhs); // moveconstruct
    ~int_buffer();
    int_buffer & operator=(const int_buffer&rhs); // copy assign
    int_buffer & operator=(int_buffer&& rhs); // move assign
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    [[maybe_unused]] size_t size() const;
    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;

private:
    void swap(int_buffer& rhs);
    int* first;
    int* last;
};

#endif //LABB1_ANGA2001_INT_BUFFER_H

