#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

// -*- C++ -*-
// $Id: Add_Command.h

//==============================================================================
/**
 * @file       Stack_Command_Factory.h
 *
 * $Id: Stack_Command_Factory.h
 *
 */
//==============================================================================

/**
 * @class Stack_Command_Factory extends Expr_command_factory
 *
 *
 */

#include <string>

#include "Expr_Command_Factory.h"
#include "Mod_Command.h"
#include "Add_Command.h"
#include "Multiply_command.h"
#include "Subtract_Command.h"
#include "Division_Command.h"
#include "Number_Command.h"
#include "Stack.h"

class Stack_Command_Factory : public Expr_Command_Factory
{
public:
    /**
     * constructor
     * @param[in] stack
     */
    Stack_Command_Factory(Stack<int> &s);

    /**
     * destructor
     */
    ~Stack_Command_Factory(void);

    /**
     * create_mod_command
     * returns Mod_Command
     */
    Mod_Command *create_mod_command(void);
    /**
     * create_div_command
     * returns Division_Command
     */
    Division_Command *create_div_command(void);

    /**
     * create_sub_command
     * returns Subtract_Command
     */
    Subtract_Command *create_sub_command(void);

    /**
     * create_multi_command
     * returns Multiply_Command
     */
    Multiply_Command *create_multi_command(void);

    /**
     * create_num_command
     * returns Number_Command
     */
    Number_Command *create_num_command(int num);

    /**
     * create_add_command
     * returns Add_Command
     */
    Add_Command *create_add_command(void);

private:
    // reference to the atcual stack
    Stack<int> &s_;
};
#endif