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

int MyVector::at(int index)
{
    if(index < 0) return -1; // error msg
    if(index >= size) return -1; // error msg
    
    return arr[index];
}

void MyVector::push_back(int value)
{
    
    if(size >= capacity)
    {
        resize();
    }

    arr[size++] = value;
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
