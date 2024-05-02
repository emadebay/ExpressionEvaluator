// -*- C++ -*-
// $Id: Queue.h 380 09/22/20202
// This file is written from sratch by Emmanuel Adebayo
// used the same naming conventions used in the other files provided by the professor

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"

template <typename T>
class Queue
{
public:
    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the queue is empty.
     */
    // class empty_exception : public std::exception
    // {
    // public:
    //     /// Default constructor.
    //     empty_exception(void)
    //         : std::exception() {}

    //     /**
    //      * Initializing constructor.
    //      *
    //      * @param[in]      msg         Error message.
    //      */
    //     empty_exception(const char *msg)
    //         : std::exception(msg) {}
    // };

    /// Default constructor.
    Queue(void);
    /// destructor
    ~Queue(void);

    /// copy constructor
    Queue(const Queue &queue);

    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue &operator=(const Queue &rhs);

    /**
     * Push a new \a element onto the queue. The element is inserted
     * after all the other elements in the list.
     *
     * @param[in]      element       Element to add to the list
     */
    void enqueue(T element);

    /**
     * Remove the fore-most element from the queue.
     *
     * @exception      empty_exception    The queue is empty.
     */
    T dequeue(void);

    /**
     * Test if the stack is empty
     *
     * @retval         true          The stack is empty
     * @retval         false         The stack is not empty
     */
    bool is_empty(void) const;

    /**
     * Number of element on the stack.
     *
     * @return         Size of the Queue.
     */
    size_t size(void) const;

    /// Remove all elements from the Queue.
    void clear(void);

private:
    // add member variable here
    Array<T> array_;
    size_t size_of_queue;
    size_t index_of_first_in_line;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"
#endif // !defined _CS507_QUEUE_H_