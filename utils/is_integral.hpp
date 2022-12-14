
#pragma once

namespace ft
{// later i will try to declare the value as a data member and change it accordingly and test to see ;
    template<class T>
    struct is_integral
    {
        static const bool value = false;
    };

    template<>
    struct is_integral<bool>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<short>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<long>
    {
        static const bool value = true;
    };


    template<>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<long long>
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };
    
    template<>
    struct is_integral<float>
    {
        static const bool value = false;
    };

    template<>
    struct is_integral<double>
    {
        static const bool value = false;
    };

    template<>
    struct is_integral<long double>
    {
        static const bool value = false;
    };

}