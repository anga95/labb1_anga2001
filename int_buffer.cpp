//
// Created by AnGa on 2022-11-02.
//

#include "int_buffer.h"
#include <algorithm>

int_buffer::int_buffer(size_t size)
    : first(new int[size]), last(first + size){
    //log("buffer: 1-arg CTR");
}

int_buffer::int_buffer(const int *source, size_t size)
    : int_buffer(std::distance(source, source+size)){
    auto target = this->first;
    std::copy(source, source+size, target);
    //log("buffer: 2-arg CTR");
}
int_buffer::int_buffer(const int_buffer &rhs)
    : int_buffer(rhs.first, rhs.size()) {
  // log("buffer: copy CTR");
}
int_buffer::int_buffer(int_buffer &&rhs)
    : first(nullptr), last(nullptr) {
    swap(rhs);
   // log("buffer: move CTR");
}
int_buffer::~int_buffer() {
    delete [] first;
   // log("buffer: destructor");
}

int_buffer &int_buffer::operator=(const int_buffer &rhs) {
    int_buffer copy(rhs);
    swap(copy);
    return *this;
  //  log("buffer: copy assign");
}
//move ass
int_buffer &int_buffer::operator=(int_buffer &&rhs) {
    swap(rhs);
    return *this;
  //  log("buffer: move asssign");
}

int &int_buffer::operator[](size_t index) {
    return *(begin() + index);
}

const int &int_buffer::operator[](size_t index) const {
    return *(begin() + index);
}

int *int_buffer::begin() { return first; }
int *int_buffer::end() { return begin() + size(); }
const int *int_buffer::begin() const { return first; }
const int *int_buffer::end() const { return begin() + size(); }
size_t int_buffer::size() const { return std::distance(first, last); }

void int_buffer::swap(int_buffer &rhs) {
    std::swap(first, rhs.first);
    std::swap(last, rhs.last);
}

