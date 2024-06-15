#include <iostream>
#include <string>
#include "Stack.h"
#include "SymbolTable.h"
#include "Interpreter.h"

int main() {
    Stack stack{};
    SymbolTable table{};

    table.setValue('A', 1);

    Interpreter interpreter(stack, table);

    std::cout << "Postfix++ Interpreter v1.0" << std::endl;
    std::cout << "Version 1.0" << std::endl << std::endl;
    std::cout << "Enter 'h' or 'help' for instructions or 'q' or 'quit' to quit the program" << std::endl << std::endl; 

    while (true)
    {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);
        std::cout << std::endl;
        if (line == "q" || line == "quit") {
            break;
        }
        if (line == "clear") {
            system("clear");
            continue;
        }
        double* answer = interpreter.compute(line);
        if (answer != nullptr) {
            std::cout << *answer << std::endl << std::endl;
        }
    }

    return 0;
}