#pragma once

struct Symbol
{
    char name;
    double value;
};

class SymbolTable
{
public:
    SymbolTable();

    void setValue(char name, double value);
    double getValue(char name);
    void printTable();
    bool isVariable(char);
    bool isValid(char);

private:
    Symbol variables[26];
};