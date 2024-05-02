// This file was written by Emmanuel Adebayo
// I have written this file because using the Array.h file violates Liskov subsiiution Principle
// Since i will not be using the resize method in the Fixed Array class, this seems like a better solution

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept> // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Base_Array<T>::Base_Array(void)
    // current size is zero
    : cur_size_(0),
      // maximum size is zero
      max_size_(0),
      // dyanmically allocated data of size zero
      data_(new T[0])
{
}

//
// Array (size_t)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length)
    // current size is initialized to the length passed in length
    : cur_size_(length),
      // maximum size is initialized to the length passed in length
      max_size_(length),
      // dynamically allocated data of size of passed in length
      data_(new T[length])
{
}

//
// Array (size_t, char)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill)
    // current size is initialized to the length passed in length
    : cur_size_(length),
      // maximum size is initialized to the length passed in length
      max_size_(length),
      // dynamically allocated data of size of passed in length
      data_(new T[length])
{
    // reused the fill method that belongs to this class
    // this fill method loops through the array and fills it with T element
    this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Base_Array<T>::Base_Array(const Base_Array &array)
    // current size is initialized to the length passed in array's current size
    : cur_size_(array.cur_size_),
      // maximum size is initialized to the length passed in array's maximum size
      max_size_(array.max_size_),
      // dynamically allocated data of size of passed in array's max size
      data_(new T[array.max_size_])
{
    // copy from passed in Array
    for (size_t i = 0; i < max_size_; i++)
    {
        data_[i] = array[i];
    }
}

//
// ~Array
//
template <typename T>
Base_Array<T>::~Base_Array(void)
{
    // deletes dynamically allocated array_ and set it to null
    delete_and_set_to_nullptr_the_dynamically_allocated_data_();
}

//
// operator =
//
template <typename T>
const Base_Array<T> &Base_Array<T>::operator=(const Base_Array &rhs)
{

    // self check
    if (this != &rhs)
    {
        // delete the data and set it to null
        delete_and_set_to_nullptr_the_dynamically_allocated_data_();

        // updates current size and maximumsize
        this->cur_size_ = rhs.size();
        this->max_size_ = rhs.max_size();

        data_ = new T[cur_size_];

        for (size_t i = 0; i < max_size_; i++)
        {

            data_[i] = rhs.data_[i];
        }
    }

    return *this;
}

//
// operator []
//
template <typename T>
T &Base_Array<T>::operator[](size_t index)
{
    // checks to see if index is within range
    // if not, throws an exception
    // refer to the method: check_if_index_is_within_range() for more
    check_if_index_is_within_range(index);

    return data_[index];
}

//
// operator []
//
template <typename T>
const T &Base_Array<T>::operator[](size_t index) const
{
    // checks to see if index is within range
    // if not, throws an exception
    // refer to the method: check_if_index_is_within_range() for more
    check_if_index_is_within_range(index);

    return data_[index];
}

//
// get
//
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    // checks to see if index is within range
    // if not, throws an exception
    // refer to the method: check_if_index_is_within_range() for more
    check_if_index_is_within_range(index);

    return data_[index];
}

//
// set
//
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    // checks to see if index is within range
    // if not, throws an exception
    // refer to the method: check_if_index_is_within_range() for more
    check_if_index_is_within_range(index);

    data_[index] = value;
}

//
// find (char)
//
template <typename T>
int Base_Array<T>::find(T value) const
{
    // try-catch prevents this from reaching the user or client
    try
    {

        return this->find(value, 0);
    }
    catch (const std::out_of_range)
    {
        // will not reach the client
    }

    // if try - catch fails
    return -1;
}

//
// find (char, size_t)
//
template <typename T>
int Base_Array<T>::find(T val, size_t start) const
{
    // checks to see if index is within range
    // if not, throws an exception
    // refer to the method: check_if_index_is_within_range() for more
    check_if_index_is_within_range(start);

    for (size_t i = start; i < cur_size_; i++)
    {
        if (data_[i] == val)
        {

            return i;
            break;
        }
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array<T>::operator==(const Base_Array &rhs) const
{
    // self check
    // if address is the same, return true

    if (this == &rhs)
    {
        return true;
    }

    // check current size of this object and right hand side
    if (cur_size_ != rhs.cur_size_)
    {
        return false;
    }

    // checks to see if same size
    if (cur_size_ == rhs.cur_size_)
    {

        for (size_t i = 0; i < cur_size_; i++)
        {
            // compare element one by one
            // if data is diffeent from right hand side
            // return false and break
            if (data_[i] != rhs.data_[i])
            {
                return false;
                break;
            }
        }
    }

    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array<T>::operator!=(const Base_Array &rhs) const
{
    // Reused the operator ==
    // checks to if *this is similar to the rhs
    // Then negates the result of whatever was returned
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Base_Array<T>::fill(T value)
{
    // fill the data with the passed in value
    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = value;
    }
}

template <typename T>
void Base_Array<T>::reverse(void)
{
    // beginning of the array
    size_t start_pointer = 0;

    // end of the array
    size_t end_pointer = cur_size_ - 1;

    // we swap the first element with the last element
    // we advance both start_pointer and decrement end_pointer
    while (start_pointer < end_pointer)
    {
        T temp = data_[start_pointer];
        data_[start_pointer] = data_[end_pointer];
        data_[end_pointer] = temp;

        start_pointer++;
        end_pointer--;
    }
}

template <typename T>
void Base_Array<T>::delete_and_set_to_nullptr_the_dynamically_allocated_data_(void)
{
    // free space of allocated memory
    // avoiding memory leak
    delete[] data_;

    data_ = nullptr;
}

template <typename T>
void Base_Array<T>::check_if_index_is_within_range(size_t index) const
{
    // throw out of range is input parameter is out of bounds
    if (index < 0 || index >= cur_size_)
    {
        throw std::out_of_range("Index is not within current range of Base Array");
    }
}