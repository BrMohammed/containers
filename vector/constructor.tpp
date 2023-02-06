#ifndef CONSTRUCTOR_TPP
#define CONSTRUCTOR_TPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Alloc>
    vector<T, Alloc>::vector(const Alloc& alloc) : m_data(NULL) , m_size(0), m_capacity(0),  m_alloc(alloc) {}

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const vector<T,Alloc>& other){*this = other;}

    template <class T, class Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator=(const vector<T,Alloc>& other)
    {
        if (this != &other)
        {
            if (m_capacity < other.m_size)
            {
                destroy_allocator();
                m_data  = m_alloc.allocate(other.m_capacity);
                m_capacity = other.m_capacity;
            }
            m_size = other.m_size;
            iterator it = iterator(other.m_data);
            for (int  i = 0;it != iterator(other.m_data + other.m_size); it++)
                m_alloc.construct(m_data + (i++), *it);

        }
        return *this;
    }


    template <class T, class Alloc>
    vector<T, Alloc>::~vector()
    {
        if(m_capacity)
        {
            for(size_t i = 0 ; i < m_size ; i++)
                m_alloc.destroy(m_data+i);
            m_alloc.deallocate(m_data,m_capacity);
        }
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(size_type n, const value_type& val,const allocator_type& alloc) :m_size(n) ,m_capacity(n), m_alloc(alloc) 
    {
        if(n > 0)
        {
            m_data = m_alloc.allocate(n);
            for(size_type i = 0; i < n ; i++)
                m_alloc.construct(m_data + i , val);
        }
    }

    template <class T, class Alloc>
    template <class Inputiterator>
    vector<T, Alloc>::vector(Inputiterator first, Inputiterator last,const Alloc& alloc, typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type*) : m_alloc(alloc)
    {
        m_size = last - first;
        m_capacity = m_size; 
        m_data  = m_alloc.allocate(m_capacity);
        for (size_t  i = 0;first != last; first++)
        {
            m_alloc.construct(m_data + i, *first);
            i++;
        }
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::assign(size_type n, const value_type& val)
    {
        destroy_allocator();
        m_size = n;
        m_capacity = n;
        m_data = m_alloc.allocate(n);
        for(size_type i = 0;  i < n ; i++)
            m_alloc.construct(m_data + i , val);
    }

    template <class T, class Alloc>
    template <class Inputiterator>
    void vector<T, Alloc>::assign(Inputiterator first, Inputiterator last ,typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type*)
    {
        destroy_allocator();
        m_size = last - first;
        m_capacity = m_size;
        m_data = m_alloc.allocate(m_capacity);
        for (int i = 0;first != last; ++first)
        m_alloc.construct((m_data + (i++)), *first);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const{ return m_alloc; }
}

#endif