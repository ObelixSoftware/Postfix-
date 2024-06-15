#include "Stack.h"
#include <algorithm>
#include <iostream>
#include <cstddef> 
#include <iterator> 

Stack::~Stack()
{
    for (int i = 0; i < size; ++i)
    {
        if (stack[i] != nullptr)
        {
            delete stack[i];
        }
    }
}

void Stack::push(char value)
{
    if (!isFull()) {
        tos++; 
        stack[tos] = new char(value);
    }
    else {
        std::cout << "Stack overflow and can't handle more than " << STACK_MAX_SIZE << " items" << std::endl;
    }
}

char Stack::pop()
{
    if (tos > 0)
    {
        char t = *stack[tos];
        stack[tos] = nullptr;
        tos--;
        return t;
    }
    else
    {
        return 0.0;
    }
}

void Stack::print()
{
    std::cout << std::endl;
    for (int i = tos; i >= 0; --i)
    {
        if (stack[i] != nullptr)
        {
            std::cout << "[" << *stack[i] << "] ";
        }
    }
    std::cout << std::endl;
}

bool Stack::isFull() {
	return tos >= STACK_MAX_SIZE - 1;
}

int Stack::capacity() {
    return std::count_if(stack, stack + size, [](char* ptr) { return ptr != nullptr; });
}