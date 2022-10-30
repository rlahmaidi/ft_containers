#include <string>
#include <iostream>

// template <class T> struct is_integral
// {

// };

namespace ft
{
    




template <bool is_const, class T>
struct is_const_result
{
    typedef    T type;
    static const bool value = is_const;
};

/*
template<typename>
    struct is_const_type : public is_const_result<false, bool> {};*/


template<typename>
    struct is_const_type: public is_const_result<false, bool> {};
    //{
        // typedef bool type;
        // vlue = false;
    //}

template<typename T>
    struct is_const_type<const T>: public is_const_result<true, T> {};/*
    {
        typedef T type;
        vlaue = true;
    }

template<typename T>
    struct is_const_type<T>: public is_const_result<false, T> {};*/
    

}


// template <class T> struct is_default_constructible
// {

// };

// template <class T> struct remove_const
// {

// };





int main()
{
    //ft::is_const<int>
    //std::vector<const int>
    static_assert(        !(ft::is_const_type<  cont int>::value)      , "ft_container dont handle const-volatile qualifer");

    //std::cout << ft::is_const_type< int>::value  << std::endl;
}