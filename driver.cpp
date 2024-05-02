#include <iostream>
#include <string>
#include "Base_Array.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Calc_Facade.h"

int main(int argc, char *argv[])
{

    std::string input;

    while (true)
    {
        try
        {
            std::cout << "please enter input in the infix format: \n";

            std::getline(std::cin, input);

            if (input == "QUIT")
            {
                std::cout << "Program exited: \n";
                break;
            }

            Calculator_Facade calculator(input);
            std::cout << calculator.output() << "\n";
        }
        catch (std::invalid_argument)
        {
            std::cout << "you have entered an unsupported opearation\n";
        }
    }

    return 0;
}
