#pragma once
#include <iostream>
//#include "iterator.hpp"
///ZA3IM SAID THAT I SHOULD READ ABOUT DYNAMCI ARRAYS.
// private:
//         size_type 			_size;
//         size_type 			_capacity;
//         pointer 			data_arr;
//         allocator_type		_alloc;
namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
    class vector
    {
       
        public: // may be it should be public;
                typedef T   value_type;
                typedef Alloc   allocator_type; 
                typedef value_type& reference;
                typedef const value_type& const_reference;
                typedef value_type* pointer;
                typedef const value_type* const_pointer;
                typedef iterator iterator; // it is up to me to define it 
                typedef const iterator;
                // some iterator still messing here;
                typedef size_t size_type;

                // ****************** constructors ************    
                explicit vector (const allocator_type& alloc = allocator_type()) // std::allocator<T>& alloc = std::allocator();
                {
                    data_arr = NULL;
                    arr_size = 0;

                }
                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): my_allocator(alloc)
                {
                    arr_size = n;
                    data_arr = my_allocator.allocate(n);// i may need to define my own allocator and use instead , 
                                                    //but only if i'm gonna need it later;
                    for(int i = 0; i < n; n++)
                    {
                        my_allocator.construct(data_arr,val);
                    }
                }	
                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                {

                }
                vector (const vector& x)
                {
                   *this = x;// seems logic to me cause we already have the '=' overloaded but ....?
                }
                //******************destructor************
                ~vector()
                {
                    // either empty or i will deallocate here;
                }
                //************   copy assignement operator   *****
                vector& operator= (const vector& x)
                {
                    this->arr_size = x.size();
                    this->data_arr = my_allocator.allocate(x.size());
                    for(int i = 0; i < x.size(); i++)
                    {
                        my_allocator(arr + i, *(x + i));
                    }
                    return(*this);
                }
                //*************   iterators    *************
                 iterator begin()
                 {

                 }
                 const_iterator begin() const
                 {

                 }
                 iterator end()
                 {

                 }
                 const_iterator end() const
                 {

                 }
                reverse_iterator rbegin()
                {

                }
                const_reverse_iterator rbegin() const
                {

                }
                reverse_iterator rend()
                {

                }
                const_reverse_iterator rend() const
                {

                }
                const_iterator cbegin() const noexcept
                {

                }
                const_iterator cend() const noexcept
                {

                }
                const_reverse_iterator crbegin() const noexcept
                {

                }
                const_reverse_iterator crend() const noexcept
                {

                }
                //***********CAPACITY**********
                size_type size() const
                {
                    return(arr_size);
                }
                size_type max_size() const
                {

                }
                void resize (size_type n, value_type val = value_type())
                {

                }
                size_type capacity() const
                {

                }
                bool empty() const
                {
                    if(arr_size == 0)
                        return(true)
                    else
                        return(false)
                }
                void reserve (size_type n)
                {

                }
                void shrink_to_fit()
                {

                }
                //*************ELEMENTS ACCESS***************

                private:
                pointer     data_arr;
                size_type   arr_size;
                allocator_type my_allocator;

    };
}