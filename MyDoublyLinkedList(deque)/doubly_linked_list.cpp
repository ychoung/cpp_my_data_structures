#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    clear();
}

void DoublyLinkedList::push_front(int value)
{
    if(head == nullptr && tail == nullptr)
    {
        head = tail = new Node(value, nullptr, nullptr);
        return;
    }

    Node* newNode = new Node(value, head, nullptr);
    head->prev = newNode;
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

void DoublyLinkedList::print_reverse() const
{
    Node* tmp = tail;
    while(tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->prev;
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

void DoublyLinkedList::pop_front()
{
    if(head == nullptr) return; // 0 node

    if(head == tail) // only 1 node
    {
        clear();
        return;
    }

    Node* newHead = head->next;

    delete head; head = nullptr;

    newHead->prev = nullptr;

    head = newHead;
}

void DoublyLinkedList::pop_back()
{
    if(tail ==  nullptr) return; // 0 node

    if(head == tail) // only 1 node
    {
        clear();
        return;
    }

    Node* newTail = tail->prev;
    
    delete tail; tail = nullptr;

    newTail->next = nullptr;
    tail = newTail;
}

void DoublyLinkedList::insert(Node* target, int value)
{
    if(target == nullptr) return;

    if(target == head)
    {
        push_front(value);
        return;
    }

    Node* prev = target->prev;
    Node* newNode = new Node(value, target, prev);
    prev->next = newNode;
    target->prev = newNode;

}

void DoublyLinkedList::erase(Node* target)
{
    if(target == nullptr) return;

    if(target == head)
    {
        pop_front();
        return;
    }

    if(target == tail)
    {
        pop_back();
        return;
    }

    Node* prev = target->prev;
    Node* next = target->next;

    delete target; target = nullptr;

    prev->next = next;
    next->prev = prev;

}

void DoublyLinkedList::clear()
{
    while(head != nullptr)
    {
        Node* removed = head->next;

        delete head; head = nullptr;

        head = removed;
    }
    tail = nullptr;
}
