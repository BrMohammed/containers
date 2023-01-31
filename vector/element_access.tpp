#ifndef ELEMENT_ACCESS_TPP
#define ELEMENT_ACCESS_TPP
#include "vector.hpp"

namespace ft
{

    template<class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T,Alloc>::operator[](size_type n)
    { return *(m_data + n);}
    template<class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T,Alloc>::operator[](size_type n) const
    { return *(m_data + n);}

    template<class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
    {
        if(n >= m_size)
            throw std::out_of_range(" *index is out of bounds *");
        else
            return *(m_data + n);
    }

    template<class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
    {
        if(n >= m_size)
            throw std::out_of_range(" *index is out of bounds *");
        return *(m_data + n);
    }

    template<class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {return *(m_data);}

    template<class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {return *(m_data);}

    template<class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {return *(m_data + (m_size - 1));}

    template<class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {return *(m_data + (m_size - 1));}
}
#endif