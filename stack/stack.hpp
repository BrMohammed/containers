#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "/Users/brmohamm/Desktop/containers/vector/vector.hpp"
#include <cstddef>
#include <memory>
#include <string>

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack {
        public:
            typedef Container container_type;
            typedef typename Container::value_type value_type;
            typedef typename Container::size_type size_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            
        protected:
            container_type c;
        public:
            explicit stack(const Container& _c = Container()) : c(_c){}
            ~stack(){}
            bool empty() const { return c.empty(); }
            size_type size() const { return c.size(); }
            value_type& top() { return c.back(); }
            const value_type& top() const { return c.back(); }
            void push(const value_type& x) { c.push_back(x); }
            void pop() { c.pop_back(); }
        };
        
    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs.size() == rhs.size();
    }
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return(!(lhs.size() == rhs.size()));
    }
    template <class T, class Container>
    bool operator <  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return(lhs.size() < rhs.size());
    }
    template <class T, class Container>
    bool operator >  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return(lhs.size() > rhs.size());
    }
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        	return (lhs.size() <= rhs.size());
    }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return ((lhs.size() >= rhs.size()));
    }
}
#endif