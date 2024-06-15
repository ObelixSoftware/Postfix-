#pragma once

#include "Stack.h"
#include "SymbolTable.h"
#include <iostream>
#include <string>

class Interpreter
{

public:
    Interpreter(const Stack &stack, const SymbolTable &table) : myStack(stack), table(table) {}

    double* compute(const std::string &expression);

private:
    Stack myStack;
    SymbolTable table;
    bool IsOperator(char);
    bool pushOperant(const std::string tok);
};