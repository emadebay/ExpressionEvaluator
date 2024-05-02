#include "Multiply_command.h"
//
// constructor
//
Multiply_Command::Multiply_Command(Stack<int> &s)
    : Binary_Command(s, 1)
{
}
//
// evaluate
//
int Multiply_Command::evaluate(int num_1, int num_2) const
{
    return num_1 * num_2;
}
