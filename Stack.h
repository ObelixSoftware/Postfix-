#pragma once
#include "config.h"

class Stack
{
public:
    Stack();
    ~Stack();
    void push(double);
    double pop();
    void print();
private:
    double* stack[STACK_MAX_SIZE] = {};
    int size, tos;
};