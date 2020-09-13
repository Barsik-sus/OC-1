#include "Stack.h"

Stack::Stack(int size)
{
    max_size = size;
    current_size = 0;
    stack->next = nullptr;
}


void Stack::push(char Data)
{
    if (current_size < max_size)
    {
        elem* new_elem = new elem();
        new_elem->Data = Data;
        new_elem->next = stack;
        stack = new_elem;
        current_size++;
    }
    else throw "Not enough storage";
  }


char Stack::pop()
{
    if (current_size < 1)
        throw "No objects";
    char rez = stack->Data;
    elem* tmp = stack;
    stack = stack->next;
    current_size--;
    delete tmp;
    return rez;
}


int Stack::getCurrentSize()
{
    return current_size;
}

Stack::~Stack()
{
    while (stack != nullptr)
    {
        elem* tmp = stack->next;
        delete stack;
        stack = tmp;
    }
}
