#pragma once

#include "config.h"

// Structure of each variable element
// P 2.2b
struct Symbol {
    char name;
    double value;
};

class SymbolTable
{
public:
    // Constructor 
    SymbolTable(); 

	// Set variable value
    void setValue(char name, double value);
    
    // Get value of a variable 
    double getValue(char name);
    
    // Print content
    void printTable();
    
    // Is a variable and not a digit
    bool isVariable(char);
    
    // Is a valid variable in the range A-Z
    bool isValid(char);
    
    // Is valid variable
	bool isValidVariable(char);

private:
    // Array of variables A-Z
    // P 2.2c
    Symbol variables[SYMBOL_TABLE_SIZE];
};