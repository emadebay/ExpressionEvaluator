// This file was written by Emmanuel Adebayo
// I have written this file because using the Array.h file violates Liskov subsiiution Principle
// Since i will not be using the resize method in the Fixed Array class, this seems like a better solution

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline size_t Base_Array<T>::size(void) const
{
  return cur_size_;
}

//
// max_size
//
template <typename T>
inline size_t Base_Array<T>::max_size(void) const
{
  return max_size_;
}
