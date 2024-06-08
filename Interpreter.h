#pragma once

#include "Stack.h"
#include <iostream>
#include <string>

class Interpreter
{

public:
    Interpreter(Stack stack) : myStack(stack) {}

    double compute(const std::string &expression);

private:
    Stack myStack;
    bool IsOp(char);
};