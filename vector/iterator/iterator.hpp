#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"
#include <vector>

namespace ft 
{
    template <class _Tp>
    class iterator
    {
        
        public:
            typedef typename std::remove_cv<_Tp>::type value_type;
            typedef std::ptrdiff_t difference_type;
            typedef _Tp* pointer;
            typedef _Tp& reference;
            typedef typename std::random_access_iterator_tag iterator_category;
        private:
            pointer m_ptr ;
        public:
            iterator(pointer ptr) : m_ptr(ptr){}
            iterator(iterator const &other){*this = other;}
            iterator() : m_ptr(NULL) {}
            ~iterator(){}

            iterator geter() const { return m_ptr; }
            
            iterator & operator = (iterator const & rhs)
            {
                if (this != &rhs)
                    this->m_ptr = rhs.m_ptr;
                return *this;
            }
            iterator& operator++()//++a
            {
                m_ptr++;
                return *this;
            }
            iterator operator ++ (int)//a++
            {
                iterator tmp;
                tmp.m_ptr = this->m_ptr;
                m_ptr++;
                return tmp;
            }
            iterator operator -- (int)//a--
            {
                iterator tmp;
                tmp.m_ptr = this->m_ptr;
                m_ptr--;
                return tmp;
            }
            iterator& operator -- ()//--a
            {
                m_ptr--;
                return *this;
            }
            reference operator*() const {return *m_ptr;}
            reference operator [] (difference_type i){return *(m_ptr + i);}
            pointer operator -> (){return m_ptr;}
            iterator& operator+=(difference_type rhs) {m_ptr += rhs; return *this;}
            iterator& operator-=(difference_type rhs) {m_ptr -= rhs; return *this;}
            iterator operator + (difference_type const & rhs) const
            {
                return m_ptr + rhs;
            }
            iterator operator - (difference_type const & rhs) const
            {
                return (m_ptr - rhs);
            }

            difference_type operator - (const iterator& other) const 
            {
                difference_type n = m_ptr - other.m_ptr;
                return n;
            }

            difference_type operator + (const iterator& other) const 
            {
                return m_ptr + other.m_ptr;
            }

            template <class B>
            friend iterator operator + (difference_type x, const iterator<B>& other) //?
            {
                return other.m_ptr + x;
            }

            template <class B>
            friend iterator operator - (difference_type x, const iterator<B>& other) //?
            {
                return other.m_ptr - x;
            }
            bool operator > (iterator const & rhs) const{return ((*this).m_ptr > rhs.m_ptr);}
            bool operator < (iterator const & rhs)  const{return ((*this).m_ptr < rhs.m_ptr);}
            bool operator >= (iterator const & rhs) const{return ((*this).m_ptr >= rhs.m_ptr);}
            bool operator <= (iterator const & rhs) const{return ((*this).m_ptr <= rhs.m_ptr);}
            bool operator == (iterator const & rhs) const{return ((*this).m_ptr == rhs.m_ptr);}
            bool operator != (iterator const & rhs) const{return ((*this).m_ptr != rhs.m_ptr);}
            operator iterator<const value_type>() {return iterator<const value_type>(m_ptr);}//?
    };
    template <class B>
    iterator<B> operator + (typename iterator<B>::difference_type x, const iterator<B>& other) //?
        {return other.geter() + x;}
    template <class B>
    iterator<B> operator - (typename iterator<B>::difference_type x, const iterator<B>& other) //?
        {return other.geter() - x;}
    template <class it1, class it2>
    bool operator < (iterator<it1> const & x, iterator<it2> const & y)
        {return (*x < *y);}   
    template <class it1, class it2>
    bool operator <=(iterator<it1> const & x, iterator<it2> const & y)
        {return (*x <=*y);}    
    template <class it1, class it2>
    bool operator > (iterator<it1> const & x, iterator<it2> const & y)
        {return (*x > *y);}   
    template <class it1, class it2>
    bool operator >=(iterator<it1> const & x, iterator<it2> const & y)
        {return (*x >= *y);}
    template <class it1, class it2>
    bool operator == (iterator<it1> const & x, iterator<it2> const & y)
        {return (*x == *y);}
    template <class it1, class it2>
    bool operator !=(iterator<it1> const & x, iterator<it2> const & y)
        {return (*x != *y);}
}


#endif