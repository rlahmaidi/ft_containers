#include "vector.hpp"

namespace ft
{               template <class InputIterator>
                void Vector<>::assign (InputIterator first, InputIterator last)
                {
                    difference_type diff;
                    //diff = std::distance(first,last);
                    diff = last - first;
                    if(diff < 0)// i need to make sure of this if????
                        diff *= (-1); 
                    
                     arr_size = diff;
                     if(arr_capacity < arr_size)
                     {
                        my_allocator.deallocate(arr_data, arr_capacity);
                        arr_capacity = arr_size;
                        arr_data = my_allocator.allocate(arr_capacity);
                     }
                     for(size_type i = 0; i < arr_size && first != last; i++)
                     {
                        my_allocator.construct(arr_data + i, *first);
                        first++;
                     }
                }
}