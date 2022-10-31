#pragma once
#include <iostream>
//#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"

#define IMHERE ; //std::cout  << "DeBug " << __LINE__ << "Function " << __PRETTY_FUNCTION__ << "FILE " << __FILE__ << std::endl;

namespace ft
{




 
template <class Iterator>
class reverse_iterator : public
iterator<typename iterator_traits<Iterator>::iterator_category,
typename iterator_traits<Iterator>::value_type,
typename iterator_traits<Iterator>::difference_type,
typename iterator_traits<Iterator>::pointer,
typename iterator_traits<Iterator>::reference>
{
    public:// should not be puplic
        Iterator current;
    public:
        typedef Iterator
        iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type
        difference_type;
        typedef typename iterator_traits<Iterator>::reference
        reference;
        typedef typename iterator_traits<Iterator>::pointer
        pointer;




    reverse_iterator(){}
    explicit reverse_iterator(Iterator x)
    {
        IMHERE
        this->current = x;
    }
    template <class U> reverse_iterator(const reverse_iterator<U>& u)
    {
        IMHERE
        current = u.current;
    }
    Iterator base() const
    { // explicit
        IMHERE
        return (current);
    }
    reference operator*() const
    {
        IMHERE
        Iterator tmp = current;
        return *--tmp;
    }
    pointer operator->() const
    {
        IMHERE
        return &(operator*());
    }
    reverse_iterator& operator++()
    {
        IMHERE
        --current;
        return (*this);
    }
    reverse_iterator operator++(int)
    {
        IMHERE
        reverse_iterator tmp = *this;
        --current;
        return (tmp);
    }
    reverse_iterator& operator--()
    {
        IMHERE
        ++current;
        return(*this);
    }
    reverse_iterator operator--(int)
    {
        IMHERE
        reverse_iterator tmp = *this;
        ++current;
        return(tmp);
    }
    reverse_iterator operator+ (difference_type n) const
    {
        IMHERE
        return(reverse_iterator(current - n));
    }
    reverse_iterator& operator+=(difference_type n)
    {
        IMHERE
        current -= n;
        return(*this);
    }
    reverse_iterator operator- (difference_type n) const
    {
        IMHERE
        return(reverse_iterator(current+n));
    }
    reverse_iterator& operator-=(difference_type n)
    {
        IMHERE
        current += n;
        return(*this);
    }
    reference operator[](difference_type n) const
    {
        IMHERE
        return(current[-n-1]);// mhaaaloussa m3a si karha;
    }
};
        template <class Iterator>
        bool operator==(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(x.current == y.current);
        }
        template <class Iterator>
        bool operator<(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(x.current > y.current);
        }
        template <class Iterator>
        bool operator!=(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(x.current != y.current);
        }
        template <class Iterator>
        bool operator>(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(x.current < y.current);
        }
        template <class Iterator>
        bool operator>=(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(x.current <= y.current);
        }
        template <class Iterator>
        bool operator<=(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return( x.current >= y.current);
        }
        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(y.current - x.current);
        }
        template <class Iterator>
        reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>& x)
        {
            return(reverse_iterator<Iterator> (x.current - n));
        }
            







}

