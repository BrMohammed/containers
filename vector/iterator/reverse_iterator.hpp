#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include <iterator>
namespace ft
{
    template <class Iterator>
    class reverse_iterator 
    {
        protected:
            Iterator m_iter;
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::reference reference;
            typedef typename iterator_traits<Iterator>::pointer pointer;
        
        reverse_iterator() : m_iter(NULL){}
        explicit reverse_iterator(Iterator other) : m_iter(other){}
        template <class T> 
        reverse_iterator(const reverse_iterator<T>& other) : m_iter(other.base()) {}
        ~reverse_iterator(){}

        Iterator base() const { return m_iter; }

        reference operator*()
        {
            Iterator tmp = m_iter;
            return *(--tmp);
        }
        pointer operator->()
        {
            return &(operator*());
        }
        reverse_iterator& operator--() { ++m_iter; return *this; }
        reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++m_iter; return tmp; }
        reverse_iterator& operator++(){m_iter--; return *this;}//a++
        reverse_iterator operator++(int)//++a
        {
            reverse_iterator tmp;
            tmp.m_iter = m_iter;
            m_iter--;
            return tmp;
        }

        reference operator [] (difference_type i) const 
        {
            Iterator tmp = m_iter;
            --tmp;
            return *(tmp - i);
        }
        reverse_iterator& operator+=(difference_type rhs) {m_iter -= rhs; return *this;}
        reverse_iterator& operator-=(difference_type rhs) {m_iter += rhs; return *this;}
        reverse_iterator operator + (difference_type const & rhs) const
        {
            reverse_iterator it = *this;
            it.m_iter -= rhs;
            return it;
        }
        reverse_iterator operator - (difference_type const & rhs) const
        {
            reverse_iterator it = *this;
            it.m_iter += rhs;
            return it;
        }

        difference_type operator - ( reverse_iterator const & other) const 
        {
            return other.m_iter - m_iter;
        }
                   
       operator reverse_iterator<const iterator_type>() {return reverse_iterator<const iterator_type>(m_iter);}//?
       template <class B>
        friend reverse_iterator operator + (difference_type x, const reverse_iterator<B>& other) //?
        {
            return reverse_iterator(other.base() - x);
        }
        template <class B>
        friend reverse_iterator operator - (difference_type x, const reverse_iterator<B>& other) //?
        {
            return reverse_iterator(other.base() + x);
        }
                    bool    operator==(reverse_iterator const & it)
            {
                return  m_iter == it.base();
            }

            bool    operator!=(reverse_iterator const & it)
            {
                return  m_iter != it.base();
            }

            // template<class T1, class T2>
            // friend bool    operator<(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            // {
            //     return  it1.base() > it2.base();
            // }

            // template<class T1, class T2>
            // friend bool    operator>(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            // {
            //     return  it1.base() < it2.base();
            // }

            // template<class T1, class T2>
            // friend bool    operator>=(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            // {
            //     return  it1.base() <= it2.base();
            // }

            // template<class T1, class T2>
            // friend bool    operator<=(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            // {
            //     return  it1.base() >= it2.base();
            // }
    };
    // template <class it1, class it2>
    // bool operator==( reverse_iterator<it1> const & x,  reverse_iterator<it2> const & y)
    //     {return (x.base() == y.base());}
    // template <class it1, class it2>
    // bool operator < ( reverse_iterator< const it1> const & x,reverse_iterator<const it2> const & y)
    //     {return (x.base() > y.base());}
    // template <class it1, class it2>
    // bool operator !=(const reverse_iterator<it1>& x,const reverse_iterator<it2>& y)
    //     {return (x.base() != y.base());}
    // template <class it1, class it2>
    // bool operator > (const reverse_iterator<it1>& x,const reverse_iterator<it2>& y)
    //     {return (x.base() < y.base());}
    // template <class it1, class it2>
    // bool operator >=(const reverse_iterator<it1>& x,const reverse_iterator<it2>& y)
    //     {return (x.base() <= y.base());}
    // template <class it1, class it2>
    // bool operator<=(const reverse_iterator<it1>& x,const reverse_iterator<it2>& y)
    //     {return (x.base() >= y.base());}

                template<class T1, class T2>
             bool    operator<(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() > it2.base();
            }

            template<class T1, class T2>
             bool    operator>(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() < it2.base();
            }

            template<class T1, class T2>
             bool    operator>=(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() <= it2.base();
            }

            template<class T1, class T2>
             bool    operator<=(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() >= it2.base();
            }
}
#endif