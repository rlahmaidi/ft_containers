#include <iostream>
#include <map>
#include <signal.h>
#include "../MAP/map.hpp"
//#include "../MAP/map.hpp"

int main ()
{
  
    {
      ft::map<char,int> mymap;

      // first insert function version (single parameter):
      
       mymap.insert ( ft::pair<char,int>('a',100) );
      
      mymap.insert ( ft::pair<char,int>('z',200) );

      ft::pair<ft::map<char,int>::iterator,bool> ret;
      ret = mymap.insert ( ft::pair<char,int>('z',500) );
      if (ret.second==false) 
      {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
      }
      std::cout << "map size is " << mymap.size() << std::endl;
    }
    {
      std::map<char,int> mymap;

      // first insert function version (single parameter):
      
       mymap.insert ( std::pair<char,int>('a',100) );
      
      mymap.insert ( std::pair<char,int>('z',200) );

      std::pair<std::map<char,int>::iterator,bool> ret;
      ret = mymap.insert ( std::pair<char,int>('z',500) );
      if (ret.second==false) 
      {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
      }
      std::cout << " std map size is " << mymap.size() << std::endl;
    }
    {
        // second insert function version (with hint position):
      ft::map<char,int> mymap;
      ft::map<char,int>::iterator it = mymap.begin();
      mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
      mymap.insert (it, ft::pair<char,int>('c',400));  //
      //ft::map<char, int>::iterator it;
      for(ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      {
        //std::cout << "ar we here ? " << std::endl;
        std::cout << "key is " << it->first <<"  value is " << it->second <<  std::endl;
      }

    }
    {
        ft::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( ft::pair<char,int>('a',100) );
        mymap.insert ( ft::pair<char,int>('z',200) );

        ft::pair<ft::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( ft::pair<char,int>('z',500) );
        if (ret.second==false) {
          std::cout << "element 'z' already existed";
          std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        ft::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.end());

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

 
    }      
    
    return 0;
}