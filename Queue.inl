// -*- C++ -*-
// $Id: Queue.h 380 09/22/20202
// This file is written from sratch by Emmanuel Adebayo
// used the same naming conventions used in the other files provided by the professor

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// is_empty
//
template <typename T>
inline bool Queue<T>::is_empty(void) const
{
    return size_of_queue == 0;
}
//
// size
//
template <typename T>
inline size_t Queue<T>::size(void) const
{
    return size_of_queue;
}