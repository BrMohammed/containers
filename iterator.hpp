#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

namespace ft 
{
    template <class T>
    class iterator
    {
        
        public:
            typedef T         value_type;
            typedef std::ptrdiff_t  difference_type;
            typedef T*   pointer;
            typedef   T& reference;
            typedef typename std::random_access_iterator_tag category;
            
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
                iterator tmp  = *this;
                tmp.m_ptr = this->m_ptr;
                ++(*this);
                return tmp;
            }
            iterator operator -- (int)//a--
            {
                iterator tmp  = *this;
                tmp.m_ptr = this->m_ptr;
                --(*this);
                return tmp;
            }
            iterator& operator -- ()//--a
            {
                m_ptr--;
                return *this;
            }
            reference operator*() const {return *m_ptr;}
            reference operator [] (int i){return *(m_ptr + i);}
            pointer operator -> (){return m_ptr;}
            iterator& operator+=(difference_type rhs) {m_ptr += rhs; return *this;}
            iterator& operator-=(difference_type rhs) {m_ptr -= rhs; return *this;}
            iterator operator + (difference_type const & rhs) const { return iterator(m_ptr + rhs); }
          
            iterator operator - (difference_type const & rhs) const { return iterator(m_ptr - rhs); }

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
            bool operator != (iterator const & rhs) const{return !((*this).m_ptr == rhs.m_ptr);}

    };


}


#endif