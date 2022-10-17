#pragma once
#include <iostream> 
//#include "vector.hpp"
#include "iterator_traits.hpp"

namespace ft
{
    template<class T>
    class random_access : public iterator<std::random_access_iterator_tag, T>
    {
		typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<std::random_access_iterator_tag, T>::pointer				pointer;
		typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
		typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		// perhaps some typdefs are still messing here;
        private:
            pointer ptr;
        public:
            random_access(){};
            random_access(const random_access& it)
            {
                this->ptr = it.ptr;
            }
            random_access& operator=(const random_access& it)
            {
                this->ptr = it.ptr;
                return(*this);
            }
            ~random_access();
        //*********comparison operators************************
        bool	operator==(random_access const &it)
		{
			if(this->ptr == it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator>(random_access const &it)
		{
			if(this->ptr > it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator<(random_access const &it)
		{
			if(this->ptr < it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator<=(random_access const &it)
		{
			if(this->ptr <= it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator>=(random_access const &it)
		{
			if(this->ptr >= it.ptr)
				return(true);
			else 
				return(false);
		}
		bool	operator!=(random_access const &it)
		{
			if(this->ptr != it.ptr)
				return(true);
			else 
				return(false);
		}
        //********dereferenced as an rvalue***********
        pointer operator*()
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
		{
			random_access tmp = *this;
			(this->ptr)++;
			return(tmp);
		}
		random_access operator--(int)
		{
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
		random_access operator+(difference_type const &n)// we can replace diffe.. with int if it dosen't work;
		{
			return(this->ptr + n);// perhaps it won't work , i need to test it;
		}
		random_access operator-(random_access const &it1)
		{
			return(this->ptr - it1.ptr);// perhaps it won't work too;
		}


		friend random_access operator+(int nb, const random_access& it)// we can't define it outside the class def because random_access neets the T 
        {													// which is not defined outside the class def;
            random_access newIt(it);// to not return a refference , but i still need to grasp itd more;
            return (newIt += nb);
        }
        random_access operator-(difference_type const &n)
        {
            return (this->ptr - n);
        }
		//*********** the [] operator  *********
		reference operator[](difference_type n) const// should it be refference and why ???????;
		 {
			return ptr[n];
		 }
		//friend void	print_pointer(pointer ptr);
    };
}