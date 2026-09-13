#include "my_linked_list.h"

MyLinkedList::MyLinkedList()
{
    head = nullptr;
}

MyLinkedList::~MyLinkedList()
{
    while(head != nullptr)
    {
        Node* removed = head->next;

        delete head; head = nullptr;

        head = removed;
    }
}

void MyLinkedList::push_front(int value)
{
    head = new Node{value, head};
}

void MyLinkedList::print_all() const
{
    Node* tmp = head;

    while(tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;

        tmp = tmp->next;
    }
}

void MyLinkedList::push_back(int value)
{
    if(head ==  nullptr) 
    {
        push_front(value);
        return;
    }

    Node* newNode = new Node{value, nullptr};
    Node* tmp = head;

    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    
    tmp->next = newNode;
}

void MyLinkedList::pop_front()
{
    if(head == nullptr) return;

    Node* newHead = head->next;

    delete head; head = nullptr;

    head = newHead;
}

void MyLinkedList::pop_back()
{
    if(head == nullptr) return;

    Node* tmp = head;

    if(tmp->next == nullptr)
    {
        delete head; head = nullptr;
        return;
    }

    while(tmp->next->next != nullptr)
    {
        tmp = tmp->next;
    }

    Node* removed = tmp->next;
    tmp->next = nullptr;

    delete removed; removed = nullptr;

}

int MyLinkedList::top()
{
    if(is_empty()) return -1;

    return head->data;
}

bool MyLinkedList::is_empty()
{
    return head == nullptr;
}
