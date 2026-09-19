#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "my_vector.h"

class Heap
{
private:
    MyVector vec;

    void swap(int, int);

    void heapify(int, int);

public:
    Heap();
    ~Heap();

    void insert(int);

    void pop();
    
    void print_heap();
    
    void push_raw_data(int);
    
    void heapify();
    
    void heap_sort();
};


#endif