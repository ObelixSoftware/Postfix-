#include "SymbolTable.h"
#include <iostream>
#include <cctype>

SymbolTable::SymbolTable()
{
    for (int i = 0; i < 26; ++i)
    {
        symbols[i].name = 'A' + i;
        symbols[i].value = 0;
    }
}

void SymbolTable::setValue(char name, double value)
{
    int index = name - 'A';
    if (index >= 0 && index < 26)
    {
        symbols[index].value = value;
    }
    else
    {
        std::cerr << "Invalid variable name: " << name << std::endl;
    }
}

double SymbolTable::getValue(char name)
{
    int index = name - 'A';
    if (index >= 0 && index < 26)
    {
        return symbols[index].value;
    }
    else
    {
        std::cerr << "Invalid variable name:  " << name << std::endl;
        return -1;
    }
}

void SymbolTable::printTable()
{
    for (int i = 0; i < 26; ++i)
    {
        std::cout << symbols[i].name << ": " << symbols[i].value << std::endl;
    }
}

bool SymbolTable::isVariable(char name)
{
    return std::isalpha(name);
}

bool SymbolTable::isValid(char name)
{
    if (name >= 'A' && name <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}