#pragma once
#include <iostream> 
#include "vector.hpp"

namespace ft
{
    template<class T>
    class iterator
    {
        typedef T* pointer;
        
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
            return(this->ptr);
        }
        //************ dereferenced as an lvalue****

        
    };
}