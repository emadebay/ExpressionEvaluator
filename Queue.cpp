// -*- C++ -*-
// $Id: Queue.h 380 09/22/20202
// This file is written from sratch by Emmanuel Adebayo
// used the same naming conventions used in the other files provided by the professor

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Queue
//
template <typename T>
Queue<T>::Queue(void)
    // queue's size is zero
    : size_of_queue(0),
      // Array object that belongs to this class is initialized
      // to and empty array
      array_(Array<T>()),
      // Index of first in line is initialized to zero
      // it is used to access to the front o the queue
      index_of_first_in_line(0)
{
}

//
// ~Queue
//
template <typename T>
Queue<T>::~Queue(void)
{

    // no data is dynamically allocated in this class
    // The dynamically allocated is in the base class of Array class
}

//
// Queue(const Queue)
//
template <typename T>
Queue<T>::Queue(const Queue &queue)
    // size of this queue is initialized to the
    // size of the passed in queue
    : size_of_queue(queue.size_of_queue),
      // Array belonging to this class is initialized
      // to array of the passed in queue
      array_(queue.array_),
      // Index of first line is initialized to zero
      // it is used to access to the front o the queue
      index_of_first_in_line(0)

{
}

//
// operator =
//
template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue &rhs)
{

    // self check
    if (this != &rhs)
    {

        // COMMENT Could you not use the assignment operator on the array class
        // to copy over the elements.

        // Comment by Emmanuel Adebayo --- reply to Dr. Hill
        // I used the assignment operator to copy elements from the rhs's array to this

        // initialized the array that  belongs to this class
        // to the that belongs to the right hand side's queue
        this->array_ = rhs.array_;
        this->size_of_queue = rhs.size_of_queue;
    }

    return *this;
}

//
// enqueue
//
template <typename T>
void Queue<T>::enqueue(T element)
{
    // checks if the size of queue is zero
    // Also if queue is full
    if (size_of_queue == 0 || size_of_queue >= array_.size())
    {
        // if queue's size is zero or queue is full
        // I incremented the queue's size by 10
        size_t new_Array_size = size_of_queue + 10;
        array_.resize(new_Array_size);
    }

    // input entry is at the size of queue
    array_[size_of_queue] = element;

    size_of_queue++;
}
//
// dequeue
//
template <typename T>
T Queue<T>::dequeue(void)
{
    // COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.

    // Comment--- Emmanuel Adebayo --  reply to Dr. Hill
    // I added a better design that i believe is less expensive
    // I incremented the value of index_of_first_in_line until it exceeds range

    // check to see if queue is empty
    if (this->is_empty() == true)
    {
        // An empty exception is thrown inidicating
        // that queue is empty
        // throw empty_exception();
    }

    // store first elemet in the array
    T element_to_be_returned = array_[index_of_first_in_line];

    index_of_first_in_line++;
    size_of_queue--;

    return element_to_be_returned;
}
//
// clear
//
template <typename T>
void Queue<T>::clear(void)
{
    // Array is resized to zero
    // This ensures that the size of the array is zero

    array_.resize(0);

    size_of_queue = 0;
}
