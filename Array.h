// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring> // for size_t definition
#include "Base_Array.h"

// COMMENT Replace this with the structure we discussed in class:
//   Base_Array
//   Fixed_Array: Base_Array
//   Array : Base_Array
//
// Otherwise, your implementation will not work as expected since
// the Array class has an expected interface, which you have changed.

// Comment by Emmanuel Adebayo -- reply to dr. hill
// This class inherits from a class named Array_base which was supposed to be Base_Array
// I have updated the Base class' name.
// I have also made sure that it inherits from the proper class

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Base_Array<T>
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Array(void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array(size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array(size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array(const Array<T> &arr);

  /// Destructor.
  ~Array(void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Array &operator=(const Array<T> &rhs);

  /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
  size_t size(void) const;

  /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
   */
  size_t max_size(void) const;

  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize(size_t new_size);

  /**
   * The slice() method returns a shallow copy of a portion of an array into
   * a new array object selected from begin to end (end not included). The original
   * array will not be modified.
   *
   * @param[in]       begin           The starting index
   * @return          A new Array object
   */
  Array slice(size_t begin) const;

  /**
   * @overload
   *
   * @param[in]       begin           The starting index
   * @param[in]       end             The ending index
   * @return          A new Array object
   */
  Array slice(size_t begin, size_t end) const;

  // shrinks array to reclaim unused space

  void shrink();

private:
  // array iterator
  // friend class Array_iterator;
  // private helper
  void check_if_index_for_slice_method_is_within_range(size_t index) const;

  /// Current size of the array.
  size_t cur_size_;

  /// Maximum size of the array.
  size_t max_size_;
};

#include "Array.cpp"
#include "Array.inl"
#endif // !defined _ARRAY_H_
