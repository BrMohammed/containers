#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"

namespace ft 
{
    template <class T>
    class iterator
    {
        
        public:
            typedef typename iterator_traits<T*>::value_type iterator_type;
            typedef typename iterator_traits<T*>::pointer pointer;
            typedef typename iterator_traits<T*>::reference reference;
            typedef typename iterator_traits<T*>::difference_type difference_type;
            typedef typename iterator_traits<T*>::category iterator_category;
        private:
            pointer m_ptr ;
        public:
            iterator(pointer ptr) : m_ptr(ptr){}
            iterator(iterator const &other){*this = other;}
            iterator() : m_ptr(NULL) {}
            ~iterator(){}

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
               iterator it;
                it.m_ptr += rhs;
                return it;
            }
            iterator operator - (difference_type const & rhs) const
            {
                iterator it;
                it.m_ptr -= rhs;
                return it;
            }

            difference_type operator - (const iterator& other) const 
            {
                difference_type n = m_ptr - other.m_ptr;
                return n;
            }

            difference_type operator + (const iterator& other) const 
            {
                difference_type n = m_ptr + other.m_ptr;
                return n;
            }
            bool operator > (iterator const & rhs) const{return ((*this).m_ptr > rhs.m_ptr);}
            bool operator < (iterator const & rhs)  const{return ((*this).m_ptr < rhs.m_ptr);}
            bool operator >= (iterator const & rhs) const{return ((*this).m_ptr >= rhs.m_ptr);}
            bool operator <= (iterator const & rhs) const{return ((*this).m_ptr <= rhs.m_ptr);}
            bool operator == (iterator const & rhs) const{return ((*this).m_ptr == rhs.m_ptr);}
            bool operator != (iterator const & rhs) const{return ((*this).m_ptr != rhs.m_ptr);}

    };


}


#endif