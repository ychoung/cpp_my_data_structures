#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "my_vector.h"

class Heap
{
private:
    MyVector vec;

    void swap(int, int);

public:
    Heap();
    ~Heap();

    void insert(int);
    void pop();
    void print_heap();

};


#endif