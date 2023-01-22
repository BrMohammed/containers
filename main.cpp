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
  int myints[] = {1776,7,2,4}; 
  ft::vector<int> first;
  first.assign (myints,myints+4); 
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "capacity of first: " << int (first.capacity()) << '\n';
  first.insert(first.begin()  , first.begin() ,first.end());
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "capacity of first: " << int (first.capacity()) << '\n';
  for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it << std::endl;
  return 0;
}