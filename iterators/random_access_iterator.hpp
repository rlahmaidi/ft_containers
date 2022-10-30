#pragma once
#include <iostream> 
//#include "vector.hpp"
#include <iterator>
#include "iterator_traits.hpp"

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
                this->ptr = it.ptr;
            }
			random_access(pointer	_ptr)
			{
				ptr = _ptr; // not required by coo but we need it if we want to retunr from a function
							// that return iterator on specific  position or 
			}
             random_access&  operator=( const random_access  & it) // i removed the <T>
            {
                ptr = it.ptr;
                return(*this);
            }
            ~random_access()
			{
				
			}

			//copied from youssef ssabbah
			operator random_access<const value_type>() const
            {
                return random_access<const value_type>(ptr);  // DON'T WITHER I NEED IT OR NOT;
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

		// //to test
		// template <class Iterator>
		// reverse_iterator<Iterator>
		// operator+(
		// typename reverse_iterator<Iterator>::difference_type n,
		// const reverse_iterator<Iterator>& x);
        //     iterator_op operator+(int nb) const
        //     {
        //         // std::cout << "test" << std::endl;                
        //         iterator_op it(*this);
        //         add(it._ptr, nb);
        //         return (it);
        //     }
        //       iterator_op operator-(int nb) const
        //     {
        //         iterator_op it(*this);
        //         sub(it._ptr, nb);
        //         return (it);
        //     }
		// // end to test

		//friend random_access operator+(int nb, const random_access& it); // we can't define it outside the class def because random_access neets the T 
        // {													// which is not defined outside the class def;
        //     random_access newIt(it);// to not return a refference , but i still need to grasp itd more;
        //     return (newIt += nb);
        // }
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
		//friend void	print_pointer(pointer ptr);
    };

	template<class T>
	random_access<T>	operator+(int nb, const random_access<T>& it) // we can't define it outside the class def because random_access neets the T 
    {													// which is not defined outside the class def;
        // random_access newIt(it);// to not return a refference , but i still need to grasp itd more;
        // return (newIt += nb);
		return(it + nb);
    }
}