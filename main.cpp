#include <vector>
#include <iostream>

// int main()
// {
//     std::allocator<int> alloc;
//     int *p = alloc.allocate(5);
//     for(int i = 0; i < 5; i++)
//         alloc.construct(p + i,i);
//     for(int i = 0 ; i < 5 ; i++)
//         alloc.destroy(p+i);
//     alloc.deallocate(p,5);
    
//     std::cout << *p+1  << std::endl;
// }

// int main ()
// {
//   // constructors used in the same order as described above:
//   std::vector<int> first;                                // empty vector of ints
//   std::vector<int> second (4,100);                       // four ints with value 100
//   std::vector<int> third (second.begin(),second.end());  // iterating through second
//   std::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fourth are:";
//   for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';


//   return 0;
// }

#include "vector.hpp"

int main ()
{
  ft::vector<int> first(4,100);
    std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "capacity of first: " << int (first.capacity()) << '\n';
  first.reserve(5);
  first.reserve(5);
  // std::vector<int> second;
  // std::vector<int> third;
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "capacity of first: " << int (first.capacity()) << '\n';
  // first.reserve(10);
  //  std::cout << "Size of first: " << int (first.size()) << '\n';
  // std::cout << "capacity of first: " << int (first.capacity()) << '\n';
  for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it << std::endl;
  // first.assign (10,100);             // 7 ints with a value of 100

  //  second.assign (first.begin(),first.end()-1); // the 5 central values of first

  // int myints[] = {1776,7,4};
  // third.assign (myints,myints+3);   // assigning from array.

  // std::cout << "Size of first: " << int (first.capacity()) << '\n';
  // std::cout << "Size of second: " << int (second.capacity()) << '\n';
  // std::cout << "Size of third: "<< int (third.capacity()) << std::endl;
  return 0;
}