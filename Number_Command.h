#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

// -*- C++ -*-
// $Id: Number_Command.h

//==============================================================================
/**
 * @file       Number_Command.h
 *
 * $Id: Number_Command.h
 *
 */
//==============================================================================

/**
 * @class Number_Command
 *
 *
 */

#include "Command.h"
#include "Stack.h"

class Number_Command : public Command
{
public:
    /**
     * @param[in] stack, num
     */
    Number_Command(Stack<int> &s, int num);

    /**
     * execute
     */
    virtual void execute(void);

private:
    Stack<int> &s_;
    int num_to_be_pushed_onto_stack_;
};
#endif