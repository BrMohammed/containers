#ifndef CAPACITY_TPP
#define CAPACITY_TPP

#include "vector.hpp"
#include <cstring>

namespace ft
{
        template <class T, class Alloc>
        typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const{ return m_size; }

        template <class T, class Alloc>
        typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const{ return m_capacity; }

        template <class T, class Alloc>
        typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
        {
            if (is_same<T,char*>::value)
                return (m_alloc.max_size() / 2);
            return (m_alloc.max_size());
        }

        template <class T, class Alloc>
        void vector<T, Alloc>::resize ( typename vector<T, Alloc>::size_type n, value_type val)
        {
            if(n == 0)
                clear();
            else if (n < m_size)
                erase(begin() + n, end());
            else if (n > m_size)
                insert(end(), n - m_size, val);
        }

        template <class T, class Alloc>
        void vector<T, Alloc>::reserve( typename vector<T, Alloc>::size_type n)
        {   
            if(n > m_alloc.max_size())
                throw std::length_error("Length exception");
            if(m_capacity < n)
            {
                pointer t_data = m_alloc.allocate(n);
                if(m_data)
                {
                    for(size_t i = 0; i < m_size; i++)
                    {
                        m_alloc.construct(t_data + i , *(m_data + i));
                        m_alloc.destroy(m_data + i);
                    }
                    m_alloc.deallocate(m_data,m_capacity);
                }
                m_data = t_data;
                m_capacity = n;
            }
        }

        template <class T, class Alloc>
        bool vector<T, Alloc>::empty() const
        {
            if(m_size == 0)
                return true;
            return false;
        }
}

#endif