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
                typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
                typedef typename ft::iterator_traits<Iterator>::value_type value_type;
                typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
                typedef typename ft::iterator_traits<Iterator>::pointer pointer;
                typedef typename ft::iterator_traits<Iterator>::reference reference;

                // typedef typename iterator_type::value_type value_type;
                // typedef typename iterator_type::difference_type difference_type;
                // typedef typename iterator_type::pointer pointer;
                // typedef typename iterator_type::reference reference;
                // typedef typename iterator_type::iterator_category iterator_category;
                
                // all of the constructors need to be tested
                reverse_iterator()
                {

                }

                reverse_iterator(pointer ptr): reverse_it(ptr)
                {
                    
                }
            
                explicit reverse_iterator (iterator_type it)
                {
                    reverse_it = (--it) ;
                }
                template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                {
                    *this = rev_it; // it is like i'm using the same constructor before implementing it;
                                        // it won't work;
                                        //  i will overload the = and use it here; but test first
                }
                //reverse_iterator(const reverse_iterator<iterator_type>& rev_it){ this->operator=(rev_it);};
                reverse_iterator& operator=(const reverse_iterator& rev_it)
                {
                
                    this->reverse_it = --rev_it.base();
                   
                    return(*this);
                }
                iterator_type base() const
                {
                    iterator_type tmp;
                    tmp = reverse_it + 1;
                    return(tmp);// since the base is always one step ahead of reverse;
                }                         // the ++ should work since it is overloaded in base, but.. test
                reference operator*() const
                {
                    // iterator_type   tmp = reverse_it ;// but this dosen't work = (--reverse_it)?? why
                    // return(*tmp);
                    return(*reverse_it);
                }
                reverse_iterator operator+ (difference_type n) const
                {
                    iterator_type  tmp;
                    tmp = (reverse_it -  n + 1);//for you my lazy memory: i'm adding the 1 , because the constructor will do a -1;
                    return(reverse_iterator(tmp));
                }
                reverse_iterator& operator++()
                {
                    --(reverse_it);
                    return(*this);
                }
                reverse_iterator  operator++(int)
                {
                    reverse_iterator    tmp = *this;
                    ++(*this);
                    return(tmp);
                }
                reverse_iterator& operator+= (difference_type n)
                {
                    //reverse_it.operator+=(-n); // reverse_it = reverse_it - n;  should work like this too, .. test;
                    reverse_it -= n;
                    std::cout << "printing from +=" << "\n";
                    return(*this);
                }
                reverse_iterator operator- (difference_type n) const
                {
                    // reverse_it.operator+(n);
                    // //reverse_it -= -n;
                    // return(*this);
                    return(reverse_iterator(reverse_it - n + 1));
                }
                reverse_iterator& operator--()
                {
                    reverse_it.operator++();
                    return(*this);
                }
                reverse_iterator  operator--(int)
                {
                    reverse_iterator tmp = *this;
                    --(*this);
                    return(tmp);
                }
                reverse_iterator& operator-= (difference_type n) 
                {
                    reverse_it += n;
                    return(*this);
                }
                pointer operator->() const 
                {
                    return &(operator*());// copied from cpp , needs to be tested;
                }
                reference operator[] (difference_type n) const
                {
                     // since base = rev + 1 , and we want to go back n from rev;
                    return(*(reverse_it - n)); // i will change it with base;
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
                iterator_type   reverse_it; // to not be confused again , it point where the rev should;
                                            // not where the base should
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
        if(lhs.base() == rhs.base())
            return(true);
        else
            return(false);      
    }
                //(2)
    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.base() != rhs.base())
            return(true);
        else
            return(false);  
    }
    //(3)	
    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.base() < rhs.base())
            return(true);
        else
            return(false);  
    }
    // (4)	
    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.base() <= rhs.base())
            return(true);
        else
            return(false);  
    }
    // (5)	
    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.base() > rhs.base())
            return(true);
        else
            return(false);  
    }
    //(6)	
    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        if(lhs.base() >= rhs.base())
            return(true);
        else
            return(false);
    }
    //operator+(int n, rev_it)
    template <class Iterator>
    reverse_iterator<Iterator> operator+ (
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it)
    {
        return(reverse_iterator<Iterator>(rev_it + n));
    }
    //************operator-(rev_it , rev_it)
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs)
    {
        return(rhs.base() - lhs.base());// cause the difference betwen their bases is the
                                        // same as the diff between their rev_it;
        //return(rhs.reverse_it - lhs.reverse_it);
    }
}

