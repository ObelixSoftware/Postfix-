#include <iostream>
#include <string>
#include "Stack.h"
#include "Interpreter.h"

int main() {
    Stack stack{};
    Interpreter interpreter(stack);

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
        std::cout << interpreter.compute(line) << std::endl << std::endl;
    }

    return 0;
}