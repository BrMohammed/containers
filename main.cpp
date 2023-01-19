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

#include "Vector.hpp"

int main ()
{
  // constructors used in the same order as described above:
   // ft::Vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                    // four ints with value 100
    ft::Vector<int> third (second.begin(),second.end());  // iterating through second
    ft::Vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of second are:";
  for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';


  return 0;
}