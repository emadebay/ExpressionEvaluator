#include "Division_Command.h"
//
// constructor
//
Division_Command::Division_Command(Stack<int> &s)
    // Parent class is classed
    // stack is initiailzed
    // order of precedence is set
    : Binary_Command(s, 1)
{
}
//
// evaluate
//
int Division_Command::evaluate(int num_1, int num_2) const
{
    return num_2 / num_1;
}
