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
    double getValue(char);
    bool isVariable(char);
    void checkDivByZero(double);
    void checkRequireOperants(int);
};