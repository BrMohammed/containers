#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"
#include "iterator.hpp"
namespace ft
{
    template <class Iterator>
    class reverse_iterator 
        :  public iterator <typename iterator_traits<Iterator>::iterator_type>

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

        typename Iterator::reference operator*() const { return *m_iter; }
        typename Iterator::pointer operator->() const { return m_iter; }

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

        reference operator [] (difference_type i) const {return *(m_iter - i);}
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

        difference_type operator - (const reverse_iterator& other) const 
        {
            difference_type n = m_iter + other.m_iter;
            return n;
        }

        difference_type operator + (const reverse_iterator& other) const 
        {
            difference_type n = m_iter - other.m_iter;
            return n;
        }
        

       
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
    {return (x.m_iter == y.m_iter);}
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {return (x.m_iter < y.m_iter);}
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {return (x.m_iter != y.m_iter);}
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {return (x.m_iter > y.m_iter);}
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {return (x.m_iter >= y.m_iter);}
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
    {return (x.m_iter <= y.m_iter);}
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
                                                                    const reverse_iterator<Iterator>& y)
    {return y.m_iter + x.m_iter;}
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                            const reverse_iterator<Iterator>& x)
    {return n.m_iter - x.m_iter;}
}
#endif