#include "Subtract_Command.h"

//
// constructor
//
Subtract_Command::Subtract_Command(Stack<int> &s)
    // passed up to the binary object
    // precedence is set to zero
    : Binary_Command(s, 0)
{
}
//
// evaluate
//
int Subtract_Command::evaluate(int num_1, int num_2) const
{

    return num_2 - num_1;
}
