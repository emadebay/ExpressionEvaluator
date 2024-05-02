#include "Calc_Facade.h"
#include <iostream>
#include <string>

//
// constructor
//
Calculator_Facade::Calculator_Facade(std::string &infix_format)
    // As at, the final result is
    // initialized to zero
    : res_(0)
{
    // stack that holds the compuation
    // This stack will be used by the commands
    // to evaluate the expression
    Stack<int> result;

    // The command factory is initialized
    // The stack for compuation is passed in
    Stack_Command_Factory factory(result);

    // Postfix, Holds an array of command
    Array<Command *> postfix;

    // This function is local to this class
    // it converts the infix expression
    // to the posftix expression
    change_infix_to_postfix(infix_format, factory, postfix);

    // After the conversion
    // Loops through the array to perform each operation

    for (int i = 0; i < postfix.size(); i++)
    {
        // checks to see if postfix[i] is not null
        if (postfix[i] != 0)
        {
            // performs execution
            postfix[i]->execute();

            // clean up
            delete postfix[i];
        }
    }

    // The result variable (res_) is initialized to the final answer
    res_ = result.top();
}
//
// change_infix_to_postfix(std::string &infix_format, Stack_Command_Factory &factory, Array<Command *> &postfix)
//
void Calculator_Facade::change_infix_to_postfix(std::string &infix_format, Stack_Command_Factory &factory, Array<Command *> &postfix)
{
    std::stringstream input(infix_format);
    std::string token;
    Command *cmd = 0;

    size_t index_for_keeping_track_of_postfix_elements = 0;

    Stack<Command *> temp;
    Stack<std::string> verbal_tracker;
    std::string what_has_been_pushed_in = "";

    // COMMENT Where is the rest of the infix to postfix algorithm. This is kind
    // of critical part for the calculator to actually work.

    // Comment by Emmanuel Adebayo
    // i have added the rest of the implementation

    // loops through the string
    // checks for what type of commands
    while (!input.eof())
    {
        input >> token;

        // binary commands
        if (token == "+")
        {
            cmd = factory.create_add_command();
        }
        else if (token == "*")
        {
            cmd = factory.create_multi_command();
        }
        else if (token == "/")
        {
            cmd = factory.create_div_command();
        }
        else if (token == "-")
        {
            cmd = factory.create_sub_command();
        }

        else if (token == "%")
        {
            cmd = factory.create_mod_command();
        }

        // open bracket check
        else if (token == "(")
        {
            // I pushed the open bracket into the what_has_been_pushed_in stack
            // This is because, I will be checking for it later

            what_has_been_pushed_in = "(";
            verbal_tracker.push(what_has_been_pushed_in);

            // get out of current evaluation
            continue;
        }
        // closed bracket evaluation
        else if (token == ")")
        {
            // verbal_tracker's top has an open bracket
            // Then expression is valid
            if (verbal_tracker.top() == "(")
            {
                // I move everthing out out of the stack
                // and append to the postfix array
                size_t cached_temp_size = temp.size();
                for (size_t i = 0; i < cached_temp_size; i++)
                {
                    postfix.resize(postfix.size() + 1);
                    cmd = temp.top();
                    postfix[index_for_keeping_track_of_postfix_elements] = cmd;
                    index_for_keeping_track_of_postfix_elements++;
                    temp.pop();
                }

                verbal_tracker.pop();
            }
            // after that, we get out of current evaluation
            continue;
        }
        // Number command
        else if (check_if_token_is_a_number(token) == true)
        {
            // Immediately added to the psoftix array
            size_t string_converted_ = std::stoi(token);
            cmd = factory.create_num_command(string_converted_);
            postfix.resize(postfix.size() + 1);
            postfix[index_for_keeping_track_of_postfix_elements] = cmd;

            index_for_keeping_track_of_postfix_elements++;

            continue;
        }
        // handles invalid operand and opeartor
        else
        {
            throw std::invalid_argument("Requested operation is not supported");
        }

        size_t cached_temp_size = temp.size();
        // before we push an element into the temp stack
        // we check if it is not on top of a higher precedence command
        for (size_t i = 0; i < cached_temp_size; i++)
        {
            // if it is higher
            // we move the top of the stack out
            // Then append it to the postfix array
            if (cmd->precedence_value() < temp.top()->precedence_value())
            {

                postfix.resize(postfix.size() + 1);
                cmd = temp.top();
                postfix[index_for_keeping_track_of_postfix_elements] = cmd;
                index_for_keeping_track_of_postfix_elements++;
                temp.pop();
            }
        }
        // pushed element into stack
        temp.push(cmd);
    }

    // After iteration
    // we move remaining commands from the temp to the postfix array
    size_t cached_temp_size = temp.size();
    for (size_t i = 0; i < cached_temp_size; i++)
    {
        postfix.resize(postfix.size() + 1);
        cmd = temp.top();
        postfix[index_for_keeping_track_of_postfix_elements] = cmd;
        index_for_keeping_track_of_postfix_elements++;
        temp.pop();
    }
}

Calculator_Facade::~Calculator_Facade(void)
{
}

//
// output
//
int Calculator_Facade::output()
{
    return res_;
}

//
// check_if_token_is_a_number
//
bool Calculator_Facade::check_if_token_is_a_number(std::string &token)
{

    // loops through the string
    for (size_t i = 0; i < token.length(); i++)
    {

        if ((token < "0") && (token > "9"))
        {
            return false;
        }
    }
    return true;
}