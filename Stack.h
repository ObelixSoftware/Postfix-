#pragma once
#include "config.h"

class Stack
{
public:
    // Constructor 
    Stack() = default;
    
    // De-constructor    
    ~Stack();
    
    // Push character item to the Stack
    void push(char);
    
    // Pop item from top of the Stack
    char pop();
    
    // Print Stack content
    void print();
    
    // Return capacity of the Stack on how many elements occupied
    int capacity();
    
private:
    // Init a stack of STAX_MAX_SIZE
    
    char *stack[STACK_MAX_SIZE] = {};
    int size = STACK_MAX_SIZE;
    int tos;
    // Is Stack full
    bool isFull();
};