#pragma once

#include "Stack.h"
#include "SymbolTable.h"
#include <iostream>
#include <string>

class Interpreter
{
public:
    // Constructor
    Interpreter(const Stack &stack, const SymbolTable &table) : myStack(stack), table(table) {}

	// Compute the RPN expression
    double* compute(const std::string &expression);

private:
    // Reference to the Stack
    Stack myStack;
    // Reference to the Symbol Table
    SymbolTable table;
    // Indicate if char is a operator
    bool IsOperator(char);
    // Get the value from the token being number of value of a veriable from symbol table
    double getValue(char);
    // is a variable
    bool isValidVariable(char);
    // Error handling, check for divison by zero and operants requried
    void checkDivByZero(double);
    void checkRequireOperants(int);
};