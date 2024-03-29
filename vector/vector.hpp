#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "./iterator/is_integral.hpp"
#include "./iterator/iterator.hpp"
#include "./iterator/reverse_iterator.hpp"
#include <cstddef>
#include <memory>
#include <string>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector 
    {
        public:
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer pointer;
            typedef typename Alloc::const_pointer const_pointer;
            typedef T                 value_type;
            typedef size_t            size_type;
            typedef ptrdiff_t         difference_type;
            typedef Alloc               allocator_type;
            typedef T&                  reference;
            typedef typename ft::iterator<value_type> iterator;
            typedef typename ft::iterator<const value_type> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        private:
            pointer m_data;
            size_t m_size;
            size_t m_capacity;
            allocator_type m_alloc;

        public :
        
            //******** constructor ******** //
            explicit vector(const Alloc& alloc = Alloc());//default
            vector(const vector<T,Alloc>& other);//copy
            vector<T,Alloc>& operator=(const vector<T,Alloc>& other); //=
            ~vector();
            explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type()); //fill   // n T with value val
            template <class Inputiterator>
            vector(Inputiterator first, Inputiterator last,const Alloc& alloc = Alloc(), typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type* = 0);//range
            void assign(size_type n, const value_type& val);
            template <class Inputiterator>
            void assign(Inputiterator first, Inputiterator last ,typename ft::enable_if<!ft::is_integral<Inputiterator>::value, Inputiterator>::type* = 0);
            allocator_type get_allocator() const;

            //**********  iterators   *******//
            iterator begin(){return m_data;}
            iterator end(){return m_data + m_size;}
            reverse_iterator rbegin() 
            { 
                return reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin()); 
            }
            const_iterator begin() const{return m_data;};
            const_iterator end() const{return m_data + m_size;}
            const_reverse_iterator rend() const{return const_reverse_iterator(begin()); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }


            //********** capacity *********//
            size_type size() const;
            size_type capacity() const;
            size_type max_size() const;
            void resize (size_type n, value_type val = value_type());
            void reserve(size_type n);
            bool empty() const;

            //********** element access ******//
            reference operator[](size_type n);
            const_reference operator[](size_type n) const;
            const_reference at(size_type n) const;
            reference at(size_type n);
            reference front();//#####
            const_reference front() const;
            reference back();
            const_reference back() const;

            //********** modifiers ******//
            void push_back (const value_type& val);
            void pop_back();
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert(iterator position,InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);
            void swap(vector& x);
            void clear();

            void destroy_allocator()
            {
                if(m_data)
                {
                    for(size_t i = 0 ; i < m_size ; ++i)
                        m_alloc.destroy(m_data + i);
                    m_alloc.deallocate(m_data,m_capacity);
                }
                m_data = NULL;
                m_size = 0;
                m_capacity = 0;
            }
    };
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) {
            if (!(*first1 == *first2))  
                return false;
            ++first1; ++first2;
        }
        return true;
    }
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2 == last2 || *first2 < *first1) 
                return false;
            else if (*first1 < *first2) 
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if(lhs.size() != rhs.size())
            return(false);
        else
            return(ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return(!(lhs == rhs));
    }
    template <class T, class Alloc>
    bool operator <  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return(ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
    }
    template <class T, class Alloc>
    bool operator >  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        	return (!(rhs < lhs));
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        if(&y != &x)
        {
            vector<T,Alloc> tmp;
            tmp.swap(x);
            x.swap(y);
            y.swap(tmp);
            tmp.clear();
        } 
    }

}

#include "constructor.tpp"
#include "capacity.tpp"
#include "modifiers.tpp"
#include "element_access.tpp"

#endif