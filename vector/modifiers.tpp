#ifndef MODIFIERS_TPP
#define MODIFIERS_TPP
#include "vector.hpp"

namespace ft
{
    template <class T, class Alloc>
    void vector<T, Alloc>::push_back (const value_type& val)
    {
       if(m_size == m_capacity) 
       {
            pointer t_data;
            if(m_capacity == 0) 
            {
                t_data = m_alloc.allocate(2);
                m_capacity = 2;
            }
            else 
            {
                t_data = m_alloc.allocate(m_size * 2);
                memcpy(t_data,m_data,m_capacity * sizeof(value_type));
                m_capacity = m_size * 2;
            }
            m_alloc.deallocate(m_data, m_size);
            m_data = t_data;
        }
        m_alloc.construct(m_data + m_size,val);
        m_size++;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::pop_back()
    {
        m_alloc.destroy(m_data + m_size);
        m_size--;
    }

    template <class T, class Alloc>
   typename vector<T, Alloc>::iterator vector<T, Alloc>::insert (typename vector<T, Alloc>::iterator position, const value_type& val)
    {
        pointer t_data = m_alloc.allocate(m_size * 2);
        int index = position - iterator(m_data) ;
        memcpy(t_data, m_data , (index )* sizeof(value_type));
        memcpy(t_data + index , &val , sizeof(value_type));
        memcpy(t_data + index + 1, m_data + index, (m_size - (index)) * sizeof(value_type));
        m_alloc.deallocate(m_data, m_capacity);
        m_data = t_data;
        m_size++;
        if(m_size == m_capacity)
            m_capacity = m_size * 2;
        return m_data + index;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::insert (iterator position, size_type n, const value_type& val)
    {
        pointer t_data = m_alloc.allocate(m_size + n);
        int index = position - iterator(m_data) ;
        memcpy(t_data, m_data , (index )* sizeof(value_type));
        for(int i = 0 ; i < n ; i++)
            memcpy(t_data + index + i , &val , sizeof(value_type));
        memcpy(t_data + index + n, m_data + index, (m_size - (index)) * sizeof(value_type));
        m_alloc.deallocate(m_data, m_capacity);
        m_data = t_data;
        m_size += n;
        if (m_size > m_capacity)
            m_capacity = m_size;   
    }

    template <class T, class Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position,InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
    {
        size_type distence = last - (first );
        pointer t_data = m_alloc.allocate(m_size + distence);
        int index = position - iterator(m_data) ;
        memcpy(t_data, m_data , (index )* sizeof(value_type));       
        memcpy(t_data + index, &(*first), distence *  sizeof(value_type));
        int index2 = m_size - index  ;
        memcpy(t_data + (index + distence) , m_data + (index), index2 * sizeof(value_type));
        m_alloc.deallocate(m_data, m_capacity);
        m_data = t_data;
        m_size += distence;
        if (m_size > m_capacity)
            m_capacity = m_size;

    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
    {
        pointer t_data = m_alloc.allocate(m_capacity);
        int index = position - iterator(m_data) ;
        memcpy(t_data, m_data , (index)* sizeof(value_type));
        memcpy(t_data + index, m_data + index + 1, (m_size - (index + 1)) * sizeof(value_type));
        m_alloc.deallocate(m_data, m_capacity);
        m_data = t_data;
        m_size--;
        return m_data + index;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator  vector<T, Alloc>::erase(iterator first, iterator last)
    {
        size_type distence = last - (first );
        pointer t_data = m_alloc.allocate(m_capacity);
        int index = first - iterator(m_data) ;
        memcpy(t_data, m_data , (index)* sizeof(value_type));
        int index2 = last - iterator(m_data) ;
        memcpy(t_data + index , m_data + (index2), (m_size - (index2)) * sizeof(value_type));
        m_alloc.deallocate(m_data, m_capacity);
        m_data = t_data;
        m_size = (first - m_data ) + (iterator(m_data + m_size)- (last));
        return m_data + (first - iterator(m_data));
    }

    template<class T,class Alloc >
    void vector<T, Alloc>::swap (vector& x)
    {
        if(this != &x)
        {
            pointer t_data = m_data;
            m_data = x.m_data;
            x.m_data = t_data;
            size_t t_size = m_size;
            m_size = x.m_size;
            x.m_size = t_size;
            t_size = m_capacity;
            m_capacity = x.m_capacity;
            x.m_capacity = t_size;
        }
    }

    template<class T,class Alloc >
    void vector<T, Alloc>::clear()
    {
        for(int i = 0 ; i < m_size ; ++i)
            m_alloc.destroy(m_data + i);
        m_size = 0;
    }
}
#endif