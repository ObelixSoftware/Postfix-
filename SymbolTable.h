#pragma once

struct Symbol
{
    char name;
    int value;
};

class SymbolTable
{
public:
    SymbolTable();

    void setValue(char name, int value);
    int getValue(char name);
    void printTable();

private:
    Symbol symbols[26];
};