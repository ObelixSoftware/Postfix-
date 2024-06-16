#include "SymbolTable.h"
#include <iostream>
#include <cctype>

/* 
  Constructor
*/
SymbolTable::SymbolTable()
{
    // Init variables from A-Z with empty 0 value
    for (int i = 0; i < SYMBOL_TABLE_SIZE; ++i)
    {
        variables[i].name = 'A' + i;
        variables[i].value = 0;
    }
}

/*
  Set variable value
*/
void SymbolTable::setValue(char name, double value)
{
    int index = name - 'A';
    if (index >= 0 && index < SYMBOL_TABLE_SIZE)
    {
        variables[index].value = value;
    }
    else
    {
       // Variable doesn't exists
        std::cerr << "Invalid variable name: " << name << std::endl;
    }
}

/*
  Get variable value
*/
double SymbolTable::getValue(char name)
{
    int index = name - 'A';
    if (index >= 0 && index < 26)
    {
        return variables[index].value;
    }
    else
    {
		// Variable doesn't exists
        std::cerr << "Invalid variable name:  " << name << std::endl;
        return -1;
    }
}

/*
  Print variables content
*/
void SymbolTable::printTable()
{
    for (int i = 0; i < 26; ++i)
    {
        std::cout << variables[i].name << ": " << variables[i].value << std::endl;
    }
}

/*
  is a variable since not a numeric digit
*/
bool SymbolTable::isVariable(char name)
{
    return std::isalpha(name);
}

/*
  Is a valid A-Z variable
*/
bool SymbolTable::isValid(char name)
{
    return name >= 'A' && name <= 'Z';
}

/*
  Is valid variable
*/
bool SymbolTable::isValidVariable(char tok)  {
	return isVariable(tok) && isValid(tok);
}
