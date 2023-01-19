#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

namespace ft 
{
    template <class T, class Distance = ptrdiff_t,class Pointer = T*, class Reference = T&>
    class Iterator
    {
        
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            // typedef std:::random_access_iterator_tag Category;
        private:
            pointer m_ptr ;
        public:
            Iterator(pointer ptr) : m_ptr(ptr){}
            Iterator(Iterator const &other){*this = other;}
            Iterator() : m_ptr(NULL) {}
            ~Iterator(){}

            Iterator & operator = (Iterator const & rhs)
            {
                if (this != &rhs)
                    this->m_ptr = rhs.m_ptr;
                return *this;
            }
            Iterator& operator++()//++a
            {
                m_ptr++;
                return *this;
            }
            Iterator operator ++ (int)//a++
            {
                Iterator tmp  = *this;
                tmp.m_ptr = *this;
                ++(*this);
                return tmp;
            }
            Iterator operator -- (int)//a--
            {
                Iterator tmp  = *this;
                tmp.m_ptr = *this;
                --(*this);
                return tmp;
            }
            Iterator& operator -- ()//--a
            {
                m_ptr--;
                return *this;
            }
            reference operator*(){return *m_ptr;}
            reference operator [] (int i){return *(m_ptr + index);}
            pointer operator -> (){return m_ptr;}
            Iterator operator + (difference_type const & rhs) const
            {
                Iterator tmp  = *this;
                tmp.m_ptr = ((*this).m_ptr + rhs.m_ptr);
                return tmp;
            }
            Iterator operator - (difference_type const & rhs) const
            {
                Iterator tmp  = *this;
                tmp.m_ptr = ((*this).m_ptr - rhs.m_ptr);
                return tmp;
            }

            Iterator& operator+=(difference_type rhs) {m_ptr += rhs; return *this;}
            Iterator& operator-=(difference_type rhs) {m_ptr -= rhs; return *this;}

            bool operator > (Iterator const & rhs) const{return ((*this).m_ptr > rhs.m_ptr);}
            bool operator < (Iterator const & rhs)  const{return ((*this).m_ptr < rhs.m_ptr);}
            bool operator >= (Iterator const & rhs) const{return ((*this).m_ptr >= rhs.m_ptr);}
            bool operator <= (Iterator const & rhs) const{return ((*this).m_ptr <= rhs.m_ptr);}
            bool operator == (Iterator const & rhs) const{return ((*this).m_ptr == rhs.m_ptr);}
            bool operator != (Iterator const & rhs) const{return !((*this).m_ptr == rhs.m_ptr);}

        

    };

}


#endif