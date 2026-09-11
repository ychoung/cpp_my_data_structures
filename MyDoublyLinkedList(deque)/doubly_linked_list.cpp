#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::push_front(int value)
{
    if(head == nullptr && tail == nullptr)
    {
        head = tail = new Node(value, nullptr, nullptr);
        return;
    }

    Node* newNode = new Node(value, tail, nullptr);
    tail->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::print_all() const
{
    Node* tmp = head;
    while(tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

void DoublyLinkedList::push_back(int value)
{
    if(head == nullptr && tail == nullptr)
    {
        head = tail = new Node(value, nullptr, nullptr);
        return;
    }

    Node* newNode = new Node(value, nullptr, tail);
    tail->next = newNode;
    tail = newNode;

}
