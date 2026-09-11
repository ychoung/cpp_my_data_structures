#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector 
{
private:
    int* arr;
    int capacity;
    int size;

    void resize();

public:
    MyVector(int init_capacity = 2); 
    ~MyVector();
    
    int at(int index);
    void push_back(int value);
};

#endif