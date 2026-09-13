#include <iostream>
#include "my_linked_list.h"

bool brackets_checker(std::string);

int main(int argc, char const *argv[])
{

  

    std::cout << brackets_checker("())") << std::endl;

    return 0;
}

bool brackets_checker(std::string bracket) // understand how computer treats brackes using stack.
{
    MyLinkedList stack;

    for(char c : bracket)
    {
        if(c == '(' || c == '{' || c == '[' )
            stack.push_front(c);
        else if(c == '}' || c == ')' || c == ']')
        {
            int removed = stack.top();
            stack.pop_front();

            if(c == '}')
            {
                if(removed != '{')
                    return false;
            }
            else if(c == ']')
            {
                if(removed != '[')
                    return false;
            }
            else if(c == ')')
            {
                if(removed != '(')
                    return false;
            }
        }    
    }

    if(!stack.is_empty()) return false;

    return true;
    
}