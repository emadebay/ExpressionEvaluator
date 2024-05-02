// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

#include "Stack.h"

template <typename T>
Stack<T>::Stack(void)
    // size of stack is initialized to zero
    : size_of_stack(0),
      // Array that belongs to this object is initialized to an empty array
      array_(Array<T>(0))
{
}

//
// Stack
//
template <typename T>
Stack<T>::Stack(const Stack &stack)
    // size of stack is initialized to the
    // size of stack of the passed in stack object
    : size_of_stack(stack.size()),
      // Array that belongs to this object is initialized to the array
      // of the passed in stack
      array_(stack.array_)
{
}

//
// ~Stack
//
template <typename T>
Stack<T>::~Stack(void)
{
    // managed by the Array_base class
    // No dynamically allocated data here
    // nothing to destroy
}

//
// push
//
template <typename T>
void Stack<T>::push(T element)
{

    // checks if the size of stack is zero
    // Also if stack is full
    if (size_of_stack == 0 || size_of_stack >= array_.size())
    {
        // if stack's size is zero or queue is full
        // I incremented the stack's size by 10
        size_t amount_to_added = 10;
        size_t new_Array_size = size_of_stack + amount_to_added;
        array_.resize(new_Array_size);
    }

    // input entry of the array is the current size of the stack
    array_[size_of_stack] = element;

    size_of_stack++;
}

//
// pop
//
template <typename T>
void Stack<T>::pop(void)
{
    // check size and throws an exception if empty
    if (size_of_stack == 0)
    {
        // throw empty_exception();
    }

    size_of_stack--;
}

//
// operator =
//
template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    // self check
    if (this == &rhs)
    {

        // COMMENT It would be easier if you just use the assignment operator
        // on the array to copy things from rhs.

        // Comment by Emmanuel Adebayo
        // I used the assignment operator to copy elements from the rhs's array to this

        this->array_ = rhs.array_;

        this->size_of_stack = rhs.size();
    }

    return *this;
}

//
// clear
//
template <typename T>
void Stack<T>::clear(void)
{

    // resize array to zero
    array_.resize(0);

    // update size of stack
    size_of_stack = 0;
}
