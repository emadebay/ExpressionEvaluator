#include "Binary_command.h"
//
// constructor
//
Binary_Command::Binary_Command(Stack<int> &s, int assigned_num_of_precedence)
    // stack is initialized
    : s_(s),
      // call to parent to assign the order of precedence
      Command(assigned_num_of_precedence)

{
}

//
// execute
//
void Binary_Command::execute(void)
{
    // pop two numbers and assign them to num_1 and num_2
    int num_1 = s_.top();
    s_.pop();

    int num_2 = s_.top();
    s_.pop();

    // the evaluate method is then called which is determined by the
    // each sub class
    // result is stored in ans and it is returned
    int ans = this->evaluate(num_1, num_2);
    s_.push(ans);
}
