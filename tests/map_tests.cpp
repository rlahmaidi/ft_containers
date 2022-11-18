#include <iostream>
#include <map>
#include <signal.h>
#include "../MAP/map.hpp"
#include <vector>
//#include "../MAP/map.hpp"

int main ()
{
  
    {
      // ft::map<char,int> mymap;

      // // first insert function version (single parameter):
      
      //  mymap.insert ( ft::pair<char,int>('a',100) );
      
      // mymap.insert ( ft::pair<char,int>('z',200) );

      // ft::pair<ft::map<char,int>::iterator,bool> ret;
      // ret = mymap.insert ( ft::pair<char,int>('z',500) );
      // if (ret.second==false) 
      // {
      //   std::cout << "element 'z' already existed";
      //   std::cout << " with a value of " << ret.first->second << '\n';
      // }
      // std::cout << "map size is " << mymap.size() << std::endl;
    }
    {
      // std::map<char,int> mymap;

      // // first insert function version (single parameter):
      
      //  mymap.insert ( std::pair<char,int>('a',100) );
      
      // mymap.insert ( std::pair<char,int>('z',200) );

      // std::pair<std::map<char,int>::iterator,bool> ret;
      // ret = mymap.insert ( std::pair<char,int>('z',500) );
      // if (ret.second==false) 
      // {
      //   std::cout << "element 'z' already existed";
      //   std::cout << " with a value of " << ret.first->second << '\n';
      // }
      // std::cout << " std map size is " << mymap.size() << std::endl;
    }
    {
        // second insert function version (with hint position):
      // ft::map<char,int> mymap;
      // ft::map<char,int>::iterator it = mymap.begin();
      // mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
      // mymap.insert (it, ft::pair<char,int>('c',400));  //
      // //ft::map<char, int>::iterator it;
      // for(ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      // {
      //   //std::cout << "ar we here ? " << std::endl;
      //   std::cout << "key is " << it->first <<"  value is " << it->second <<  std::endl;
      // }

    }
    {
        // ft::map<char,int> mymap;

        // // first insert function version (single parameter):
        // mymap.insert ( ft::pair<char,int>('a',100) );
        // mymap.insert ( ft::pair<char,int>('z',200) );

        // ft::pair<ft::map<char,int>::iterator,bool> ret;
        // ret = mymap.insert ( ft::pair<char,int>('z',500) );
        // if (ret.second==false) {
        //   std::cout << "element 'z' already existed";
        //   std::cout << " with a value of " << ret.first->second << '\n';
        // }

        // // second insert function version (with hint position):
        // ft::map<char,int>::iterator it = mymap.begin();
        // mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
        // mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

        // // third insert function version (range insertion):
        // ft::map<char,int> anothermap;
        // anothermap.insert(mymap.begin(),mymap.end());

        // // showing contents:
        // std::cout << "mymap contains:\n";
        // for (it=mymap.begin(); it!=mymap.end(); ++it)
        //   std::cout << it->first << " => " << it->second << '\n';

        // std::cout << "anothermap contains:\n";
        // for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        //   std::cout << it->first << " => " << it->second << '\n';

 
    }
    {
      //   ft::map<char, std::string> mymap;

      // mymap['a']="an element";
      // mymap['b']="another element";
      // mymap['c']=mymap['b'];
      // mymap['e'] = "rachid";
      // mymap['f'] = " lahmaidi";
      // mymap['j'];

      // std::cout << "mymap['a'] is " << mymap['a'] << '\n';
      // std::cout << "mymap['b'] is " << mymap['b'] << '\n';
      // std::cout << "mymap['c'] is " << mymap['c'] << '\n';
      // std::cout << "mymap['d'] is " << mymap['d'] << '\n';
      // std::cout << "mymap['e'] is " << mymap['e'] << '\n';
      // std::cout << "mymap['f'] is " << mymap['f'] << '\n';

      // std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }   
    {
      //   ft::map<char,int> mymap;

      //   // insert some values:
      //   mymap['a']=10;
      //   mymap['b']=20;
      //   mymap['c']=30;
      //   mymap['d']=40;
      //   mymap['e']=50;
      //   mymap['f']=60;
      //   mymap['p'] = 70;
      //   mymap['q']=80;
      //   mymap['r'] = 90;
      //   mymap['z'] = 100;
      //   //ft::map<char,int>::iterator it = mymap.begin();

      //   //it=mymap.find('b');
      //   //mymap.erase (it);                   // erasing by iterator

      //   //mymap.erase ('c');                  // erasing by key
      //   //mymap.erase ('b');                  // erasing by key

      //   ft::map<char,int>::iterator it = mymap.begin()  ;
      //  mymap.erase ( mymap.begin(), mymap.end());    // erasing by range

      //   // show content:
      //   for (it=mymap.begin(); it!=mymap.end(); ++it)
      //     std::cout << it->first << " => " << it->second << '\n';
    }
    {
        // std::map<char,int> mymap;
        // std::map<char,int>::iterator it;

        // // insert some values:
        // mymap['a']=10;
        // mymap['b']=20;
        // mymap['c']=30;
        // mymap['d']=40;
        // mymap['e']=50;
        // mymap['f']=60;

        // it=mymap.find('b');
        // mymap.erase (it);                   // erasing by iterator

        // std::cout << mymap.erase ('c') << std::endl; 

    }
    {
      // ft::map<char,int> foo,bar;

      // foo['x']=100;
      // foo['y']=200;

      // bar['a']=11;
      // bar['b']=22;
      // bar['c']=33;
      // //ft::map<char ,int>::iterator it[2] = {foo.begin(),foo.begin()++};
      // ft::map<char ,int>::iterator it = foo.begin();
      // std::cout << "before swap "<< it->first << std::endl;
      // foo.swap(bar);
      // it++;
      // std::cout << "after  swap "<< it->first << std::endl;

      // std::cout << "foo contains:\n";
      // for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';

      // std::cout << "bar contains:\n";
      // for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';

    }
    {
    //  ft::map<char,int> mymap;

    //   mymap['x']=100;
    //   mymap['y']=200;
    //   mymap['z']=300;

    //   std::cout << "mymap contains:\n";
    //   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    //   mymap.clear();
    //   mymap['a']=1101;
    //   mymap['b']=2202;

    //   std::cout << "mymap contains:\n";
    //   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';;
     }
    {
      ft::map<char,int> mymap;

      ft::map<char,int>::key_compare mycomp = mymap.key_comp();

      mymap['a']=100;
      mymap['b']=200;
      mymap['c']=300;

      std ::cout << "mymap contains:\n";

      char highest = mymap.rbegin()->first;     // key value of last element

      ft::map<char,int>::iterator it = mymap.begin();
      do {
        std::cout << it->first << " => " << it->second << '\n';
      } while ( mycomp((*it++).first, highest) );

      std::cout << '\n';
    }
    
    return 0;
}