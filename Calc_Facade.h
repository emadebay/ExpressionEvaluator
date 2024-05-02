#ifndef _CALC_FACDE_H
#define _CALC_FACDE_H

// -*- C++ -*-
// $Id: Calculator_Facade.h

//==============================================================================
/**
 * @file       Calculator_Facade.h
 *
 * $Id: Calculator_Facade.h
 *
 */
//==============================================================================

/**
 * @class Calculator_Facade
 *
 *Because the whole application will be using many interconnected subsytems
 *This class is serving as a wrapper (facade)
 *This way, input comes and output goes goes out
 *Making it easier for the client to use
 */

#include <iostream>
#include <sstream>
#include <string>

#include "Array.h"
#include "Stack.h"
#include "Queue.h"

#include "Command.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"

class Calculator_Facade

{
public:
    /**
     * constructor
     * @param[in] infix_format
     */
    Calculator_Facade(std::string &infix_format);
    /**
     * destructor
     */
    ~Calculator_Facade(void);

    /**
     * output
     * This returns the answer
     */
    int output();

private:
    // this wil store the result of the final answer
    int res_;
    // helpers functions

    /**
     * convert_infix_to_postfix
     */
    void change_infix_to_postfix(std::string &infix_format, Stack_Command_Factory &factory, Array<Command *> &postfix);

    /**
     check_if_token_is_a_number;
     *@param[in] std::string &token
     *return bool
    */
    bool check_if_token_is_a_number(std::string &token);
};

#endif