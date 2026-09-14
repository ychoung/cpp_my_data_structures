#include "heap.h"



Heap::Heap()
{
}

Heap::~Heap()
{
}


void Heap::swap(int idx1, int idx2)
{
    int tmp = vec[idx1];
    vec[idx1] = vec[idx2];
    vec[idx2] = tmp;
}

void Heap::insert(int val)
{
    if(vec.get_size() == 0)
    {
        vec.push_back(-1);
        vec.push_back(val);
        return;
    }

    vec.push_back(val);

    int currentIdx = vec.get_size() - 1;

    while(vec[currentIdx] > vec[currentIdx >> 1])
    {
        if(currentIdx == 1) break;

        int newChild = vec[currentIdx >> 1];
        vec.set(currentIdx, newChild);
        vec.set(currentIdx >> 1, val);

        currentIdx = currentIdx >> 1;
    }
}

void Heap::pop()
{
    if(vec.get_size() == 0) return; // when pop an empty heap

    int currentSize = vec.get_size() - 1;

    vec.set(1, vec[currentSize]);

    vec.pop_back();

    currentSize -= 1;
    int currentIdx = 1;
    while(currentIdx < currentSize)
    {
        if(currentIdx << 1 > currentSize) break;

        if(currentIdx << 1 == currentSize)
        {
            if(vec[currentIdx] < vec[currentSize])
            {
                swap(currentIdx, currentSize);

                break;
            }
            break;
        }
        
        int lchildIdx = currentIdx << 1;
        int rchildIdx = (currentIdx << 1) + 1;

        if(vec[currentIdx] >= vec[lchildIdx] && vec[currentIdx] >= vec[rchildIdx]) break;

        if(vec[lchildIdx] > vec[rchildIdx])
        {
            swap(currentIdx, lchildIdx);

            currentIdx <<= 1;
        }
        else
        {
            swap(currentIdx, rchildIdx);

            currentIdx = (currentIdx << 1) + 1;
        }
    }
}

void Heap::print_heap()
{
    if(vec.get_size() == 0) return; // when print an empty heap

    int size = vec.get_size();

    for (size_t i = 1; i < size; i++)
    {
        std::cout << vec.at(i) << std::endl;
    }
    
}
