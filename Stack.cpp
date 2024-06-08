#include "Stack.h"
#include "config.h"
#include <algorithm>
#include <iostream>

Stack::Stack()
{
    size = STACK_MAX_SIZE;
    stack = new double[size - 1]{};
    std::fill_n(stack, size, -1);
}

Stack::~Stack()
{
    delete[] stack;
}

void Stack::push(double value)
{
    tos++;
    stack[tos] = value;
}

double Stack::pop()
{
    float t = stack[tos];
    tos--;
    return t;
}

void Stack::print()
{
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (stack[i] != -1)
        {
            std::cout << "[" << stack[i] << "] ";
        }
    }
    std::cout << std::endl;
}