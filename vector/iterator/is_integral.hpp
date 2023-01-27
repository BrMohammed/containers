#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include <iostream>
#include <stdio.h>

namespace ft 
{

    template <class T, class U>
    struct is_same {
        static const bool value = false;
    };
    
    template <class T>
    struct is_same<T, T> {
        static const bool value = true;
    };

    ////////// enable_if/////////
    template<bool Cond, class T = void> 
    struct enable_if
    {
    };
    template<class T> 
    struct enable_if<true, T>
    { 
        typedef T type; 
    };


////////////////////*******************/////////////
    template<typename T>
    struct is_integral {
        static const bool value = false;
    };

    template<>
    struct is_integral<int> 
    {
        static const bool value = true;
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
    struct is_integral<wchar_t> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<signed char> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<short int> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<long int> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<long long int> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned char> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned short int> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned int> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long int> 
    {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long long int> 
    {
        static const bool value = true;
    };
}

#endif