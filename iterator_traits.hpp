#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <iostream>

namespace ft{
    template<class Iterator>
    class iterator_traits
    {
        public:
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::difference_type difference_type;
    };

    template<class T>
    class iterator_traits<T*>
    {
        public:
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ptrdiff_t difference_type;
            typedef std::random_access_iterator_tag category;
    };

    template<class T>
    class iterator_traits<const T*>
    {
        public:
            typedef T value_type;
            typedef const T* pointer;
            typedef const T& reference;
            typedef ptrdiff_t difference_type;
            typedef std::random_access_iterator_tag category;
    };
}

#endif
   