
// This file was written by Emmanuel Adebayo
// I have written this file because using the Array.h file violates Liskov subsiiution Principle
// Since i will not be using the resize method in the Fixed Array class, this seems like a better solution
//==============================================================================
/**
 * @file       Base_Array.h
 *
 *
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef BASE_ARRAY_H_
#define BASE_ARRAY_H_

#include <cstring> // for size_t definition

// COMMENT Replace this with the structure we discussed in class:
//   Base_Array
//   Fixed_Array: Base_Array
//   Array : Base_Array
//
// Otherwise, your implementation will not work as expected since
// the Array class has an expected interface, which you have changed.

// Comment by Emmanuel Adebayo -- reply to dr. hill
// The initial name of this file was Array_base
// I have renamed this file because the initial name does not meet the requirements
//

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Base_Array
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Base_Array(void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Base_Array(size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Base_Array(size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Base_Array(const Base_Array &arr);

  /// Destructor.
  ~Base_Array(void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Base_Array &operator=(const Base_Array &rhs);

  /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
  virtual size_t size(void) const;

  /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
   */
  virtual size_t max_size(void) const;

  /**
   * Get the character at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
   */
  T &operator[](size_t index);

  /**
   * @overload
   *
   * The returned character is not modifiable.
   */
  const T &operator[](size_t index) const;

  /**
   * Get the character at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   * @exception       std::out_of_range     Invalid index value
   */
  T get(size_t index) const;

  /**
   * Set the character at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   * @exception       std::out_of_range     Invalid \a index value
   */
  void set(size_t index, T value);

  /**
   * Locate the specified character in the array. The index of the first
   * occurrence of the character is returned. If the character is not
   * found in the array, then -1 is returned.
   *
   * @param[in]        ch        Character to search for
   * @return           Index value of the character
   * @retval           -1        Character not found
   */
  int find(T element) const;

  /**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       ch                   Character to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Character not found
   * @exception       std::out_of_range    Invalid index
   */
  int find(T element, size_t start) const;

  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator==(const Base_Array &rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator!=(const Base_Array &rhs) const;

  /**
   * Fill the contents of the array.
   *
   * @param[in]       ch                   Fill character
   */
  void fill(T element);

  /// Reverse the contents of the array such that the first element is now
  /// the last element and the last element is the first element.
  void reverse(void);

private:
  // Helper functions
  // Not given by the professor but allowed
  void delete_and_set_to_nullptr_the_dynamically_allocated_data_(void);
  void check_if_index_is_within_range(size_t index) const;

  /// Pointer to the actual data.
  T *data_;

  /// Current size of the array.
  size_t cur_size_;

  /// Maximum size of the array.
  size_t max_size_;
};

#include "Base_Array.inl"
#include "Base_Array.cpp"

#endif // !defined BASE_ARRAY_H_
