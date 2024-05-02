#ifndef _EXPR_COMMAND_FACTORY_H
#define _EXPR_COMMAND_FACTORY_H

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Mod_Command.h"
#include "Multiply_command.h"
#include "Division_Command.h"
#include "Number_Command.h"

// -*- C++ -*-
// $Id: Expr_Command_Factory.h

//==============================================================================
/**
 * @file       Expr_Command_Factory.h
 *
 * $Id: Expr_Command_Factory.h
 *
 */
//==============================================================================

/**
 * @class Expr_Command_Factory
 *
 *
 */

class Expr_Command_Factory
{
public:
    /**
     * constructor
     */
    Expr_Command_Factory();

    /**
     * destructor
     */
    ~Expr_Command_Factory(void);
    /**
     * This are templates
     * create_div_command
     */
    virtual Division_Command *create_div_command(void) = 0;
    /**
     * This are templates
     * create_mod_command
     */
    virtual Mod_Command *create_mod_command(void) = 0;
    /**
     * This are templates
     * create_num_command
     */
    virtual Number_Command *create_num_command(int num) = 0;
    /**
     * This are templates
     * create_sub_command
     */
    virtual Subtract_Command *create_sub_command(void) = 0;
    /**
     * This are templates
     * create_multi_command
     */
    virtual Multiply_Command *create_multi_command(void) = 0;
    /**
     * This are templates
     * create_add_command
     */
    virtual Add_Command *create_add_command(void) = 0;
};

#endif