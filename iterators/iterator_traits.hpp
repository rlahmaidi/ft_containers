#pragma once
#include <iostream>


namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
            // i think i don't need to put public here , since everething is public by defeault in 
            // a struct unlike class , so let's see;
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
    };
    template <class Iterator>
    class iterator_traits
    {
        public: // because we will try to access from outside the class definiton
            typedef typename    Iterator::difference_type   difference_type;
            typedef typename    Iterator::value_type        value_type;
            typedef typename    Iterator::pointer           pointer;
            typedef typename    Iterator::reference         reference;
            typedef typename    Iterator::iterator_category iterator_category;

    };
    template <class T> 
    class iterator_traits<T*>
    {
        public: // because we will try to access from outside the class definiton
            typedef ptrdiff_t                           difference_type;
            typedef T                                   value_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;
            typedef  std::random_access_iterator_tag    iterator_category;
    };
    template <class T> 
    class iterator_traits<const T*>
    {
        public:
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef const  T* pointer;
            typedef const T& reference;
            typedef std::random_access_iterator_tag iterator_category;
    };
    // template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    // struct iterator
    // {
    //     typedef T         value_type;
    //     typedef Distance  difference_type;
    //     typedef Pointer   pointer;
    //     typedef Reference reference;
    //     typedef Category  iterator_category;
    // };
}
