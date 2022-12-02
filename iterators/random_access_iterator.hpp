#pragma once
#include <iostream> 
//#include "vector.hpp"
#include <iterator>
#include "iterator_traits.hpp"
//#define IMHERE ; std::cout  << " DeBug " << __LINE__ << "  Function " << __PRETTY_FUNCTION__ << " FILE " << __FILE__ << std::endl;

namespace ft
{
    template<class T>
    class random_access /*: public iterator<std::random_access_iterator_tag, T>*/
    {

		public:
		
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		

            random_access(): ptr(NULL)
			{

			}
            random_access(const random_access& it)
            {
				
                this->ptr = it.ptr;
            }
			random_access(pointer	_ptr)
			{
				ptr = _ptr;  
			}
            random_access&  operator=( const random_access& it)
            {
				
                ptr = it.ptr;
                return(*this);
            }
            ~random_access()
			{
				
			}

			//operator for conversion from 'Iterator<int>' to Iterator<const int>'
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
			return (ptr);
		}
    
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
		random_access & operator+=(difference_type n)
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
		random_access operator+(difference_type const &n) const 
		{
			return(ptr + n);
		}
		difference_type operator-(random_access const &it1) const
		{
			return(this->ptr - it1.ptr);
		}

	
        random_access operator-(difference_type const &n) const
        {
			return(random_access(ptr - n));
        }
		//*********** the [] operator  *********
		reference operator[](difference_type n) const
		 {
			return ptr[n];
		 }

	
		 pointer base() const 
		 {
			 return ptr; 
		 }
		private:
            pointer ptr;
	
    };

	template<class T>
	random_access<T>	operator+(int nb, const random_access<T>& it) 
    {
		return(it + nb);
    }

    template <class T>
    bool operator== (const random_access<T>& lhs, const random_access<T>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class T>
    bool operator!= (const random_access<T>& lhs, const random_access<T>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class T>
    bool operator<  (const random_access<T>& lhs, const random_access<T>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class T>
    bool operator<= (const random_access<T>& lhs, const random_access<T>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class T>
    bool operator>  (const random_access<T>& lhs, const random_access<T>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class T>
    bool operator>= (const random_access<T>& lhs, const random_access<T>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
}