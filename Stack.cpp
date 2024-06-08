#include "Stack.h"
#include <algorithm>
#include <iostream>

Stack::Stack()
{
    size = STACK_MAX_SIZE;
}

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

void Stack::push(double value)
{
    tos++;
    stack[tos] = new double(value);
}

double Stack::pop()
{
    if (tos > 0)
    {
        double t = *stack[tos];
        stack[tos] = nullptr;
        tos--;
        return t;
    }
    else
    {
        // Handle stack underflow error
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