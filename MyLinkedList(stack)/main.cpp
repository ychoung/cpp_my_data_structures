#include <iostream>
#include "my_linked_list.h"

int main(int argc, char const *argv[])
{
    MyLinkedList list;

  

    list.push_front(25);
    list.push_front(23);
    list.push_front(26);
    list.push_front(21);
    list.push_back(30);
    list.pop_back();
    list.print_all();

    return 0;
}
