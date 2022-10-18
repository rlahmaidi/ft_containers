#pragma once
#include <iostream>
//#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
                typedef Iterator iterator_type;
                //typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
                // typedef typename ft::iterator_traits<Iterator>::value_type value_type;
                // typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
                // typedef typename ft::iterator_traits<Iterator>::pointer pointer;
                // typedef typename ft::iterator_traits<Iterator>::reference reference;

                typedef typename iterator_type::value_type value_type;
                typedef typename iterator_type::difference_type difference_type;
                typedef typename iterator_type::pointer pointer;
                typedef typename iterator_type::reference reference;
                typedef typename iterator_type::iterator_category iterator_category;
                
                // all of the constructors need to be tested
                reverse_iterator()
                {

                }
            
                explicit reverse_iterator (iterator_type it)
                {
                    reverse_it(--it) ;
                }
                template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                {
                    reverse_it(rev_it) ; // i need to make sure it is working;
                }
                iterator_type base() const
                {
                    return(++(reverse_it));// since the base is always one step ahead of reverse;
                }                         // the ++ should work since it is overloaded in base, but.. test
                reference operator*() const
                {
                    iterator_type   tmp = (--reverse_it);
                    return(*tmp);
                }
                reverse_iterator operator+ (difference_type n) const
                {
                    return(reverse_it - n);
                }
                reverse_iterator& operator++()
                {
                    return(--reverse_it);
                }
                reverse_iterator  operator++(int)
                {
                    reverse_iterator    tmp = *this;
                    ++(*this);
                    return(tmp);
                }
                reverse_iterator& operator+= (difference_type n)
                {
                    reverse_it.operator+=(n); // reverse_it = reverse_it + n;  should work like this too, .. test;
                    return(*this);
                }
                reverse_iterator operator- (difference_type n) const
                {
                    reverse_it.operator+(n);
                    return(*this);
                }
                reverse_iterator& operator--()
                {
                    reverse_it.operator++();
                    return(*this);
                }
                reverse_iterator  operator--(int)
                {
                    iterator_type tmp = *this;
                    --(*this);
                    return(tmp);
                }
                reverse_iterator& operator-= (difference_type n)
                {
                    reverse_it.operator+=(n);
                    return(*this);
                }
                pointer operator->() const 
                {
                    return &(operator*());// copied from cpp , needs to be tested;
                }
                reference operator[] (difference_type n) const
                {
                    reverse_it -= n + 1; // since base = rev + 1 , and we want to go back n from rev;
                    return(*this);
                }
                // // **************OPERATOR+*********
                // template <class Iterator>// THIS  WORKS FOR THE CASE n + obj;
                // reverse_iterator<Iterator> operator+ (
                //  typename reverse_iterator<Iterator>::difference_type n,
                //  const reverse_iterator<Iterator>& rev_it)
                //  {
                //    return(rev_it + n);

                //  }       // SHODOW ERROR STILL HERE;

                // //***********operator-*****

                // template <class Iterator>
                //  typename reverse_iterator<Iterator>::difference_type operator- (
                // const reverse_iterator<Iterator>& lhs,
                // const reverse_iterator<Iterator>& rhs)
                // {
                //     return(lhs - rhs);
                // }

        private:
                iterator_type   reverse_it;
    };
    // should those fuckers be freind?(NOTE: WE DON'T USE ANY PRIVATE MEMBER BELOW)
    // if the below dosen't work, i will declare them friend and do the following:
    // if(lhs.reverse_it.operator*() < rhs.reverse_it.operator*())
    // but this rise the question, are we sure we will work with our rand_acc
    // and we have th operator*()????/
    //(1)
    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.operator==(rhs))
            return(true);
        else
            return(false);      
    }
                //(2)
    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.operator!=(rhs))
            return(true);
        else
            return(false);  
    }
    //(3)	
    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.operator<(rhs))
            return(true);
        else
            return(false);  
    }
    // (4)	
    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.operator<=(rhs))
            return(true);
        else
            return(false);  
    }
    // (5)	
    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.operator>(rhs))
            return(true);
        else
            return(false);  
    }
    //(6)	
    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.operator>=(rhs))
            return(true);
        else
            return(false);
    }
}

