#ifndef MODIFIERS_TPP
#define MODIFIERS_TPP
#include "vector.hpp"

namespace ft
{
    template <class T, class Alloc>
    void vector<T, Alloc>::push_back(const value_type &val)
    {
        if (m_size == m_capacity)
        {
            pointer t_data;
            if (m_capacity == 0)
            {
                t_data = m_alloc.allocate(1);
                m_capacity = 1;
            }
            else
            {
                t_data = m_alloc.allocate(m_size * 2);
                for (size_t i = 0; i < m_size; i++)
                {
                    m_alloc.construct(t_data + i, *(m_data + i));
                    m_alloc.destroy(m_data + i);
                }
                m_capacity = m_size * 2;
            }
            if (m_data)
                m_alloc.deallocate(m_data, m_size);
            m_data = t_data;
        }
        m_alloc.construct(m_data + m_size, val);
        m_size++;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::pop_back()
    {
        erase(iterator(m_data + (m_size - 1)));
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(typename vector<T, Alloc>::iterator position, const value_type &val)
    {
        size_t index = position - iterator(m_data);
        if (m_capacity == m_size)
        {
            if (m_capacity == 0)
                m_capacity = 1;
            else
                m_capacity = m_size * 2;
            pointer t_data = m_alloc.allocate(m_capacity);
            for (size_t i = 0; i < m_size; i++)
            {
                m_alloc.construct(t_data + i, *(m_data + i));
                m_alloc.destroy(m_data + i);
            }
            if (m_data)
                m_alloc.deallocate(m_data, m_size);
            m_data = t_data;
        }
        m_alloc.construct(m_data + (m_size), val);
        value_type tmp = m_data[index];
        for (size_t i = index + 1; i <= m_size; i++)
        {
            value_type tmp2 = m_data[i];
            m_data[i] = tmp;
            tmp = tmp2;
        }
        m_data[index] = val;
        m_size++;
        return m_data + index;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
    {
        if(n > m_alloc.max_size())
            throw std::length_error("Length exception");
        if (n != 0 )
        {
            size_t t_capacity = m_capacity;
            if (m_capacity <= m_size + n && n != 0)
                t_capacity = (m_size + n) * 2;
            else if (m_capacity == 0)
                t_capacity =  n;
            else
                t_capacity = m_capacity;
            pointer t_data = m_alloc.allocate(t_capacity);
            size_t index = position - iterator(m_data);
            for(size_t i = 0; i < index; i++)
                m_alloc.construct(t_data + i, *(m_data + i));
            for(size_t i = 0; i < n; i++)///////////////
                m_alloc.construct(t_data + (i + index), val);
            for(size_t i = 0; i + index < m_size; i++)
                m_alloc.construct(t_data + (i + n  + index), *(m_data + i + index));
            if(m_data)
            {
                for(size_t i = 0 ; i < m_size ; ++i)
                    m_alloc.destroy(m_data + i);
                m_alloc.deallocate(m_data,m_capacity);
            }
            m_data = t_data;
            m_size += n;
            m_capacity = t_capacity;
        }
    }

    template <class T, class Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type *)
    {
        size_t index = position - iterator(m_data);
        for(;first != last;first++)
        {
            iterator tmp = m_data + index;
            insert(tmp,*first);
            index++;
        }
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
    {
        size_t index = position - iterator(m_data);
        if (m_size != 0)
        {
            for (size_t i = index; i < m_size ; i++)
                m_data[i] = m_data[i + 1];
            m_alloc.destroy(m_data + (m_size - 1));
        }
        m_size--;
        return m_data + index;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
    {
        size_t index = first - iterator(m_data);
        size_t end = last - first;

        if (m_size != 0)
        {
            for (size_t i = index; i < m_size; i++)
                m_data[i] = m_data[i + (end)];
            for (size_t i = m_size - end; i < m_size; i++)
                m_alloc.destroy(m_data + i);
            m_size -= end;
        }
        return m_data + index;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::swap(vector &x) //?
    {
        if (this != &x)
        {
            // pointer t_data = m_data;
            // m_data = x.m_data;
            // x.m_data = t_data;
            // size_t t_size = m_size;
            // m_size = x.m_size;
            // x.m_size = t_size;
            // t_size = m_capacity;
            // m_capacity = x.m_capacity;
            // x.m_capacity = t_size;
            // Alloc t_alloc = m_alloc;
            // m_alloc = x.m_alloc;
            // x.m_alloc = t_alloc;
            ft::swap(*this,x);
        }
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::clear()
    {
        for (size_t i = 0; i < m_size; ++i)
            m_alloc.destroy(m_data + i);
        m_size = 0;
    }
}
#endif