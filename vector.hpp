#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "is_integral.hpp"
#include "iterator.hpp"
#include <cstring>

namespace ft
{


    template < class T, class Alloc = std::allocator<T> >
    class vector 
    {
        public:
            typedef typename Alloc::reference reference;
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer pointer;
            typedef typename Alloc::const_pointer const_pointer;
            typedef T                 value_type;
            typedef size_t            size_type;
            typedef ptrdiff_t         difference_type;
            typedef Alloc         allocator_type;
            typedef typename ft::iterator<value_type> iterator;
            // typedef typename ft::iterator<const value_type> const_iterator;
            // typedef std::reverse_iterator<iterator> reverse_iterator;
            // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        private:
            pointer m_data;
            size_t m_size;
            size_t m_capacity;
            allocator_type m_alloc;

        public :
            explicit vector(const Alloc& alloc = Alloc()): m_data(NULL) , m_alloc(alloc), m_size(0), m_capacity(0){}//default
            vector(const vector<T,Alloc>& other)//copy
            {
                *this = other;
            }
            vector<T,Alloc>& operator=(const vector<T,Alloc>& other) //=
            {
                if (this != &other)
                    vector(other.m_data,other.m_data + other.m_size);
                return *this;
            }
            ~vector()
            {
                for(int i = 0 ; i < m_size ; i++)
                    m_alloc.destroy(m_data+i);
                m_alloc.deallocate(m_data,m_size);
            }
            explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type()) : m_alloc(alloc) ,m_size(n),m_capacity(n)    //fill   // n T with value val
            {
                m_data = m_alloc.allocate(n);
                for(int i = 0;  i < n ; i++)
                    m_alloc.construct(m_data + i , val);
            }
            template <class Inputiterator>
            vector(Inputiterator first, Inputiterator last,const Alloc& alloc = Alloc(), typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type* = 0) : m_alloc(alloc) //range
            {
                m_size = last - first;
                m_data  = m_alloc.allocate(m_size);
                for (int  i = 0;first != last; ++first)
                {
                    m_alloc.construct(m_data + (i++), *first);
                }
            }
            void assign(size_type n, const value_type& val)
            {
                destroy_allocator();
                m_size = n;
                m_capacity = n;
                m_data = m_alloc.allocate(n);
                for(int i = 0;  i < n ; i++)
                    m_alloc.construct(m_data + i , val);
            }
            template <class Inputiterator>
            void assign(Inputiterator first, Inputiterator last ,typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type* = 0)
            {
                destroy_allocator();
                m_size = last - first;
                m_capacity = m_size;
                m_data  = m_alloc.allocate(m_size);
                for (int i = 0;first != last; ++first)
                    m_alloc.construct((m_data + (i++)), *first);
            }
            allocator_type get_allocator() const{return m_alloc;}

            iterator begin()
            {
                return m_data;
            }
            iterator end()
            {
                return m_data + m_size;
            }
            //reverse_iterator rbegin();
            //reverse_iterator rend();
            //const_iterator begin() const;
            //const_iterator end() const;
            // rbegin() const;
            // rend() const;
            //const_reverse_iterator rend() const;
            //const_reverse_iterator rbegin() const;



            size_type size() const{ return m_size; }
            size_type capacity() const{ return m_capacity; }
            size_type max_size() const{return ((2^64)/sizeof(value_type) - 1);}
            void resize (size_type n, value_type val = value_type())
            {
                if(n < m_size)
                {
                    for(int i = n ; i < m_size ; i++)
                        m_alloc.destroy(m_data + i);
                }
                else if(n != m_size)
                {
                    allocator_type t_alloc;
                    pointer t_data;
                    t_data = t_alloc.allocate(n);
                    iterator end = iterator(m_data + m_size);
                    iterator begin = iterator(m_data);

                    for (int i = 0;begin != end; ++begin)
                        t_alloc.construct((t_data + (i++)), *begin);
                    for(int i = m_size ; i < n ; i++)
                    {
                        if(val != 0)
                            t_alloc.construct(t_data + i, val);
                        else
                            t_alloc.construct(t_data + i, 0);
                    }
                    destroy_allocator();
                    m_data = m_alloc.allocate(n);
                    end = NULL; 
                    begin = NULL;
                    end = iterator(t_data + n);
                    begin = iterator(t_data);
                    for (int i = 0;begin != end; ++begin)
                        m_alloc.construct((m_data + (i++)), *begin);
                    for(int i = 0 ; i < n ; ++i)
                        t_alloc.destroy(t_data + i);
                    t_alloc.deallocate(t_data,n);
                    t_data = NULL;
                }
                m_size = n;
                m_capacity = n;
            }
            void reserve(size_type n)
            {   
                if(m_capacity < n)
                {
                    allocator_type t_alloc;
                    pointer t_data;
                    t_data = t_alloc.allocate(m_size);
                    iterator end = iterator(m_data + m_size);
                    iterator begin = iterator(m_data);
                    for (int i = 0;begin != end; ++begin)
                        t_alloc.construct((t_data + (i++)), *begin);
                    size_type tmp = m_size;
                    destroy_allocator();
                    m_capacity = n;
                    m_size = tmp;
                    m_data = m_alloc.allocate(n);
                    end = NULL; 
                    begin = NULL;
                    end = iterator(t_data + m_size);
                    begin = iterator(t_data);
                    for (int i = 0;begin != end; ++begin)
                        m_alloc.construct((m_data + (i++)), *begin);
                    for(int i = 0 ; i < m_size ; ++i)
                        t_alloc.destroy(t_data + i);
                    t_alloc.deallocate(t_data,m_size);
                    t_data = NULL;
                }
                
            }
            bool empty() const
            {
                if(m_size = 0)
                    return true;
                return false;
            }

            void push_back(const T& x)
            {
                if(m_size == m_capacity)
                {
                   
                    pointer t_data = m_alloc.allocate(m_size * 2);
                    memcpy(t_data,m_data,m_size * sizeof(value_type));
                    m_alloc.construct(t_data + m_size,x);
                    m_alloc.deallocate(m_data, m_capacity);
                    m_capacity = m_size * 2;
                    m_data = t_data;
                }
                else
                    m_alloc.construct(m_data + m_size,x);
                m_size++;
           
            }
            void pop_back()
            {
                m_alloc.destroy(m_data + m_size);
                m_size--;
            }
            iterator insert (iterator position, const value_type& val)
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
            void insert (iterator position, size_type n, const value_type& val)
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
            template <class InputIterator>
            void insert(iterator position,InputIterator first, InputIterator last)
            {
                size_type distence = last - (first );
                pointer t_data = m_alloc.allocate(m_size + distence);
                int index = position - iterator(m_data) ;
                memcpy(t_data, m_data , (index )* sizeof(value_type));
                memcpy(t_data + index, &(*first) , distence *  sizeof(value_type));
                int index2 = m_size - index  ;
                memcpy(t_data + (index + distence) , m_data + (index), index2 * sizeof(value_type));
                m_alloc.deallocate(m_data, m_capacity);
                m_data = t_data;
                m_size += distence;
                if (m_size > m_capacity)
                    m_capacity = m_size;
            }

            iterator erase(iterator position)
            {
                pointer t_data = m_alloc.allocate(capacity);
                int index = position - iterator(m_data) ;
                memcpy(t_data, m_data , (index)* sizeof(value_type));
                memcpy(t_data + index, m_data + index + 1, (m_size - (index + 1)) * sizeof(value_type));
                m_alloc.deallocate(m_data, m_capacity);
                m_data = t_data;
                m_size--;
                return m_data + index;
            }

            iterator erase(iterator first, iterator last)
            {
                size_type distence = last - (first );
                pointer t_data = m_alloc.allocate(capacity);
                int index = first - iterator(m_data) ;
                memcpy(t_data, m_data , (index)* sizeof(value_type));
                int index2 = last - iterator(m_data) ;
                memcpy(t_data + index , m_data + (index2), (m_size - (index2)) * sizeof(value_type));
                m_alloc.deallocate(m_data, m_capacity);
                m_data = t_data;
                m_size = (first - m_data ) + (iterator(m_data + m_size)- (last));
                return m_data + (first - iterator(m_data));
            }
            // void swap(vector<T,Allocator>&);
            // void clear();

            void destroy_allocator()
            {
                for(int i = 0 ; i < m_size ; ++i)
                    m_alloc.destroy(m_data + i);
                m_alloc.deallocate(m_data,m_size);
                m_data = NULL;
                m_size = 0;
                m_capacity = 0;
            }
    };

}



#endif