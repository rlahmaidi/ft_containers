#include"../vector.hpp"
#include <vector>
#include <iostream>

int main ()
{
    {
        //     // constuctor (n,val)
        // ft::Vector<int> foo (3,0);
        // ft::Vector<int> bar (5,0);
        // // operator[]
        // for(size_t i = 0; i < 3; i++)
        // {
        //     std::cout << foo[i] ;
        // }
        // std::cout << "\n";
        //     for(size_t i = 0; i < 5; i++)
        // {
        //     std::cout << bar[i] << " ";
        // }
        // std::cout << "\n";
        // // copy assignement 
        // bar = foo;
        // // default constructor;
        // foo = ft::Vector<int>();

        // // size() function
        // std::cout << "Size of foo: " << int(foo.size()) << '\n';
        // std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }
    {
        // ft::Vector<int> myvector;// we are not calling any  constructor, is it called explicityly?
        // // push_back  is working
        // for (int i=1; i<=5; i++) myvector.push_back(i);

        // std::cout << "myvector contains:";
        // // iterator is working fine; begin( ) and end() are working;
        // for (ft::Vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';
    }
    {
        //  ft::Vector<int> myvector (5);  // 5 default-constructed ints

        // int i=0;

        // ft::Vector<int>::reverse_iterator rit (myvector.rbegin());
        // for (; rit!= myvector.rend(); ++rit)
        //     *rit = ++i;

        // std::cout << "myvector contains:";
        // for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << "\n";
    }
    {// SIZE(), PUSH_BACK() , POP_BACK()
            // ft::Vector<int> myints;
            // std::cout << "0. size: " << myints.size() << '\n';

            // for (int i=0; i<10; i++) myints.push_back(i);
            // std::cout << "1. size: " << myints.size() << '\n';

            // // myints.insert (myints.end(),10,100);
            // // std::cout << "2. size: " << myints.size() << '\n';
            
            // myints.pop_back();
            // std::cout << "3. size: " << myints.size() << '\n';
    }
    {
        // ft::Vector<int> myvector;

        // // set some content in the vector:
        // for (int i=0; i<100; i++) myvector.push_back(i);

        // std::cout << "size: " << myvector.size() << "\n";
        // std::cout << "capacity: " << myvector.capacity() << "\n";
        // std::cout << "max_size: " << myvector.max_size() << "\n";
    }
    {//*********** RESIZE *************
        // ft::Vector<int> myvector;

        // // set some initial content:
        // // std::cout << "myvector size is " << myvector.size()<< '\n';
        // // std::cout << "myvector capacity is " << myvector.capacity()<< '\n';

        // for (size_t i = 1;i < 10; i++) myvector.push_back(i);

        // // std::cout << "myvector size is " << myvector.size()<< '\n';
        // // std::cout << "myvector capacity is " << myvector.capacity()<< '\n';

        // // myvector.resize(5);
        //  myvector.resize(8,100);
        //  //myvector.resize(12);

        // std::cout << "myvector contains:";
        // for (size_t i = 0;i < myvector.size(); i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';
    }
    {// EMPTY()
        //   ft::Vector<int> myvector;
        // int sum (0);

        // for (int i=1;i<=10;i++) myvector.push_back(i);

        // while (!myvector.empty())
        // {
        //     sum += myvector.back();
        //     myvector.pop_back();
        // }

        // std::cout << "total: " << sum << '\n';
    }
    {// RESIZE :it gives the same result as the std one;
        // ft::Vector<int>::size_type sz;

        // ft::Vector<int> foo;
        // sz = foo.capacity();
        // std::cout << "making foo grow:\n";
        // for (int i=0; i<100; ++i) {
        //     foo.push_back(i);
        //     if (sz!=foo.capacity()) {
        //     sz = foo.capacity();
        //     std::cout << "capacity changed: " << sz << '\n';
        //     }
        //     }

        // ft::Vector<int> bar;
        // sz = bar.capacity();
        // bar.reserve(100);   // this is the only difference with foo above
        // std::cout << "making bar grow:\n";
        // for (int i=0; i<100; ++i) {
        //     bar.push_back(i);
        //     if (sz!=bar.capacity()) {
        //     sz = bar.capacity();
        //     std::cout << "capacity changed: " << sz << '\n';
        //     }
        // }
    }
    {
        // ft::Vector<int> myvector (10);   // 10 zero-initialized elements

        // ft::Vector<int>::size_type sz = myvector.size();

        // // assign some values:
        // for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // // reverse vector using operator[]:
        // for (unsigned i=0; i<sz/2; i++)
        // {
        //     int temp;
        //     temp = myvector[sz-1-i];
        //     myvector[sz-1-i]=myvector[i];
        //     myvector[i]=temp;
        // }

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<sz; i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';
    }
    {//AT[]
        //   ft::Vector<int> myvector (10);   // 10 zero-initialized ints

        // // assign some values:
        // for (unsigned i=0; i<myvector.size(); i++)
        //     myvector.at(i)=i;

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector.at(i);
        // std::cout << '\n';
    }
    {
        // ft::Vector<int> myvector;

        // myvector.push_back(78);
        // myvector.push_back(16);

        // // now front equals 78, and back 16

        // myvector.front() -= myvector.back();

        // std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }
    { //BACK()
        //   ft::Vector<int> myvector;

        // myvector.push_back(10);

        // while (myvector.back() != 0)
        // {
        //     myvector.push_back ( myvector.back() -1 );
        // }

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size() ; i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';
    }
    {
        ft::Vector<int> first;
        ft::Vector<int> second;
        ft::Vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        ft::Vector<int>::iterator it;
        it=first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
    }
  return 0;     
}