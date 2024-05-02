#ifndef _BINARY_COMMAND_H
#define _BINARY_COMMAND_H

// -*- C++ -*-
// $Id: Add_Command.h

//==============================================================================
/**
 * @file       Binary_Command.h
 *
 * $Id: Binary_Command.h
 *
 */
//==============================================================================

/**
 * @class Binary_Command
 * This class is a template for class that or objects
 * That performs binary operation
 * such as division, addition, subtraction, multiplication. etc
 *
 *
 */

#include "Command.h"
#include "Stack.h"

class Binary_Command : public Command
{

public:
    /**
     *constructor
     *@param[in]       stack
     @param[in]       assigned value for the precedence
     */
    Binary_Command(Stack<int> &s, int assigned_num_of_precedence);

    /**
     * execute
     *
     */
    void execute(void);

    /**
     * evaluate
     *@param[in] num_1
     @param[in] num_2
     *return    to be determined by subclasses
     */
    virtual int evaluate(int num_1, int num_2) const = 0;

private:
    // reference to the passed in stack
    Stack<int> &s_;
};

#endif