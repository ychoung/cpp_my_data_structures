#include <iostream>
#include "heap.h"

int main(int argc, char const *argv[])
{
    Heap heap;
    heap.push_raw_data(4);
    heap.push_raw_data(43);
    heap.push_raw_data(42);
    heap.push_raw_data(53);
    heap.push_raw_data(74);
    heap.push_raw_data(13);
    heap.push_raw_data(23);
    heap.push_raw_data(1);

    heap.print_heap();

    heap.heapify();

    std::cout << std::endl;
    heap.print_heap();

    heap.heap_sort();
    std::cout << std::endl;
    heap.print_heap();
    return 0;
}
