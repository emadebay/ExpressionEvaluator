#ifndef _UNARY_COMMAND_H
#define _UNARY_COMMAND_H

// -*- C++ -*-
// $Id: Unary_Command.h

//==============================================================================
/**
 * @file       Unary_Command.h
 *
 * $Id: Unary_Command.h
 *
 */
//==============================================================================

/**
 * @class Unary_Command
 * This is a template class for commands with unary operations
 *
 *
 */

#include "Command.h"

class Unary_Command : public Command
{

public:
       /**
     * destructor
     */
    ~Unary_Command(void); // destructor

    /**
     * execute
     */
    virtual void execute(void) = 0;
};

#endif