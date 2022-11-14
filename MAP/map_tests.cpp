#include <iostream>
#include <map>
#include "map.hpp"

int main ()
{
    {
        std::map<char,int> mymap;

          mymap['a']=10;
          mymap['b']=20;
          mymap['c']=30;

        //   while (!mymap.empty())
        //   {
        //     std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        //     mymap.erase(mymap.begin());
        //   }
        std::cout << mymap.begin()->second << std::endl;
        std::cout << (--mymap.end())->second << std::endl;
        // if(mymap.empty() == true)
        //     std::cout << "empty is working" << std::endl;
        // else
        //     std::cout << "empty is not working" << std::endl;
        //  std::cout << mymap.max_size() << std::endl;
    }
    {
    //       std::map<int,int> mymap;
    //       std::cout << mymap.max_size() << std::endl;

    }
    return 0;
}