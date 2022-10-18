#pragma once
#include <iostream>
#include <limits.h>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
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
                typedef typename  std::ptrdiff_t      difference_type;
                typedef size_t size_type;

                //****************** constructors ************    
                explicit Vector (const allocator_type& alloc = allocator_type()): my_allocator(alloc)// std::allocator<T>& alloc = std::allocator();
                {
                    
                    arr_data = NULL;
                    arr_size = 0;
                    arr_capacity = 0;

                }

                explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): my_allocator(alloc)
                {
                    arr_size = n;
                    arr_data = my_allocator.allocate(n);// i may need to define my own allocator and use instead , 
                                                    //but only if i'm gonna need it later;
                    for(size_t i = 0; i < n; n++)
                    {
                        my_allocator.construct(&arr_data[i], val);
                    }
                    arr_capacity = n;
                }

                template <class InputIterator>
                Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):my_allocator(alloc)
                {
                    // this focking function may be confused with the above one, so the enable if may be needed;
                    difference_type diff;
                    random_access   it;
                    //diff = last - first;
                    diff = std::distance(first, last);
                    if(diff < 0)
                        diff = diff * (-1);
                    arr_data = my_allocator.allocate(diff);
                    for(difference_type i = 0; i < diff && first != last; i++)
                    {
                        my_allocator.contruct(&arr_data[i], *first);
                        first++;
                    }
                    arr_size = diff;
                    arr_capacity = diff;
                }

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
                    iterator it;
                    it.ptr = &arr_data[0];
                    return(iterator);
                    //l3odama has suggested to add a constructor to rand_acc(pointer) to be constructed
                    // by a pointer and just do (return(arr_data);) so if that dosen't work ....
                 }
                 const_iterator begin() const
                 {
                    const_iterator const_it;
                    const_it.ptr = arr_data;
                    return(const_it);
                 }
                 iterator end()
                 {
                    iterator    it;
                    it.ptr = arr_data + arr_size;
                    return(it);
                 }
                 const_iterator end() const
                 {
                    const_iterator    it;
                    it.ptr = arr_data + arr_size;
                    return(it);
                 }
                reverse_iterator rbegin()
                {
                    reverse_iterator rev_it(end());
                    return(rev_it);
                }
                const_reverse_iterator rbegin() const
                {
                    const_reverse_iterator rev_it(end());
                    return(rev_it);
                }
                reverse_iterator rend()
                {
                    reverse_iterator rev_it(begin());
                    return(rev_it);
                }
                const_reverse_iterator rend() const
                {
                    const_reverse_iterator rev_it(begin());
                    return(rev_it);
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
                // void shrink_to_fit()
                // {
                //     if(arr_capacity > arr_size)
                //     {
                //         my_allocator.deallocate(&arr_data[n], arr_capacity - n);
                //     }
                //     arr_capacity = arr_size;
                // }
                //*************  ELEMENTS ACCESS  ***************
                reference operator[] (size_type n)
                {
                    std::cout << "printing from operator[]" << std::endl;
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
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last)
                {

                }
                void assign (size_type n, const value_type& val)
                {

                }
                void push_back (const value_type& val)
                {

                }
                void pop_back()
                {

                }

                //single element (1)	
                iterator insert (iterator position, const value_type& val)
                {

                }
                //fill (2)	
                    void insert (iterator position, size_type n, const value_type& val)
                    {

                    }
                //range (3)	
                template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last)
                {

                }
                iterator erase (iterator position)
                {

                }
                iterator erase (iterator first, iterator last)
                {

                }
                void swap (vector& x)
                {

                }
                void clear()
                {
                    
                }
                private:
                pointer     arr_data;
                size_type   arr_size;
                allocator_type my_allocator;
                size_type       arr_capacity;

    };
}