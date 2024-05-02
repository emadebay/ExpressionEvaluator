#include "Mod_Command.h"
//
// constructor
//
Mod_Command::Mod_Command(Stack<int> &s)
    // call to parent class
    // to initialize stack
    // and set order of precedence
    : Binary_Command(s, 2)
{
}
//
// evaluate
//
int Mod_Command::evaluate(int num_1, int num_2) const
{
    return num_2 % num_1;
}
