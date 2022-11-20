#pragma once
#include <iostream> 
//#include "vector.hpp"
#include <iterator>
#include "iterator_traits.hpp"
#define IMHERE ;//std::cout  << "DeBug " << __LINE__ << "Function " << __PRETTY_FUNCTION__ << "FILE " << __FILE__ << std::endl;

namespace ft
{
    template<class T>
    class random_access : public iterator<std::random_access_iterator_tag, T>
    {

		public:
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		// perhaps some typdefs are still messing here;

            random_access(): ptr(NULL)
			{

			}
            random_access(const random_access& it)
            {
				IMHERE
                this->ptr = it.ptr;
            }
			random_access(pointer	_ptr)
			{
				ptr = _ptr; // not required by coo but we need it if we want to retunr from a function
							// that return iterator on specific  position or 
			}
            random_access&  operator=( const random_access& it) // i removed the <T>
            {
				IMHERE
                ptr = it.ptr;
                return(*this);
            }
            ~random_access()
			{
				
			}

			operator random_access<const value_type>() const
            {
                return random_access<const value_type>(ptr);  
            }
        //*********comparison operators************************
        bool	operator==(random_access const &it) const
		{
			if(ptr == it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator>(random_access const &it) const
		{
			if(this->ptr > it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator<(random_access const &it) const
		{
			if(this->ptr < it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator<=(random_access const &it) const
		{
			if(this->ptr <= it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator>=(random_access const &it) const
		{
			if(this->ptr >= it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator!=(random_access const &it) const
		{
			if(this->ptr != it.ptr)
				return(true);
			else 
				return(false);
		}
        //********dereferenced as an rvalue***********
        reference operator*() const
        {
            return (*ptr);
        }
		pointer operator->() const
		{ 
			return (ptr);// it will always return ptr even if you type(obj->tkharbi9a);
		}
        //************ dereferenced as an lvalue****
		// pointer operator&() const 
		// { 
		// 	return (ptr);  me and hamid confirmed that we won't need it
		// }
		//(*a = t) i think it will work since * and = are already overloaded; I WAS WRONG
		
		//***************  INCREMENT AND DECREMENT  *******
		random_access& operator++()
		{// preincrement 
			(this->ptr)++;
			return(*this);
		}
        random_access& operator--()
		{
			(this->ptr)--;
			return(*this);			
		}
		random_access operator++(int)
		{// post
			random_access tmp = *this;
			(this->ptr)++;
			return(tmp);
		}
		random_access operator--(int)
		{//post
			random_access tmp = *this;
			(this->ptr)--;
			return(tmp);
		}
		// the *a++ and *a-- should be working since ++ -- and * are overloaded;

		//************   += and -= ************
		random_access &operator+=(difference_type n)
		{
			 ptr += n; 
			 return (*this); 
		}
		random_access &operator-=(difference_type n)
		 { 
			ptr -= n;
			return (*this);
		}

		//***************   ARITHMETIQUE OPERATORS  *********
		random_access operator+(difference_type const &n) const // we can replace diffe.. with int if it dosen't work;
		{
			return(ptr + n);// perhaps it won't work , i need to test it;
		}
		difference_type operator-(random_access const &it1) const
		{
			return(this->ptr - it1.ptr);// perhaps it won't work too;
		}

	
        random_access operator-(difference_type const &n) const
        {
			return(random_access(ptr - n));
			// ptr -= n;
            // return (*this);
			// i'm putting the const because we can't call a non-const function on a const object
			//(const iterator), but it shouldn't fucking work ,since we changed a data member(ptr)??
        }
		//*********** the [] operator  *********
		reference operator[](difference_type n) const// should it be refference and why ???????;
		 {
			return ptr[n];
		 }
		private:
            pointer ptr;
	
    };

	template<class T>
	random_access<T>	operator+(int nb, const random_access<T>& it) 
    {
		return(it + nb);
    }
}