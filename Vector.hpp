#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
#include "is_integral.hpp"

namespace ft
{


    template < class T, class Alloc = std::allocator<T> >
    class vector 
    {
        public:
            typedef typename Alloc::reference reference;
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer pointer;
            typedef T                 value_type;
            typedef typename ft::iterator<value_type> iterator;
            typedef typename ft::iterator<const value_type> const_iterator;
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
            explicit vector(const Alloc& alloc = Alloc()): m_data(NULL) , m_alloc(alloc){}//default
            explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type()) : m_alloc(alloc) ,m_size(n),m_capacity(n)    //fill   // n T with value val
            {
                m_data = m_alloc.allocate(n);
                for(int i = 0;  i < n ; i++)
                    m_alloc.construct(m_data + i , val);
            }
           template <class Inputiterator>
            vector(Inputiterator first, Inputiterator last,const Alloc& alloc = Alloc(), typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type = 0) : m_alloc(alloc) //range
            {
                m_size = last - first;

                m_data  = m_alloc.allocate(m_size);
                for (;first != last; ++first)
                {
                    m_alloc.construct(m_data + ((last - (first + 1))), *first);
                }
            }
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
                for(int i = 0 ; i < size ; i++)
                    m_alloc.destroy(m_data+i);
                alloc.deallocate(m_data,size);
            }
            // template <class Inputiterator>
            // void assign(Inputiterator first, Inputiterator last);
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