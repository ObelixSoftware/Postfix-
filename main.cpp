#include <iostream>
#include <string>
#include "Stack.h"
#include "SymbolTable.h"
#include "Interpreter.h"

int main()
{
    // Init the stack, symbol table and interpreter
    Stack stack{};
    SymbolTable table{};
    Interpreter interpreter(stack, table);

	// Intro text
    std::cout << "Postfix++ Interpreter v1.0" << std::endl;
    std::cout << "Version 1.0" << std::endl
              << std::endl;
    std::cout << "Enter 'q' or 'quit' to quit the program" << std::endl
              << std::endl;

    while (true)
    {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);
        std::cout << std::endl;
		
		// Quit the program
        if (line == "q" || line == "quit")
        {
            break;
        }
		
		// Clear the screen
        if (line == "clear")
        {
            system("clear");
            continue;
        }
  
        try
        {
            double *answer = interpreter.compute(line);
			// Output answer if valid math expression
            if (answer != nullptr)
            {
                std::cout << *answer << std::endl
                          << std::endl;
            }
        }
        catch (const std::runtime_error &e) // Display any intepreter errors
        {
            std::cerr << e.what() << std::endl << std::endl;
        }
    }

    return 0;
}