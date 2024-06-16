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

  P 2.2d
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

  P 2.2e
*/
double SymbolTable::getValue(char name)
{
    int index = name - 'A';
    if (index >= 0 && index < SYMBOL_TABLE_SIZE)
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
  is a variable since not a numeric digit

  P 2.2f
*/
bool SymbolTable::isVariable(char name)
{
    return std::isalpha(name);
}

/*
  Is a valid A-Z variable
  
  P 2.2g
*/
bool SymbolTable::isValid(char name)
{
    return name >= 'A' && name <= 'Z';
}

/*
  Is valid variable

  P 2.2h
*/
bool SymbolTable::isValidVariable(char tok)  {
	return isVariable(tok) && isValid(tok);
}

/*
  Print variables content

  P 2.2i
*/
void SymbolTable::printTable()
{
    for (int i = 0; i < 26; ++i)
    {
        std::cout << variables[i].name << ": " << variables[i].value << std::endl;
    }
}
