#include <iostream>
#include <map>
#include <signal.h>
#include "../MAP/map.hpp"
#include <vector>
#include "../utils/equal_lexecographi.hpp"
#include "../vector.hpp"
//#include "../MAP/map.hpp"

          bool fncomp (char lhs, char rhs) {return lhs<rhs;}

          struct classcomp {
            bool operator() (const char& lhs, const char& rhs) const
            {return lhs<rhs;}
          };
          bool mypredicate (int i, int j) {
  return (i==j);
}

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

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
    {// erase methods
      ft::map<char,int> mymap;
      ft::map<char,int>::iterator it, it_end;

      // insert some values:
      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;
      mymap['d']=40;
      mymap['e']=50;
      mymap['f']=60;

      it=mymap.find('b');
      //mymap.erase (it);                   // erasing by iterator

      //mymap.erase ('c');                  // erasing by key

      it_end = mymap.find ('e');
      mymap.erase ( it, it_end );    // erasing by range

      // show content:
      for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
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
    {// key_comp
      // ft::map<char,int> mymap;

      // ft::map<char,int>::key_compare mycomp = mymap.key_comp();

      // mymap['a']=100;
      // mymap['b']=200;
      // mymap['c']=300;

      // std ::cout << "mymap contains:\n";

      // char highest = mymap.rbegin()->first;     // key value of last element

      // ft::map<char,int>::iterator it = mymap.begin();
      // do {
      //   std::cout << it->first << " => " << it->second << '\n';
      // } while ( mycomp((*it++).first, highest) );

      // std::cout << '\n';
    }
    {// VALUE_COMP
      // ft::map<char,int> mymap;

      // mymap['x']=1001;
      // mymap['y']=2002;
      // mymap['z']=3003;

      // std::cout << "mymap contains:\n";

      // ft::pair<char,int> highest = *mymap.rbegin();          // last element

      // ft::map<char,int>::iterator it = mymap.begin();
      // do {
      //   std::cout << it->first << " => " << it->second << '\n';
      // } while ( mymap.value_comp()(*it++, highest) );

      }
      {// find
        // ft::map<char,int> mymap;
        // ft::map<char,int>::iterator it;

        // mymap['a']=50;
        // mymap['b']=100;
        // mymap['c']=150;
        // mymap['d']=200;

        // it = mymap.find('b');
        // if (it != mymap.end())
        //   mymap.erase (it);

        // // print content:
        // std::cout << "elements in mymap:" << '\n';
        // std::cout << "a => " << mymap.find('a')->second << '\n';
        // std::cout << "c => " << mymap.find('c')->second << '\n';
        // std::cout << "d => " << mymap.find('d')->second << '\n';

      }
      {// count   
          // std::map<char,int> mymap;
          // char c;

          // mymap ['a']=101;
          // mymap ['c']=202;
          // mymap ['f']=303;

          // for (c='a'; c<'h'; c++)
          // {
          //   std::cout << c;
          //   if (mymap.count(c)>0)
          //     std::cout << " is an element of mymap.\n";
          //   else 
          //     std::cout << " is not an element of mymap.\n";
          // }
      }
      {
        //  ft::map<char,int> mymap;
        //   ft::map<char,int>::const_iterator itlow,itup;

        //   mymap['a']=20;
        //   mymap['b']=40;
        //   mymap['c']=60;
        //   mymap['d']=80;
        //   mymap['e']=100;

        //   itlow=mymap.lower_bound ('b');  // itlow points to b
        //   itlow=mymap.lower_bound ('c');  // itlow points to b
        //   //itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        //   mymap.erase('e');        // erases [itlow,itup)

        //   // print content:
        //   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';
      }
      {
          // ft::map<char,int> mymap;
          // ft::map<char,int>::iterator itlow,itup;

          // mymap['a']=20;
          // mymap['b']=40;
          // mymap['c']=60;
          // mymap['d']=80;
          // mymap['e']=100;

          // itlow=mymap.lower_bound ('b');  // itlow points to b
          // itup=mymap.upper_bound ('d');   // itup points to e (not d!)

          // mymap.erase('b');        // erases [itlow,itup)
          // mymap.erase('c');        // erases [itlow,itup)
          // mymap.erase('d');        // erases [itlow,itup)

          // // print content:
          // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
          //   std::cout << it->first << " => " << it->second << '\n';
      }
      {
        // int psize;
        // ft::map<char,int> mymap;
        // ft::pair<const char,int>* p;

        // // allocate an array of 5 elements using mymap's allocator:
        // p=mymap.get_allocator().allocate(5);

        // // assign some values to array
        // psize = sizeof(ft::map<char,int>::value_type)*5;

        // std::cout << "The allocated array has a size of " << psize << " bytes.\n";

        // mymap.get_allocator().deallocate(p,5);
      }
      {
          // std::map<char,int> mymap;

          // mymap['a']=10;
          // mymap['b']=20;
          // mymap['c']=30;

          // std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
          // ret = mymap.equal_range('b');

          // std::cout << "lower bound points to: ";
          // std::cout << ret.first->first << " => " << ret.first->second << '\n';

          // std::cout << "upper bound points to: ";
          // std::cout << ret.second->first << " => " << ret.second->second << '\n';
      }
      
      {


        
            // ft::map<char,int> first;

            // first['a']=10;
            // first['b']=30;
            // first['c']=50;
            // first['d']=70;

            // ft::map<char,int> second (first.begin(),first.end());

            // ft::map<char,int> third (second);

            // ft::map<char,int,classcomp> fourth;                 // class as Compare

            // bool(*fn_pt)(char,char) = fncomp;
            // ft::map<char,int,bool(*)(char,char)> fifth (fn_pt);
            // for(ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
            // {
            //   std::cout << "first equal to " << it->first ;
            //   std::cout << " second equal to " << it->second << std::endl;
            // }
      }
      {
        //  int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
        //   ft::Vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

        //   // using default comparison:
        //   if ( ft::equal (myvector.begin(), myvector.end(), myints) )
        //     std::cout << "The contents of both sequences are equal.\n";
        //   else
        //     std::cout << "The contents of both sequences differ.\n";

        //   myvector[3]=81;                                 // myvector: 20 40 60 81 100

        //   // using predicate comparison:
        //   if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
        //     std::cout << "The contents of both sequences are equal.\n";
        //   else
        //     std::cout << "The contents of both sequences differ.\n";
      }
      {
          // char foo[]="Apple";
          // char bar[]="apartment";

          // std::cout << std::boolalpha;

          // std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

          // std::cout << "Using default comparison (operator<): ";
          // std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
          // std::cout << '\n';

          // std::cout << "Using mycomp as comparison object: ";
          // std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
          // std::cout << '\n';

      }
      {
          // ft::map<int, char> alice;
          // alice[1] = 'a';
          // alice[2] = 'b';
          // alice[3] = 'c';
          // ft::map<int, char> bob;
          // bob[7] = 'Z';
          // bob[8] = 'Y';
          // bob[9] = 'X';
          // bob[10] = 'W';
          // ft::map<int, char> eve;
          // eve[1] = 'a';
          // eve[2] = 'b';
          // eve[3] = 'c';
      
          // std::cout << std::boolalpha;
      
          // // Compare non equal containers
          // std::cout << "alice == bob returns " << (alice == bob) << '\n';
          // std::cout << "alice != bob returns " << (alice != bob) << '\n';
          // std::cout << "alice <  bob returns " << (alice < bob) << '\n';
          // std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
          // std::cout << "alice >  bob returns " << (alice > bob) << '\n';
          // std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
      
          // std::cout << '\n';
      
          // // Compare equal containers
          // std::cout << "alice == eve returns " << (alice == eve) << '\n';
          // std::cout << "alice != eve returns " << (alice != eve) << '\n';
          // std::cout << "alice <  eve returns " << (alice < eve) << '\n';
          // std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
          // std::cout << "alice >  eve returns " << (alice > eve) << '\n';
          // std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
      }
      
    
    return 0;
}