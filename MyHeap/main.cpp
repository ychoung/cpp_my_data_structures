#include <iostream>
#include "heap.h"

int main(int argc, char const *argv[])
{
    Heap heap;
    heap.insert(15);
    heap.insert(30);
    heap.insert(20);
    heap.insert(45);
    heap.insert(50);

    std::cout << "[최초 힙 상태]" << std::endl;
    heap.print_heap();

    // 2. 1회 팝 (가장 큰 50 제거)
    heap.pop();
    std::cout << "\n[pop 1회 후]" << std::endl;
    heap.print_heap();

    // 3. 2회 팝 (그다음 큰 45 제거)
    heap.pop();
    std::cout << "\n[pop 2회 후]" << std::endl;
    heap.print_heap();
    return 0;
}
