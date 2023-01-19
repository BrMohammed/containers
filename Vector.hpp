#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "Iterator.hpp"

namespace ft
{

    template < class T, class Alloc = std::allocator<T> >
    class Vector 
    {
        public:
            typedef typename Alloc::reference reference;
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer pointer;
            typedef T                 value_type;
            typedef typename ft::Iterator<value_type> iterator;
            typedef typename ft::Iterator<const value_type> const_iterator;
            typedef size_t            size_type;
            typedef ptrdiff_t         difference_type;
            typedef Alloc         allocator_type;
            typedef typename Alloc::const_pointer const_pointer;
            // typedef std::reverse_iterator<iterator> reverse_iterator;
            // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        private:
            pointer m_data;
            size_t m_size;
            size_t m_capacity;
            allocator_type m_alloc;

        public :
            explicit Vector(const Alloc& alloc = Alloc()): m_data(NULL) , m_alloc(alloc){}//default

            // explicit Vector (size_type n, const value_type& val = value_type(),
            //                     const allocator_type& alloc = allocator_type()) : m_alloc(alloc) ,m_size(n),m_capacity(n)    //fill   // n T with value val
            // {
            //     m_data = m_alloc.allocate(n);
            //     for(int i = 0;  i < n ; i++)
            //         m_alloc.construct(m_data + i , val);
            // }
            template <class InputIterator>
            Vector(InputIterator first, InputIterator last,const Alloc& alloc = Alloc()) : m_alloc(alloc) //range
            {
                m_size = last - first;
                m_data  = m_alloc.allocate(m_size);
                for (;first != last; ++first)
                {
                    m_alloc.construct(m_data + ((last - (first + 1))), *first);
                }
            }
            Vector(const Vector<T,Alloc>& other)//copy
            {
                *this = other;
            }
            Vector<T,Alloc>& operator=(const Vector<T,Alloc>& other) //=
            {
                if (this != &other)
                    Vector(other.m_data,other.m_data + other.m_size);
                return *this;
            }
            // ~Vector(){}
            // template <class InputIterator>
            // void assign(InputIterator first, InputIterator last);
            // void assign(size_type n, const T& u);
            // allocator_type get_allocator() const;


            iterator begin()
            {
                return m_data;
            }
            //const_iterator begin() const;
            iterator end()
            {
                return m_data + m_size;
            }
            //const_iterator end() const;
            //reverse_iterator rbegin();
            // rbegin() const;
            //reverse_iterator rend();
            //const_reverse_iterator rend() const;



            // size_type size() const;
            // size_type max_size() const;
            // void resize(size_type sz, T c = T());
            // size_type capacity() const;
            // bool empty() const;
            // void reserve(size_type n);

    };

}



#endif