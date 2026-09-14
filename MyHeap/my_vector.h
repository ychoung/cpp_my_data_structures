#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector 
{
private:
    int* arr;
    int capacity;
    int size;

    void resize(); // reallocate new array

public:
    MyVector(int init_capacity = 2); 
    ~MyVector();
    
    int at(int);
    void push_back(int);
    void pop_back();
    void set(int, int);
    int get_size();

    int& operator[](int);
};

#endif