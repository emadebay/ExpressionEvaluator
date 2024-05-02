#include <iostream>
#include "Add_Command.h"

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

//
// Constructor
//
Add_Command::Add_Command(Stack<int> &s)
    // The parent class (Binary_command is called)
    // It's order of accesibilty is set to zero
    // based on PEMDAS
    : Binary_Command(s, 0)
{
}

//
// evalaute
//
int Add_Command::evaluate(int num_1, int num_2) const
{

    return num_1 + num_2;
}
