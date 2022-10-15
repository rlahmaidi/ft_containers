#pragma once
#include <iostream> 
#include "vector.hpp"

namespace ft
{
    template<class T>
    class iterator
    {
        typedef T* pointer;
		typedef ptrdiff_t	difference_type;// still not sure wither ptrdiif_t already exist 
											//or i should alias it with sizet_t or somthing;
        
        private:
            pointer ptr;
        public:
            iterator(){};
            iterator(const iterator& it)
            {
                this->ptr = it.ptr;
            }
            iterator& operator=(const iterator& it)
            {
                this->ptr = it.ptr;
                return(*this);
            }
            ~iterator();
        //*********comparison operators************************
        bool	iterator::operator==(iterator const &it)
		{
			if(this->ptr == it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	iterator::operator>(iterator const &it)
		{
			if(this->ptr > it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	iterator::operator<(iterator const &it)
		{
			if(this->ptr < it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	iterator::operator<=(iterator const &it)
		{
			if(this->ptr <= it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	iterator::operator>=(iterator const &it)
		{
			if(this->ptr >= it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	iterator::operator!=(iterator const &it)
		{
			if(this->ptr != it.ptr)
				return(true);
			else 
				return(false);
		}
        //********dereferenced as an rvalue***********
        pointer iterator::operator*(iterator const &it)
        {
            return(*ptr);
        }
		pointer operator->() 
		{ 
			return (ptr);// it will always return ptr even if you type(obj->tkharbi9a);
		}
        //************ dereferenced as an lvalue****
		//(*a = t) i think it will work since * and = are already overloaded;
		
		//***************  INCREMENT AND DECREMENT  *******
		iterator& iterator::operator++()
		{// preincrement 
			(this->ptr)++;
			return(*this);
		}
        iterator& iterator::operator--()
		{
			(this->ptr)--;
			return(*this);			
		}
		iterator iterator::operator++(int)
		{
			iterator tmp = *this;
			(this->ptr)++;
			return(tmp);
		}
		iterator iterator::operator--(int)
		{
			iterator tmp = *this;
			(this->ptr)--;
			return(tmp);
		}
		// the *a++ and *a-- should be working since ++ -- and * are overloaded;

		//************   += and -= ************
		iterator &operator+=(difference_type n) 
		{
			 ptr += n; 
			 return (*this); 
		}
		iterator &operator-=(difference_type n) 
		 { 
			ptr -= n;
			return (*this);
		}
		//***************   ARITHMETIQUE OPERATORS  *********
		iterator iterator::operator+(difference_type const &n)// we can replace diffe.. with int if it dosen't work;
		{
			return(this->ptr + n);// perhaps it won't work , i need to test it;
		}
		iterator iterator::operator-(iterator const &it1)
		{
			return(this->ptr - it1.ptr);// perhaps it won't work too;
		}


		friend iterator operator+(int nb, const iterator& it)// we can't define it outside the class def because iterator neets the T 
        {													// which is not defined outside the class def;
            iterator newIt(it);// to not return a refference , but i still need to grasp itd more;
            return (newIt += nb);
        }
        iterator operator-(difference_type const &n)
        {
            return (this->ptr - n);
        }
		//*********** the [] operator  *********
		reference operator[](difference_type n) const// should it be refference and why ???????;
		 {
			return ptr[n];
		 }
		 friend void	print_pointer(pointer ptr);
    };
}