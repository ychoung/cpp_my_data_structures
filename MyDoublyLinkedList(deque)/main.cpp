#include "doubly_linked_list.h"

int main(int argc, char const *argv[])
{
    DoublyLinkedList dl;

    dl.push_front(24);
    dl.push_front(26);
    dl.push_front(23);
    dl.print_all();

    return 0;
}
