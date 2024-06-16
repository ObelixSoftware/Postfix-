#include "Stack.h"
#include <algorithm>
#include <iostream>
#include <cstddef> 
#include <iterator> 

/*
 De-constructor
*/
Stack::~Stack()
{
    // Cleanup memory of all stack items
    for (int i = 0; i < size; ++i)
    {
        if (stack[i] != nullptr)
        {
            delete stack[i];
        }
    }
}

/*
  Indicate if stack is full

  P 2.1c
*/
bool Stack::isFull() {
	return tos >= STACK_MAX_SIZE - 1;
}

/*
  Push item to the Stack

  P 2.1d
*/
void Stack::push(char value)
{
    if (!isFull()) {
        tos++; 
        stack[tos] = new char(value);
    }
    else {
        // More than STACK_MAX_SIZE is returned so output error
        std::cerr << "Stack overflow and can't handle more than " << STACK_MAX_SIZE << " items" << std::endl;
    }
}

/*
  Pop item from Stack
  
  P 2.1e
*/
char Stack::pop()
{
    if (tos > 0)
    {
		// Get item 
        char t = *stack[tos];
		// Cleanup item
        stack[tos] = nullptr;
        tos--;
        return t;
    }
    else // If no more items then return 0.0
    {
        return 0.0;
    }
}

/*
  Print stack content

  P 2.1f 
*/
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

/*
  Return stack capacity e.g. how many elements are occupied

  P 2.1g
*/
int Stack::capacity() {
    return std::count_if(stack, stack + size, [](char* ptr) { return ptr != nullptr; });
}