#include "Number_Command.h"

//
// constructor
//
Number_Command::Number_Command(Stack<int> &s, int num)
    // stack is initialized
    : s_(s),
      // number to pushed onto stack is initialized
      num_to_be_pushed_onto_stack_(num)
{
}

//
// execute
//
void Number_Command::execute(void)
{
    // pushes onto stack
    s_.push(num_to_be_pushed_onto_stack_);
}
