#include <iostream>
#include "Stack.h"

int main() {

    std::cout << "Postfix++ Interpreter v1.0" << std::endl;
    std::cout << "Version 1.0" << std::endl << std::endl;
    std::cout << "Enter 'h' or 'help' for instructions or 'q' or 'quit' to quit the program" << std::endl << std::endl; 
    
    Stack stack{};
    
    stack.push(10);
    stack.push(5);
    stack.print();

    /*
    while (true)
    {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);
        std::cout << std::endl;
        if (line == "q" || line == "quit") {
            break;
        }
    }*/

    return 0;
}