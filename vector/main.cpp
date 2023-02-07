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
  ft::vector<int> myvector(10, 10);

  ft::vector<int>::reverse_iterator it = myvector.rend();
  std::cout << *it << std::endl;
  // set some values (from 1 to 10)
  // for (int i=1; i<=10; i++) myvector.push_back(i);

  // // erase the 6th element
  // myvector.erase (myvector.begin()+5);

  // // erase the first 3 elements:
  // myvector.erase (myvector.begin()+1,myvector.begin()+2);

  // std::cout << "myvector contains:";
  // for (unsigned i=0; i<myvector.size(); ++i)
  //   std::cout << ' ' << myvector[i];
  // std::cout << '\n';

  // return 0;
}