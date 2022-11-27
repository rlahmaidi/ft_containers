#pragma once
#include <iostream> 
#include "vector.hpp"

namespace ft
{
    template <class T> 
    class allocator
    {
        public:
            typedef T value_tupe;
            typedef T* pointer;
            typedef T& reference;
            typedef const t* const_pointer;
            typedef const T& const_reference;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type; // not sure what this is  too;
            typedef member class rebind<type>;//not sure what this is, just saw it on the bible;
                //*** constructors*******//
                allocator() throw()
                {
                    //no fuckin shit can be done here;
                }
                allocator (const allocator& alloc) throw()
                {
                    
                }
                template <class U>  
                allocator (const allocator<U>& alloc) throw()
                {
                    
                }
                //*********destructor*******//
                ~allocator ( ) throw;
                //************address********//
                pointer address ( reference x ) const
                {

                }
                const_pointer address ( const_reference x ) const
                {

                }
                //*********allocator*********
                pointer allocate (size_type n, allocator<void>::const_pointer hint=0)
                {
                    return(static_cast<T*> (new (n * sizeof(T)))); // may be new can't be called like that in that context;
                }                               //dynamic cast seems to be the right one, but every docomentation is using static?
                //*******deallocate*******
                void deallocate (pointer p, size_type n)
                {
                    delete p;
                }
                size_type max_size() const throw()
                {

                }
                //*******construct****
                void construct ( pointer p, const_reference val )
                {
                    p(val);// for this to work the copy constructor need to be implemented;
                }
                //*********destroy*****//
                void destroy (pointer p)
                {

                }
                //**********comparaison operators******//
                bool operator=(reference other)
                {
                    if(this->)
                }
                //
                // I'M MESSING SOME REBIND CLASS HERE OR SOMETHING, AND A
                // A TEMPLATE SPECIALIZATION FOR VOID TYPE;
    };
    //2- I NEED TO OVERLOAD THE COMPARAISON AND THE DIFFerence operator here, but don't know what to give it in  parametre;
}