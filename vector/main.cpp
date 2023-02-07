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

int main () {
  ft::vector<int> myvector;
         ft::vector<std::string> str("");
        ft::vector<std::string>::iterator it(str);
  for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

  // typedef ft::vector<int>::iterator iter_type;

  // // std::reverse_iterator<iter_type> rev_iterator(myvector.rbegin());

  // std::reverse(myvector.rbegin(), myvector.rend());
  //     // if (myvector.rbegin() !=  myvector.rend())
  //     // {
  //     //   for (; myvector.rbegin() < --myvector.rend(); ++myvector.rbegin())
  //     //   {
  //     //       std::cout << "hi" << std::endl;
  //     //       std::swap(* myvector.rbegin() , *myvector.rend());
  //     //   }
            
  //     // }
        

  // for ( ft::reverse_iterator<iter_type> rit = myvector.rbegin() ; rit != myvector.rend();rit++)
  //   std::cout << *rit << std::endl;
   

  return 0;
}