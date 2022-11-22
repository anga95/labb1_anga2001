#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <numeric>
#include "int_buffer.h"
#include "int_sorted.h"
//int_sorted sort(const int *begin, const int *end);
void selectionSort(int* first,  int* last);
//void f(int_buffer buf);
//void f1(int_sorted buf);
//int_buffer generate();

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
//int_buffer b(10);
//    for (auto &item : b) {
//        item = (rand() % 100+1);
//    }
//    for (auto &item: b) {
//        log(item);
//    }
//    int_sorted sorted(b.begin(),b.size());
//    log("\n");
//    for (auto &e:sorted) {
//        log(e);
//    }

    std::vector<double> selSortVec;
    std::cout << "-----------------------\n";
    for (int i = 0; i < 5; i++) {
        int_buffer b1(400000);
        for (int & randelement : b1) {
            randelement = (rand() % 1000 + 1);
        }
        auto start = std::chrono::steady_clock::now();
        selectionSort(b1.begin(), b1.end());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = (end-start);
        std::cout << i+1 <<". SelectionSort:\t" << elapsed.count() << "ms\n";
        selSortVec.push_back(elapsed.count());
    }

    std::vector<double> sortVec;
    std::cout << "-----------------------\n";
    for (int i = 0; i < 5; i++) {
        int_buffer b1(400000);
        for (int & randelement : b1) {
            randelement = (rand() % 1000 + 1);
        }
        auto start = std::chrono::steady_clock::now();
        int_sorted sorted(b1.begin(),b1.size());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = (end-start);
        std::cout<<i+1 << ". Sort:\t" << elapsed.count() << "ms\n";
        sortVec.push_back(elapsed.count());
    }

    std::vector<double> stdSortVec;
    std::cout << "-----------------------\n";
    for (int i = 0; i < 5; i++) {
        int_buffer b1(400000);
        for (int & randelement : b1) {
            randelement = (rand() % 1000 + 1);
        }
        auto start = std::chrono::steady_clock::now();
        std::sort(b1.begin(),b1.end());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = (end-start);
        std::cout<<i+1 << ". std::sort:\t" << elapsed.count() << "ms\n";
        stdSortVec.push_back(elapsed.count());
    }
    double selSortAverage = std::accumulate(selSortVec.begin(), selSortVec.end(),
                                            0.0) / selSortVec.size();
    double sortAverage = std::accumulate(sortVec.begin(), sortVec.end(),
                                         0.0) / sortVec.size();
    double stdSortAverage = std::accumulate(stdSortVec.begin(), stdSortVec.end(),
                                            0.0) / stdSortVec.size();
    std::cout << "-----------------------\n";
    std::cout << "selectionSort() medel:\t" << selSortAverage << "ms\n";
    std::cout << "sort() medel:\t\t\t" << sortAverage << "ms\n";
    std::cout << "std::sort() medel:\t\t" << stdSortAverage << "ms\n";
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