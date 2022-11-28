#pragma once
#include <iostream>
#include <iterator>
#include <limits.h>
#include <iterator>
#include <vector>
#include <exception>
#include "../ITERATORS/random_access_iterator.hpp"
#include "../ITERATORS/reverse_iterator.hpp"
#include "../UTILS/enable_if.hpp"
#include "../UTILS/is_integral.hpp"
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
                typedef ft::random_access<value_type> iterator; 
                //typedef T* iterator;
                typedef  ft::random_access<const value_type> const_iterator;
               // typedef pointer iterator;
                //typedef pointer const_iterator;
                // if iteratror iterate over int const iterator will iterate over const int;
                typedef ft::reverse_iterator<iterator>      reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>      const_reverse_iterator;
                typedef typename  std::ptrdiff_t      difference_type;
                typedef size_t size_type;

                //****************** constructors ************    
                explicit Vector (const allocator_type& alloc = allocator_type()):  my_allocator(alloc)
                {
                    arr_data = NULL;
                    arr_size = 0;
                    arr_capacity = 0;
                }

                explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): my_allocator(alloc)
                {
                    arr_size = n;
                    arr_data = my_allocator.allocate(n);
                                                    
                    for(size_t i = 0; i < n; i++)
                    {
                        my_allocator.construct(&arr_data[i], val);
                    }
                    arr_capacity = n;
                }
                template <class InputIterator>
		        Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL) : my_allocator(alloc) //(first, last)
                {    
                    (void ) f;   	
                    difference_type diff;
                    diff = std::distance(first, last);
                    if(diff < 0)
                        diff = diff * (-1);
                    arr_data = my_allocator.allocate(diff);
                    for(difference_type i = 0; i < diff && first != last; i++)
                    {
                        my_allocator.construct(&arr_data[i], *first);
                        first++;
                    }
                    arr_size = diff;
                    arr_capacity = diff;
                }

                Vector (const Vector& x)
                {
                   //+//*this = x;// seems logic to me cause we already have the '=' overloaded but ....?
                    this->arr_size = x.size();
                    this->arr_data = my_allocator.allocate(x.size());
                    for(size_type i = 0; i < x.size(); i++)
                    {
                        my_allocator.construct(arr_data + i, x.arr_data[i]);
                    }
                    this->arr_capacity = x.capacity();
                }
                //******************destructor************
                ~Vector()
                {
                    pointer         arrb = &*begin(); // may be i will modify this cha3wada to make more clear later;
                    pointer         arre = &*end();
                    while (arrb != arre)
                    {
                        my_allocator.destroy(arrb);
                        arrb++;
                    }
                    my_allocator.deallocate(&*begin(), arr_size);
                    arr_size = 0;
                    arr_capacity = 0;
                }
                //************   copy assignement operator   *****
                Vector& operator= (const Vector& x)
                {
                    if (this->arr_data)
                        {
                            pointer         arrb = &*begin();
                            pointer         arre = &*end();
                            while (arrb != arre)
                            {
                                my_allocator.destroy(arrb);
                                arrb++;
                            }
                            my_allocator.deallocate(&*begin(), arr_size);
                            arr_size = 0;
                            arr_capacity = 0;
                        }
                    this->arr_size = x.size();
                    this->arr_data = my_allocator.allocate(x.size());
                    for(size_type i = 0; i < x.size(); i++)
                    {
                        my_allocator.construct(arr_data + i, x.arr_data[i]);
                    }
                    this->arr_capacity = x.capacity();
                    return(*this);
                }
                //*************   iterators    *************
                 iterator begin()
                 {
                    return(iterator(&arr_data[0]));
                 }
                 const_iterator begin() const
                 {  
                    const_iterator const_it = arr_data;

                    return(const_it);
                 }
                 iterator end()
                 {
                    return(iterator(arr_data + arr_size ));
                 }
                 const_iterator end() const
                 {
                    const_iterator    it(arr_data + arr_size);
                    
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
                    return(my_allocator.max_size());
                }
                void resize (size_type n, value_type val = value_type())
                {
                    if(n < arr_size)
                    {
                        for(size_type i = n; i < arr_size; i++)
                            my_allocator.destroy(&arr_data[i]);
                        arr_size = n;
                    }
                    else if(n > arr_size && n <= arr_capacity)
                    {
                        for(size_type i = arr_size; i < n; i++)
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
                            for(size_type i = 0; i < arr_size; i++)
                            {
                                my_allocator.construct(&tmp_arr[i], arr_data[i]);
                                my_allocator.destroy(&arr_data[i]);
                            }
                            for(size_type i = arr_size; i < n; i++)
                            {
                                my_allocator.construct(&tmp_arr[i], val);
                            }
                            my_allocator.deallocate(arr_data,arr_capacity);
                            arr_data = tmp_arr;
                            arr_capacity = n;
                            arr_size = n;
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
                    if(n > max_size())
                    {
                         std::bad_alloc();
                    }
                    try
                    {
                        if(n > arr_capacity)
                        {
                            pointer tmp_arr;
                            tmp_arr = my_allocator.allocate(n);
                            for(size_type i = 0; i < arr_size; i++)
                            {
                                my_allocator.construct(&tmp_arr[i], arr_data[i]);
                                my_allocator.destroy(&arr_data[i]);
                            }
                            my_allocator.deallocate(arr_data,arr_capacity);
                            arr_data = tmp_arr;
                            arr_capacity = n;
                        }
                    }
                    catch(std::bad_alloc& ba)
                    {
                        std::cout << "bad alloc caught"  << std::endl;
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
                    return(arr_data[n]);
                }
                const_reference operator[] (size_type n) const
                {
                    return(arr_data[n]);
                }
                reference at (size_type n)
                {
                    if(n >= arr_size)
                        throw std::out_of_range("this index is out of bounds of valid elements");
                    return(*(arr_data + n));
                        
                }
                const_reference at (size_type n) const
                {
                    if(n >= arr_size)
                        throw std::out_of_range("this index is out of bounds of valid elements");
                    return(*(arr_data + n));
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
                
                //**************  MODIFIERS  ************
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last)
                { //Replaces the contents with copies of those in the range [first, last)
                // . The behavior is undefined if either argument is an iterator into *this
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
                void assign (size_type n, const value_type& val)
                {
                     arr_size = n;
                     if(arr_capacity < arr_size)
                     {
                        my_allocator.deallocate(arr_data, arr_capacity);
                        arr_capacity = arr_size;
                        arr_data = my_allocator.allocate(arr_capacity);
                     }
                     for(size_type i = 0; i < arr_size ; i++)
                     {
                        my_allocator.construct(arr_data + i, val);
                     }             
                }
                void push_back (const value_type& val)
                {
                    if(arr_capacity == arr_size)
                    {
                        if(!arr_capacity)
                        {
                            reserve(1);
                        }
                        else
                        {
                            reserve(arr_capacity * 2);
                        }
                    }
                    my_allocator.construct(&arr_data[arr_size], val);
                    arr_size++;
                }
                void pop_back()
                {
                        if(arr_size)
                        {
                            my_allocator.destroy(&arr_data[arr_size - 1]);
                            arr_size--;
                        }
                }

                iterator erase (iterator position)
                {
                    difference_type diff;
                    diff = abs(std::distance(begin(), position)); 

                    for(size_type i = diff; i < arr_size; i++)
                    {
                        my_allocator.construct(&arr_data[i], arr_data[i + 1]);
                    }
                    arr_size--;
                    my_allocator.destroy(&arr_data[arr_size - 1]);
                    return(iterator(arr_data + diff));
                }
                iterator erase (iterator first, iterator last)
                {
                    difference_type diff, fl;
                    diff = abs(std::distance(begin(), first));
                    fl = abs(std::distance(first, last));
                    for(size_type i = diff; i + fl < arr_size; i++)
                    {
                        my_allocator.construct(&arr_data[i], arr_data[i + fl]);
                    }
                    arr_size -= fl;
                    for(size_type i = diff + fl; i < arr_size; i++)
                    {
                        my_allocator.destroy(&arr_data[i]);
                    }
                    return(arr_data + diff);
                    //"An invalid position or range causes undefined behavior". form cplus
                    // so i don't have to check for range or postion validity.
                }
                void swap (Vector& x)
                {
                    size_type   tmp;
                    tmp = x.arr_capacity;
                    x.arr_capacity = arr_capacity;
                    arr_capacity = tmp;
                    tmp = x.arr_size;
                    x.arr_size = arr_size;
                    arr_size = tmp;
                    pointer tmp_arr;

                    tmp_arr = x.arr_data;
                    x.arr_data = arr_data;
                    arr_data = tmp_arr;
                    // Vector tmp(*this);
                    // *this = x;           this small vesion will be tested later;
                    // x = tmp;
                    // why wouldn't this work;
                    //√ casue we will reallocate at operatro=
                    // and our iterators will be invalidate;
                }
                void clear()
                {// although it is called clear we can't deallocate here, otherwise we
                //  will be causing a double free , cause we will free at destructor;
                    for(size_type i = 0; i < arr_size; i++)
                    {
                        my_allocator.destroy(&arr_data[i]);
                    }
                    arr_size = 0;
                }
                iterator insert (iterator position, const value_type& val)
                {
                    difference_type diff  = abs(position -  begin());

                        if(arr_capacity == arr_size)
                        {
                            if(!arr_capacity)
                                reserve(1);
                            else 
                                reserve(arr_capacity * 2);
                        }
                        for(difference_type i = arr_size; i > diff; i--)
                        {// REM :arr_size is the lenght of the segement and diff is the distace form position
                            my_allocator.construct(&arr_data[i], arr_data[i - 1]);
                        }
                        
                        my_allocator.construct(&arr_data[diff], val);
                        arr_size++;
                        return(iterator(arr_data + diff));
                }
        
                //fill (2)	
                void insert (iterator position, size_type n, const value_type& val)
                {
                    difference_type diff;
                    if(arr_size == 0)
                        diff = 0;
                    else
                        diff = abs(std::distance(begin(), position));
                     
                    if (arr_size + n > arr_capacity)
                    {
                        if (arr_size + n <= arr_capacity * 2)
                            reserve(arr_capacity * 2);
                        else
                            reserve(arr_size + n);
                    }
                    if(arr_size != 0)
                    {
                        for(difference_type i = arr_size - 1 ; i >= diff; i--)
                        {// because we are moving n element from the arr;
                            my_allocator.construct(&arr_data[i + n], arr_data[i]);
                        }
                    }
                    arr_size += n;
                    for(difference_type i = diff; n > 0; i++)
                    {
                        my_allocator.construct(&arr_data[i], val);
                        n--;
                    }
                }

                //range (3)	
                template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last ,typename
                ft::enable_if< !ft::is_integral<InputIterator>::value >::type *usless = 0)
                {// hi future rachid(the explanation you gonna forget): if is_integral returned true we will get false above
                    // which means our type won't be difined and so the compiler will face an error  recognizing the last argument
                    // and eventually dropping this signature of the function candidate.
                    // in other case type will be  defined and function will considered as a candiate(the winning one of course)
                    // and we won't use that dummy parametre .
                    (void)usless;
                    difference_type diff;
                    if(arr_size == 0)
                        diff = 0;
                    else
                        diff = abs(std::distance(begin(), position));
                    difference_type n = last - first;
                    
                    if (arr_size + n > arr_capacity)
                    {
                        if (arr_size + n <= arr_capacity * 2)
                            reserve(arr_capacity * 2);
                        else
                            reserve(arr_size + n);
                    }

                    if(arr_size != 0)
                    {
                        for(difference_type i = arr_size - 1 ; i >= diff; i--)
                        {
                            my_allocator.construct(&arr_data[i + n], arr_data[i]);
                            
                        }
                    }
                    arr_size += n; 
                    for(difference_type i = diff; n > 0 && first != last; i++)
                    {
                        my_allocator.construct(&arr_data[i], *first);
                        n--;
                        first++;
                    }
                }
                allocator_type get_allocator() const
                {
                    return(my_allocator);
                }

                private:
                pointer     arr_data;
                size_type   arr_size;
                allocator_type my_allocator;
                size_type       arr_capacity;

    };

                //(1)	
                template <class T, class Alloc>
                bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
                {
                    if(lhs.size() != rhs.size())
                        return(false);
                    for(size_t i = 0; i < lhs.size(); i++)
                    {
                        if(lhs[i] != rhs[i])
                            return(false);

                    }
                    return(true);
                    
                }
                //(2)	
                template <class T, class Alloc>
                bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
                {
                    if(lhs.size() != rhs.size())
                        return(true);
                    for(size_t i = 0; i < lhs.size(); i++)
                    {
                        if(lhs[i] != rhs[i])
                            return(true);

                    }
                    return(false);
                }
                // //(3)	
                template <class T, class Alloc>
                bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
                {
                    size_t i = 0;
                    for(; i < lhs.size() ; i++)
                    {
                        if(i == rhs.size() || rhs[i] < lhs[i])// try the same thing with operator* ins of []
                            return(false);
                        else if(lhs[i] < rhs[i])
                            return(true);

                    }
                    return(i != rhs.size());
                }
                // //(4)	
                 template <class T, class Alloc>
                bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
                {
                    size_t i = 0;
                    for(; i < lhs.size() ; i++)
                    {
                       
                        if(i == rhs.size() || rhs[i] < lhs[i])
                            return(false);
                        else if(lhs[i] < rhs[i])
                            return(true);

                    }
                    if(rhs.size() >= lhs.size())
                        return(true);
                    else
                        return(false);
                }
                // //(5)	
                template <class T, class Alloc>
                bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
                {
                    size_t i = 0;
                    for(; i < rhs.size() ; i++)
                    {
                        if(i == lhs.size() || rhs[i] > lhs[i])// try the same thing with operator* ins of []
                            return(false);
                        else if(lhs[i] > rhs[i])
                            return(true);

                    }
                    return(i != lhs.size());
                }
                // //(6)	
                template <class T, class Alloc>
                bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
                {
                    size_t i = 0;
                    for(; i < rhs.size() ; i++)
                    {
                       
                        if(i == lhs.size() || rhs[i] > lhs[i])
                            return(false);
                        else if(lhs[i] > rhs[i])
                            return(true);

                    }
                    if(rhs.size() <= lhs.size())
                        return(true);
                    else
                        return(false);
                }
                //swap
                template <class T, class Alloc>
                void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
                {
                    x.swap(y);
                            
                }
}
