#pragma once

#include "Stack.h"
#include "SymbolTable.h"
#include <iostream>
#include <string>

class Interpreter
{

public:
    Interpreter(Stack stack, SymbolTable table) : myStack(stack), variableTable(table) {}

    double compute(const std::string &expression);

private:
    Stack myStack;
    SymbolTable variableTable;
    bool IsOp(char);
};