#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <vector>
#include <numeric>
#include "int_buffer.h"
#include "int_sorted.h"
int_sorted sort(const int *begin, const int *end);
void selectionSort(int* first,  int* last);
void f(int_buffer buf);
//void f1(int_sorted buf);
int main() {
//    int_buffer b(10);
//    int_buffer b1(b.begin(), b.size());
//    int_buffer b2(b);
//    int_buffer b3 = std::move(b);
//    srand(time(NULL));
//    int_sorted s;
//    s.print();
//    for (int i = 0; i < 100; i++) {
//        s.insert(rand() % 100 + 1);
//        s.print();
//    }


    std::vector<double> selSortVec;
    std::cout << "-----------------------\n";
    for (int i = 0; i < 5; i++) {
        int_buffer b1(40000);
        for (int & randelement : b1) {
            randelement = (rand() % 1000 + 1);
        }
        auto start = std::chrono::steady_clock::now();
        selectionSort(b1.begin(), b1.end());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = (end-start);
        std::cout << i <<". SelectionSort:\t" << elapsed.count() << "ms\n";
        selSortVec.push_back(elapsed.count());
    }

    std::vector<double> sortVec;
    std::cout << "-----------------------\n";
    for (int i = 0; i < 5; i++) {
        int_buffer b1(40000);
        for (int & randelement : b1) {
            randelement = (rand() % 1000 + 1);
        }
        auto start = std::chrono::steady_clock::now();
        int_sorted sorted = sort(b1.begin(), b1.end());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = (end-start);
        std::cout<<i << ". Sort:\t" << elapsed.count() << "ms\n";
        sortVec.push_back(elapsed.count());
    }

    std::vector<double> stdSortVec;
    std::cout << "-----------------------\n";
    for (int i = 0; i < 5; i++) {
        int_buffer b1(40000);
        for (int & randelement : b1) {
            randelement = (rand() % 1000 + 1);
        }
        auto start = std::chrono::steady_clock::now();
        std::sort(b1.begin(),b1.end());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = (end-start);
        std::cout<<i << ". std::sort:\t" << elapsed.count() << "ms\n";
        stdSortVec.push_back(elapsed.count());
    }
    double selSortAverage = std::accumulate(selSortVec.begin(), selSortVec.end(), 0.0) / selSortVec.size();
    double sortAverage = std::accumulate(sortVec.begin(), sortVec.end(), 0.0) / sortVec.size();
    double stdSortAverage = std::accumulate(stdSortVec.begin(), stdSortVec.end(), 0.0) / stdSortVec.size();
    std::cout << "-----------------------\n";
    std::cout << "-----tid selectionSort() medel:\t\t" << selSortAverage << "ms\n";
    std::cout << "-----tid sort() medel:\t" << sortAverage << "ms\n";
    std::cout << "-----tid std::sort() medel:\t" << stdSortAverage << "ms\n";
    std::cout << "-----------------------\n";

    return 0;
}
void selectionSort(int* first,  int* last){
    for(int* current = first; current < last - 1; current++){
        for(int* next = current + 1; next < last; next++) {
            if (*next < *current ) {
                int temp = *current;
                *current= *next;
                *next = temp;
            }
        }
    }
}
int_sorted sort(const int *begin, const int *end) {
    if (begin == end){
        return int_sorted(nullptr, 0);
    }
    if (begin == end-1){
        return int_sorted(begin,1);
    }
    ptrdiff_t half = (end-begin)/2;
    const int* mid = begin + half;
    return sort( begin , mid ).merge( sort(mid, end ) );
}
/*
 * void f1(int_sorted buf){
    for (int i = 0; i < 10; i++) {
        buf.insert(rand() % 100 + 1);
    }
}
 */
/*
 * void f(int_buffer buf){

    std::cout << "add elements to buffer" << std::endl;
    for (int* i = buf.begin(); i != buf.end() ; i++){
        buf[*i] = ++*i;
    }
//    for (auto &e : buf) {
//        buf[e] = ++e;
//    }

    std::cout << "print elements from buffer" << std::endl;
//    for (const int* i = buf.begin(); i != buf.end() ; i++){
//        std::cout << *i <<"\t"<< i << "\n";
//    }
    // auto& kör const, enbart auto kör utan

    for( const auto& e :  buf ){
        std::cout << e << "\t" << &e << "\n";
    }

    //const int_buffer buff = buf;
    //used to use "const..begin() or const..end()"
}
 */