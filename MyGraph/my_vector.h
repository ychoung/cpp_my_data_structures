#ifndef MYVECTOR_H
#define MYVECTOR_H

template<typename T>
class MyVector 
{
private:
    T* arr;
    int capacity;
    int size;

    void resize(); // reallocate new array

public:
    MyVector(int init_capacity = 1);
    MyVector(const MyVector<T>&);
    ~MyVector();
    
    T& at(int);
    void push_back(T);
    void pop_back();
    void set(int, T);
    int get_size();

    T& operator[](int);
    MyVector& operator=(const MyVector<T>&);
};

template<typename T>
inline MyVector<T>::MyVector(int init_capacity): capacity(init_capacity), arr(new T[init_capacity]), size(0)
{
    // capacity = init_capacity;
    // arr = new T[capacity];
    // size = 0;
}

template <typename T>
inline MyVector<T>::MyVector(const MyVector<T>& other)
{
    capacity = other.capacity;
    size = other.size;
    arr = new T[capacity];

    for(int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
}

template<typename T>
inline MyVector<T>::~MyVector()
{
    delete[] arr;
}

template<typename T>
inline void MyVector<T>::resize() 
{
    int newCapacity = capacity * 2;
    T* newArr = new T[newCapacity];

    for (int i = 0; i < capacity; i++)
    {
        newArr[i] = arr[i];
    }
    
    delete[] arr; arr = nullptr;

    capacity = newCapacity;
    arr = newArr;
}

template<typename T>
inline T& MyVector<T>::at(int index)
{
    if(index < 0 || index >= size)
        throw std::out_of_range("Vector index out of bounds!");
    
    return arr[index];
}

template<typename T>
inline void MyVector<T>::push_back(T value)
{
    
    if(size >= capacity) // resize when the size is about to exceed capacity
    {
        resize();
    }

    arr[size++] = value;
}

template<typename T>
inline void MyVector<T>::pop_back()
{
    if(get_size() != 0) --size;
}

template<typename T>
inline void MyVector<T>::set(int idx, T val)
{
    if(idx < size && idx >= 0)
        arr[idx] = val;
}

template<typename T>
inline int MyVector<T>::get_size()
{
    return size;
}

template<typename T>
inline T& MyVector<T>::operator[](int idx)
{
    return arr[idx];
}

template <typename T>
inline typename MyVector<T>::MyVector &MyVector<T>::operator=(const MyVector<T>& other)
{
    capacity = other.capacity;
    size = other.size;
    arr = new T[capacity];

    for(int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
    
    return *this;
}

#endif