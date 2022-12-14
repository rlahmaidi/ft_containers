#pragma once
#include <iostream>
//#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"

//#define  ; //std::cout  << "DeBug " << __LINE__ << "Function " << __PRETTY_FUNCTION__ << "FILE " << __FILE__ << std::endl;
// token from page 520 in iso+iec
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
    protected:// should not be puplic
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




    reverse_iterator()
    {
        
    }
    explicit reverse_iterator(Iterator x)
    {
        
        this->current = x;
    }
    template <class U> reverse_iterator(const reverse_iterator<U>& u)
    {
        
       
        current = u.base();
    }
    Iterator base() const
    { // explicit
        
        return (current);
    }
    reference operator*() const 
    {
        
        
        Iterator tmp = current;
        return *--tmp;
    }
    pointer operator->() const
    {
        
        return &(operator*());
    }
    reverse_iterator& operator++()
    {
        
        --current;
        return (*this);
    }
    reverse_iterator operator++(int)
    {
        
        reverse_iterator tmp = *this;
        --current;
        return (tmp);
    }
    reverse_iterator& operator--()
    {
        
        ++current;
        return(*this);
    }
    reverse_iterator operator--(int)
    {
        
        reverse_iterator tmp = *this;
        ++current;
        return(tmp);
    }
    reverse_iterator operator+ (difference_type n) const
    {
        
        return(reverse_iterator(current - n));
    }
    reverse_iterator& operator+=(difference_type n)
    {
        
        current -= n;
        return(*this);
    }
    reverse_iterator operator- (difference_type n) const
    {
        
        return(reverse_iterator(current+n));
    }
    reverse_iterator& operator-=(difference_type n)
    {
        current += n;
        return(*this);
    }
    reference operator[](difference_type n) const
    {
        return (*(*this + n));
    }

        template <class U,class X>
        friend bool operator==(const reverse_iterator<U>& x, const reverse_iterator<X>& y)
        {
            return(x.current == y.current);
        }
        template <class U,class X>
        friend bool operator<(
        const reverse_iterator<U>& x,
        const reverse_iterator<X>& y)
        {
            return(x.current > y.current);
        }
        template <class U,class X>
        friend bool operator!=(
        const reverse_iterator<U>& x,
        const reverse_iterator<X>& y)
        {
            return(x.current != y.current);
        }
        template <class U,class X>
        friend bool operator>(
        const reverse_iterator<U>& x,
        const reverse_iterator<X>& y)
        {
            return(x.current < y.current);
        }
        template <class U,class X>
        friend bool operator>=(
        const reverse_iterator<U>& x,
        const reverse_iterator<X>& y)
        {
            return(x.current <= y.current);
        }
        template <class U,class X>
        friend bool operator<=(
        const reverse_iterator<U>& x,
        const reverse_iterator<X>& y)
        {
            return( x.current >= y.current);
        }

};
        // template <class U,class X>
        // bool operator==(const reverse_iterator<U>& x, const reverse_iterator<X>& y)
        // {
        //     return(x.current == y.current);
        // }
        // template <class Iterator>
        // bool operator<(
        // const reverse_iterator<Iterator>& x,
        // const reverse_iterator<Iterator>& y)
        // {
        //     return(x.current > y.current);
        // }
        // template <class Iterator>
        // bool operator!=(
        // const reverse_iterator<Iterator>& x,
        // const reverse_iterator<Iterator>& y)
        // {
        //     return(x.current != y.current);
        // }
        // template <class Iterator>
        // bool operator>(
        // const reverse_iterator<Iterator>& x,
        // const reverse_iterator<Iterator>& y)
        // {
        //     return(x.current < y.current);
        // }
        // template <class Iterator>
        // bool operator>=(
        // const reverse_iterator<Iterator>& x,
        // const reverse_iterator<Iterator>& y)
        // {
        //     return(x.current <= y.current);
        // }
        // template <class Iterator>
        // bool operator<=(
        // const reverse_iterator<Iterator>& x,
        // const reverse_iterator<Iterator>& y)
        // {
        //     return( x.current >= y.current);
        // }
        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator>& x,
        const reverse_iterator<Iterator>& y)
        {
            return(y.base() - x.base());
        }
        template <class Iterator>
        reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>& x)
        {
            return(reverse_iterator<Iterator> (x.base() - n));
        }
            







}

