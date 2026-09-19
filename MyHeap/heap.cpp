#include "heap.h"



Heap::Heap()
{
    vec.push_back(-1);
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

void Heap::heapify()
{
    if(vec.get_size() <= 1) return; // heapify an empty heap. 

    int currentSize = vec.get_size() - 1; // real size

    for (size_t i = currentSize >> 1; i > 0; i--) // run through every parent node
    {
        heapify(i, currentSize);
    }
}

void Heap::heapify(int currentIdx, int currentSize)
{
    while((currentIdx << 1) <= currentSize) // until currentIdx is smaller and equal to the currentSize
    {
        if((currentIdx << 1) == currentSize) // when parent node has the last child
        {
            if(vec[currentIdx] < vec[currentSize])
            {
                swap(currentIdx, currentSize);

                break;
            }
            break;
        }

        int lchildIdx = currentIdx << 1; // left child
        int rchildIdx = (currentIdx << 1) + 1; //  right child

        if(vec[currentIdx] >= vec[lchildIdx] && vec[currentIdx] >= vec[rchildIdx]) break; // when subtree is perfect

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

void Heap::insert(int val)
{
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
    if(vec.get_size() <= 1) return; // when pop an empty heap

    int currentSize = vec.get_size() - 1;

    vec.set(1, vec[currentSize]);

    vec.pop_back();

    heapify(1, currentSize - 1);
}

void Heap::print_heap()
{
    if(vec.get_size() <= 1) return; // when print an empty heap

    int size = vec.get_size();

    for (size_t i = 1; i < size; i++)
    {
        std::cout << vec.at(i) << std::endl;
    }
    
}

void Heap::push_raw_data(int val)
{
    vec.push_back(val);
}

void Heap::heap_sort() // sort heap from lowest to largest value
{
    if(vec.get_size() <= 1) return; // when sort an emtpy heap

    heapify();

    int currentSize = vec.get_size() - 1;

    for (size_t i = currentSize; i > 1; i--) // iterate from current size to 1(the first element)
    {
        swap(1, i); // swap the largest with the last value

        heapify(1, i - 1); // bubble down the last value to the proper position and the second largest value will be palced at the first idex
    }
    
}
