#pragma once

class Stack
{
public:
    Stack();
    ~Stack();
    void push(double);
    double pop();
    void print();
private:
    double *stack;
    int size, tos;
};