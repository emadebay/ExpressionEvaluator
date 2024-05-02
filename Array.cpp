// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept> // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array<T>::Array(void)
    // current size is initialized to zero
    : cur_size_(0),
      // maximum size is initialized to zero
      max_size_(0),
      // Call to parent class
      // The base is initialzed to zero
      Base_Array<T>(0)
{
}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array(size_t length)
    // current size is initialized to passed in length
    : cur_size_(length),
      // maximum size is initialized to passed in length
      max_size_(length),
      // Call to parent class
      // The base is initialzed to passed in length
      Base_Array<T>(length)
{
}

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array(size_t length, T fill)
    // current size is initialized to passed in length
    : cur_size_(length),
      // maximum size is initialized to passed in length
      max_size_(length),
      // Call to parent class
      // The base is initialzed to passed in length
      // This Base_Array constructor initializes the Array to size of length
      // It also initialized it the T element
      Base_Array<T>(length, fill)
{
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array<T> &array)
    // current size is initialized to passed in array's current size
    : cur_size_(array.cur_size_),
      // maximum size is initialized to passed in array's current size
      max_size_(array.max_size_),
      // Call to parent class' copy constructor
      // The base is initialzed to passed in array
      Base_Array<T>(array)
{
}

//
// ~Array
//
template <typename T>
Array<T>::~Array(void)
{
    // no data is dynamically allocated in this class
    // The dynamically allocated is in the parent class
    // this destructor will be managed by the lower class
}

//
// operator =
//
template <typename T>
const Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    // self check
    if (this != &rhs)
    {

        // used  assignment(=) of the base operator in the derived class
        Base_Array<T>::operator=(rhs);

        // updates Current size of the array.
        cur_size_ = rhs.size();

        // Updates Maximum size of the array.
        max_size_ = rhs.max_size();
    }

    return *this;
}

//
// resize
//
template <typename T>
void Array<T>::resize(size_t new_size)
{
    size_t current_size = cur_size_;
    // if new size is less than or euqal max_size
    if (new_size <= this->max_size_)
    {

        // we update cur_size_ and max_size_
        this->cur_size_ = new_size;
        this->max_size_ = new_size;
    }

    // if new_size is greater than cur_size_
    if (new_size > max_size_)
    {
        // holds the hold data to copied
        Array temp_data = Array<T>(new_size);

        for (size_t i = 0; i < cur_size_; i++)
        {
            // stores what is in lower class' Array and initialize to nothing
            temp_data[i] = Base_Array<T>::get(i);
        }

        // The value of temp_data is now assigned to this instance
        Base_Array<T>::operator=(temp_data);
        cur_size_ = new_size;
        max_size_ = new_size;
    }
    // leaving cur size the same because client might decide to do nothing with it
    // cur_size_ = current_size;
}

template <typename T>
Array<T> Array<T>::slice(size_t begin) const
{
    // checks to see if begin is within an acceptable range
    check_if_index_for_slice_method_is_within_range(begin);

    /* Immediate opeartion below calculates the new size*/
    size_t new_length = cur_size_ - begin;

    Array<T> new_array_object = Array<T>(new_length);
    size_t new_index_of_array = 0;

    for (size_t i = begin; i < cur_size_; i++)
    {
        new_array_object[new_index_of_array] = this->get(i);
        new_index_of_array++;
    }
    return new_array_object;
}

template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end) const
{
    // checks to see if begin and end are within acceptable range
    check_if_index_for_slice_method_is_within_range(begin);
    check_if_index_for_slice_method_is_within_range(end);

    /* Immediate opeartion below calculates the new size*/
    size_t new_length = end - begin;

    Array<T> new_array_object = Array<T>(new_length);

    size_t new_index_of_array = 0;

    for (size_t i = begin; i < end; i++)
    {
        new_array_object[new_index_of_array] = this->get(i);
        new_index_of_array++;
    }
    return new_array_object;
}

template <typename T>
void Array<T>::shrink()
{

    // if cur_size is less than maximum size
    if (cur_size_ < max_size_)
    {
        // new size to be used
        size_t new_length = cur_size_;

        // temporary Array
        Array<T> temp_data_ = Array<T>(new_length);

        for (size_t i = 0; i < new_length; i++)
        {
            temp_data_[i] = Base_Array<T>::get(i);
        }

        // The value of temp_data is now assigned to this instance

        Base_Array<T>::operator=(temp_data_);

        // updates current size and maximum size
        cur_size_ = new_length;
        max_size_ = new_length;
    }
}

//
// checks to see if index passed in for the sliced method is within range
//

template <typename T>
void Array<T>::check_if_index_for_slice_method_is_within_range(size_t index) const
{

    // throw out of range is input parameter is out of bounds
    if (index < 0 || index >= cur_size_)
    {
        throw std::out_of_range("Index is not within current range of array size");
    }
}
