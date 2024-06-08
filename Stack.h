#pragma once
#include "config.h"

class Stack
{
public:
    Stack() = default;
    ~Stack();
    void push(double);
    double pop();
    void print();

private:
    double *stack[STACK_MAX_SIZE] = {};
    int size = STACK_MAX_SIZE;
    int tos;
};