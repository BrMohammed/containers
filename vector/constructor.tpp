#ifndef CONSTRUCTOR_TPP
#define CONSTRUCTOR_TPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Alloc>
    vector<T, Alloc>::vector(const Alloc& alloc) : m_data(NULL) , m_size(0), m_capacity(0),  m_alloc(alloc) {}

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const vector<T,Alloc>& other)
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
        *this = other;
    }

    template <class T, class Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator=(const vector<T,Alloc>& other)
    {
        if (this != &other)
        {
            destroy_allocator();
            m_data  = m_alloc.allocate(other.m_capacity);
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            iterator it = iterator(other.m_data);
            for (int  i = 0;it != iterator(other.m_data + other.m_size); it++)
                m_alloc.construct(m_data + (i++), *it);
        }
        return *this;
    }

    template <class T, class Alloc>//size
    vector<T, Alloc>::vector(size_type n, const value_type& val,const allocator_type& alloc) :m_alloc(alloc) 
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
        if(n > m_alloc.max_size())
            throw std::length_error("Length exception");
        if(n > 0)
        {
            m_data = m_alloc.allocate(n);
            for(size_type i = 0; i < n ; i++)
                m_alloc.construct(m_data + i , val);
        }
        m_size = n;
        m_capacity = n;
    }

    template <class T, class Alloc>
    template <class Inputiterator>
    vector<T, Alloc>::vector(Inputiterator first, Inputiterator last,const Alloc& alloc, typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type*) : m_alloc(alloc)
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
        if (!is_same<std::random_access_iterator_tag ,typename std::iterator_traits<Inputiterator>::iterator_category>::value)
        {
            for(;first != last; first++)
                push_back(*first);
        }
        else
        {
            m_size = std::distance(first,last);
            m_capacity = m_size;
            m_data  = m_alloc.allocate(m_capacity);
            for (size_t  i = 0;first != last; first++)
                m_alloc.construct(m_data + (i++), *first);
        }
    }

    template <class T, class Alloc>
    vector<T, Alloc>::~vector()
    {
        if(m_data) 
        {
            for(size_t i = 0 ; i < m_size ; i++)
                m_alloc.destroy(m_data + i );
            m_alloc.deallocate(m_data,m_capacity);
            m_size = 0;
            m_capacity = 0;
            m_data = NULL;
        }
    }
    template <class T, class Alloc>
    void vector<T, Alloc>::assign(size_type n, const value_type& val)
    {
        if(n > 0)
        {
            if(m_data)
            {
                for(size_t i = 0 ; i < m_size ; ++i)
                    m_alloc.destroy(m_data + i);
                m_alloc.deallocate(m_data,m_capacity);
            }
            m_size = n;
            if(n > m_capacity)
                m_capacity = n;
            m_data = m_alloc.allocate(m_capacity);
            for(size_type i = 0;  i < n ; i++)
                m_alloc.construct(m_data + i , val);
        }

    }

    template <class T, class Alloc>
    template <class Inputiterator>
    void vector<T, Alloc>::assign(Inputiterator first, Inputiterator last ,typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type*)
    { 
        if (!is_same<std::random_access_iterator_tag ,typename std::iterator_traits<Inputiterator>::iterator_category>::value)
        {
            if(m_data)
            {
                for(size_t i = 0 ; i < m_size ; ++i)
                    m_alloc.destroy(m_data + i);
                m_alloc.deallocate(m_data,m_capacity);
            }
            for(;first != last; first++)
                push_back(*first);
        }
        else
        {
            size_t tmp = std::distance(first,last);
            pointer t_data = m_alloc.allocate(tmp);
            for (size_t  i = 0;first != last; first++)
                m_alloc.construct(t_data + (i++), *first);
            if(m_data)
            {
                for(size_t i = 0 ; i < m_size ; ++i)
                    m_alloc.destroy(m_data + i);
                m_alloc.deallocate(m_data,m_capacity);
            }
            m_size = tmp;
            m_capacity = m_size;
            m_data = t_data;
        }
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const{ return m_alloc; }
}

#endif