#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_command.h"

class Subtract_Command : public Binary_Command
{
public:
    Subtract_Command(Stack<int> &s);
    int evaluate(int num_1, int num_2) const;

private:
};

#endif