#include "Command.h"

//
// constrcutor
//
Command::Command(void)
    // initilaize order of precedence
    : assigned_num_of_precedence_(0)
{
}
//
// constrcutor
//
Command::Command(int assigned_num_of_precedence)
    // initilaize order of precedence
    : assigned_num_of_precedence_(assigned_num_of_precedence)
{
}
//
// destructor
//
Command::~Command(void)
{
}

//
// precedence_value
//

int Command::precedence_value() const
{
    return assigned_num_of_precedence_;
}
