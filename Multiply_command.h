#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_command.h"
// -*- C++ -*-
// $Id: Add_Command.h

//==============================================================================
/**
 * @file       Multiply_Command.h
 *
 * $Id: Multiply_Command.h
 *
 */
//==============================================================================

/**
 * @class Multiply_Command
 *
 *
 */
class Multiply_Command : public Binary_Command
{
public:
    /**
     * constructor
     * @param[in] stack
     */
    Multiply_Command(Stack<int> &s);
    /**
     * evaluate
     * @param[in] num_1, num_2
     */
    int evaluate(int num_1, int num_2) const;

private:
};

#endif