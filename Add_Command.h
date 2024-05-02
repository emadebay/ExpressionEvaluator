#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

// -*- C++ -*-
// $Id: Add_Command.h

//==============================================================================
/**
 * @file       Add_Command.h
 *
 * $Id: Add_Command.h
 *
 */
//==============================================================================

/**
 * @class Add_Command
 *
 *
 */

#include "Binary_command.h"

class Add_Command : public Binary_Command
{
public:
    /**
     *constructor
     *@param[in]       stack
     */
    Add_Command(Stack<int> &s);
    /**
     * evaluate
     *
     * @param[in]      num_1,            number to be added
     * @param[in]      num_2,            number to be added
     * @return         num_1 + num_2;
     */
    int evaluate(int num_1, int num_2) const;

private:
    // helpers funtion or variables should be added here
};

#endif