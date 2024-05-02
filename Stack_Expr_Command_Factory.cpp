#include "Stack_Expr_Command_Factory.h"

//
// constructor
//
Stack_Command_Factory::Stack_Command_Factory(Stack<int> &s)
    // stack is initialized
    : s_(s)
{
}
//
// destructor
//
Stack_Command_Factory::~Stack_Command_Factory(void)
{
}

//
// create_num_command
//
Number_Command *Stack_Command_Factory::create_num_command(int num)
{
    return new Number_Command(s_, num);
}

//
// create_add_command
//
Add_Command *Stack_Command_Factory::create_add_command(void)
{
    return new Add_Command(s_);
}

//
// create_sub_command
//
Subtract_Command *Stack_Command_Factory::create_sub_command(void)
{
    return new Subtract_Command(s_);
}

//
// create_multi_command
//
Multiply_Command *Stack_Command_Factory::create_multi_command(void)
{
    return new Multiply_Command(s_);
}

//
// create_div_command
//
Division_Command *Stack_Command_Factory::create_div_command(void)
{
    return new Division_Command(s_);
}

//
// create_mod_command
//
Mod_Command *Stack_Command_Factory::create_mod_command(void)
{
    return new Mod_Command(s_);
}
