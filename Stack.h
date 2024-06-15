#pragma once
#include "config.h"

class Stack
{
public:
    Stack() = default;
    ~Stack();
    void push(char);
    char pop();
    void print();

private:
    char *stack[STACK_MAX_SIZE] = {};
    int size = STACK_MAX_SIZE;
    int tos;
    bool isFull();
};