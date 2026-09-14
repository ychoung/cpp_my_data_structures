#include "my_vector.h"

MyVector::MyVector(int init_capacity)
{
    capacity = init_capacity;
    arr = new int[capacity];
    size = 0;
}

MyVector::~MyVector()
{
    delete[] arr;
}

void MyVector::resize() 
{
    int newCapacity = capacity * 2;
    int* newArr = new int[newCapacity];

    for (int i = 0; i < capacity; i++)
    {
        newArr[i] = arr[i];
    }
    
    delete[] arr; arr = nullptr;

    capacity = newCapacity;
    arr = newArr;
}

int MyVector::at(int index)
{
    if(index < 0) return -1; // error msg
    if(index >= size) return -1; // when index is greater than and equal to size
    
    return arr[index];
}

void MyVector::push_back(int value)
{
    
    if(size >= capacity) // resize when the size is about to exceed capacity
    {
        resize();
    }

    arr[size++] = value;
}

void MyVector::pop_back()
{
    if(get_size() != 0) --size;
}

void MyVector::set(int idx, int val)
{
    if(idx < size && idx >= 0)
        arr[idx] = val;
}

int MyVector::get_size()
{
    return size;
}

int& MyVector::operator[](int idx)
{
    return arr[idx];
}


