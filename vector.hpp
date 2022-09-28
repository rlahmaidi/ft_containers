#pragma once
#include <iostream>
#include "iterator.hpp"

namespace ft
{
    template < class T, class Alloc = allocator<T> > 
    class vector
    {
        private: // may be it should be public;
            typedef T   value_type;
            typedef Alloc   allocator_type; // to be defined
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef iterator iterator; // it is up to me to define it 
            typedef const iterator;


            public:
                // ******************start of constructors************
                explicit vector (const allocator_type& alloc = allocator_type())
                {

                }
                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                {

                }	
                template <class InputIterator>  vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                {

                }
                vector (const vector& x)
                {

                }
                //******************end of constructors************
    }
}