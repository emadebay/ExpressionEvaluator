#ifndef _DIVISION_COMMAND_H_
#define _DIVISION_COMMAND_H_

// -*- C++ -*-
// $Id: Division_Command.h

//==============================================================================
/**
 * @file       Division_Command.h
 *
 * $Id: Division_Command.h
 *
 */
//==============================================================================

/**
 * @class Division_Command
 *
 *
 */

#include "Binary_command.h"
#include "Stack.h"

class Division_Command : public Binary_Command
{
public:
    /**
     * constructor
     * @param[in] stack
     */
    Division_Command(Stack<int> &s);
    /**
     * evaluate
     * @param[in] num_1, num_2
     * return num_1 / num_2
     */
    int evaluate(int num_1, int num_2) const;

private:
};

#endif