#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

namespace ft 
{
    template <class Category, class T, class Distance = ptrdiff_t,class Pointer = T*, class Reference = T&>
    class Iterator
    {
        private:
            
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  std:::random_access_iterator_tag;
        public:
            Iterator(pointer ptr) : m_ptr(ptr){}
            Iterator(Fixed const &other){*this = other;}
            Iterator(): m_ptr(null) {}
            ~Iterator(){}

            Iterator & operator = (Iterator const & rhs)
            {
                if (this != &rhs)
                    this->m_ptr = rhs.m_ptr();
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
            Reference operator*(){return *m_ptr}
            Reference operator [] (int i){return *(m_ptr + index)}
            Pointer operator -> (){return m_ptr}
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

        private:
            pointer m_ptr ;

    };

}


#endif