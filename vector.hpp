#pragma once
#include <iostream>
#include <limits.h>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include <exception>
//#include "iterator.hpp"
///ZA3IM SAID THAT I SHOULD READ ABOUT DYNAMCI ARRAYS.
namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
    class Vector
    {
       
        public:
                typedef T   value_type;
                typedef Alloc   allocator_type; 
                typedef value_type& reference;
                typedef const value_type& const_reference;
                typedef value_type* pointer;
                typedef const value_type* const_pointer;
                typedef random_access<value_type> iterator; // it is up to me to define it 
                typedef const random_access<value_type> const_iterator;
                typedef ft::reverse_iterator<iterator>      reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>      const_reverse_iterator;
                typedef typename  iterator_traits<iterator>::difference_type      difference_type;
                typedef size_t size_type;

                // ****************** constructors ************    
                // explicit Vector (const allocator_type& alloc = allocator_type()) // std::allocator<T>& alloc = std::allocator();
                // {
                //     arr_data = NULL;
                //     arr_size = 0;

                // }
                explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): my_allocator(alloc)
                {
                    arr_size = n;
                    arr_data = my_allocator.allocate(n);// i may need to define my own allocator and use instead , 
                                                    //but only if i'm gonna need it later;
                    for(int i = 0; i < n; n++)
                    {
                        my_allocator.construct(arr_data, val);
                    }
                }	
                // template <class InputIterator>
                // Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                // {

                // }
                Vector (const Vector& x)
                {
                   *this = x;// seems logic to me cause we already have the '=' overloaded but ....?
                }
                //******************destructor************
                ~Vector()
                {
                    // either empty or i will deallocate here;
                }
                //************   copy assignement operator   *****
                Vector& operator= (const Vector& x)
                {
                    this->arr_size = x.size();
                    this->arr_data = my_allocator.allocate(x.size());
                    for(int i = 0; i < x.size(); i++)
                    {
                        my_allocator(arr_data + i, *(x + i));// changed from arr to arr_dat, not sure?
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
                //***********CAPACITY**********
                size_type size() const
                {
                    return(arr_size);
                }
                size_type max_size() const
                {
                    return(SIZE_MAX);
                }
                void resize (size_type n, value_type val = value_type())
                {
                    if(n < arr_size)
                    {
                        for(int i = n; n < arr_size; i++)
                            my_allocator.destroy(&arr_data[i]);
                        my_allocator.deallocate(&arr_data[n], arr_size - n);
                        arr_size = n;
                    }
                    else if(n > arr_size && n <= arr_capacity)
                    {
                        for(int i = arr_size; i < n; i++)
                        {
                            my_allocator.construct(&arr_data[i], val);
                        }
                        arr_size = n;
                    }
                    else if(n > arr_capacity)
                    {
                        try
                        {
                            pointer tmp_arr;
                            tmp_arr = my_allocator.allocate(n);
                            for(int i = 0; i < arr_size; i++)
                            {
                                my_allocator.construct(&tmp_arr[i], arr_data[i]);
                                my_allocator.destroy(&arr_data[i]);
                            }
                            for(int i = arr_size; i < n; i++)
                            {
                                my_allocator.construct(&tmp_arr[i], val);
                                my_allocator.destroy(&arr_data[i]);
                            }
                            my_allocator.deallocate(arr_data,arr_capacity);
                            arr_data = tmp_arr;
                            arr_capacity = n;
                            arr_size = n;// not sure of this one;
                        }
                        catch(std::bad_alloc& bad)
                        {
                            std::cout << "bad alloc caught" << bad.what() << std::endl;
                        }
                    }
                }
                size_type capacity() const
                {
                    return(arr_capacity);
                }
                bool empty() const
                {
                    if(arr_size == 0)
                        return(true);
                    else
                        return(false);
                }
                void reserve (size_type n)
                {
                    if(n > SIZE_MAX)
                    {
                        throw("error: the new capacity is bigger than MAX_SIZE the Vector can handle");
                    }
                         //std::lenght_error("error: the new capacity is bigger than MAX_SIZE the Vector can handle");
                    try
                    {
                    
                        if(n > arr_capacity)
                        {
                            pointer tmp_arr;
                            tmp_arr = my_allocator.allocate(n);
                            for(int i = 0; i < arr_size; i++)
                            {
                                my_allocator.construct(&tmp_arr[i], arr_data[i]);// when will we construct the element above arr_size????;
                                my_allocator.destroy(&arr_data[i]);
                            }
                            my_allocator.deallocate(arr_data,arr_capacity);
                            arr_data = tmp_arr;
                            arr_capacity = n;
                        }
                    }
                    catch(std::bad_alloc& ba)
                    {
                        std::cout << "bad alloc caught" << ba.what() << std::endl;
                    }
                }
                void shrink_to_fit()
                {
                    if(arr_capacity > arr_size)
                    {
                        my_allocator.deallocate(&arr_data[n], arr_capacity - n);
                    }
                    arr_capacity = arr_size;
                }
                //*************  ELEMENTS ACCESS  ***************
                reference operator[] (size_type n)
                {
                    return(arr_data[n]);
                }
                const_reference operator[] (size_type n) const
                {
                    return(arr_data[n]);
                }
                reference at (size_type n)
                {
                    if(n >= arr_size)
                        std::out_of_range("this index is out of bounds of valid elements");
                    return(arr_data[n]);
                        
                }
                const_reference at (size_type n) const
                {
                    if(n >= arr_size)
                        std::out_of_range("this index is out of bounds of valid elements");
                    return(arr_data[n]);
                }
                reference front()
                {
                    return(arr_data[0]);
                }
                const_reference front() const
                {
                    return(arr_data[0]);
                }
                reference back()
                {
                    return(arr_data[arr_size - 1]);
                }
                const_reference back() const
                {
                    return(arr_data[arr_size - 1]);
                }
                // value_type* data() noexcept  TO BE REMOVED(C++11)
                // {
                //     return(pointer);
                // }
                // const value_type* data() const noexcept
                // {
                //     return(pointer);
                // }
                //**************  MODIFIERS  ************




                private:
                pointer     arr_data;
                size_type   arr_size;
                allocator_type my_allocator;
                size_type       arr_capacity;

    };
}