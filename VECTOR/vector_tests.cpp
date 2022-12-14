#include"vector.hpp"
#include <iomanip>
// #include <vector>
// #include <iostream>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
int main ()
{

    {// CONSTRUCTORS;
        // // constructors used in the same order as described above:
        // std::vector<int> first;                                // empty vector of ints
        // std::vector<int> second (4,100);                       // four ints with value 100
        // std::vector<int> third (second.begin(),second.end());  // iterating through second
        // std::vector<int> fourth (third);                       // a copy of third

        // // the iterator constructor can also be used to construct from arrays:
        // int myints[] = {16,2,77,29};
        // std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        // std::cout << "The contents of fifth are:";
        // for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';
     }

    {// rbegin , rend
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
    {//  push_back , capacity , size, max_size;
        // ft::Vector<int> myvector;

        // // set some content in the vector:
        // for (int i=0; i<100; i++) myvector.push_back(i);

        // std::cout << "size: " << myvector.size() << "\n";
        // std::cout << "capacity: " << myvector.capacity() << "\n";
        // std::cout << "max_size: " << myvector.max_size() << "\n";
    }

     {// reserve
    //       ft::Vector<int>::size_type sz;

    //     ft::Vector<int> foo;
    //     sz = foo.capacity();
    //     std::cout << "making foo grow:\n";
    //     for (int i=0; i<100; ++i) {
    //         foo.push_back(i);
    //         if (sz!=foo.capacity()) {
    //         sz = foo.capacity();
    //         std::cout << "capacity changed: " << sz << '\n';
    //         }
    //     }

    //     ft::Vector<int> bar;
    //     sz = bar.capacity();
    //     bar.reserve(100);   // this is the only difference with foo above
    //     std::cout << "making bar grow:\n";
    //     for (int i=0; i<100; ++i) {
    //         bar.push_back(i);
    //         if (sz!=bar.capacity()) {
    //         sz = bar.capacity();
    //         std::cout << "capacity changed: " << sz << '\n';
    //         }
    //     }
    }

    {//*********** RESIZE *************
        // ft::Vector<int> myvector;
        // int a = int();
        // std::cout << a << std::endl;
        // // set some initial content:
        // // std::cout << "myvector size is " << myvector.size()<< '\n';
        // // std::cout << "myvector capacity is " << myvector.capacity()<< '\n';

        // for (size_t i = 1;i < 10; i++) myvector.push_back(i);

        // // std::cout << "myvector size is " << myvector.size()<< '\n';
        // // std::cout << "myvector capacity is " << myvector.capacity()<< '\n';

        //  myvector.resize(2);
        //  myvector.resize(13,100);
        //  myvector.resize(20);

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
    {// reserve 
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
    {// operator[]
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
        // for (unsigned i=0; i< myvector.size(); i++)
        //     myvector.at(i)=i;

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector.at(i);
        // std::cout << '\n';
    }
    {// front
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
    {//assign:
        // ft::Vector<int> first;
        // ft::Vector<int> second;
        // ft::Vector<int> third;

        // first.assign (7,100);             // 7 ints with a value of 100

        // ft::Vector<int>::iterator it;
        // it=first.begin()+1;

        // second.assign (it,first.end()-1); // the 5 central values of first

        // int myints[] = {1776,7,4};
        // third.assign (myints,myints+3);   // assigning from array.

        // std::cout << "Size of first: " << int (first.size()) << '\n';
        // std::cout << "Size of second: " << int (second.size()) << '\n';
        // std::cout << "Size of third: " << int (third.size()) << '\n';
    }
    {// push_back()
        // ft::Vector<int> myvector;
        
        // for(int i = 0; i < 10; i++)
        // {
        //     myvector.push_back(i);
        // }
        // for(int i = 0;i < 10; i++)
        // {
        //     std::cout << myvector[i]<< "  " ;
        // }
        // std::cout << "\n";

        // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    }
    {// pop_back()
        //  ft::Vector<int> myvector;
        // int sum (0);
        // myvector.push_back (100);
        // myvector.push_back (200);
        // myvector.push_back (300);

        // while (!myvector.empty())
        // {
        //     sum+=myvector.back();
        //     myvector.pop_back();
        // }

        // std::cout << "The elements of myvector add up to " << sum << '\n';
        // std::cout << "my vector size is " << myvector.size() << "\n";
    }
    {// erase()
        //   ft::Vector<int> myvector;

        // // set some values (from 1 to 10)
        // for (int i=1; i<=10; i++) myvector.push_back(i);

        // // erase the 6th element
        // myvector.erase (myvector.begin()+5);

        // // erase the first 3 elements:
        // myvector.erase (myvector.begin(),myvector.begin()+3);

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); ++i)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';

    }
    {// swap()
        // ft::Vector<int> foo(10,100) ;   
      
        // ft::Vector<int> bar (5,200);   // five ints with a value of 200

        // ft::Vector<int>::iterator it1 = foo.begin (), it2 = bar.begin();

        // std::cout << "content of it1 shoud be 100 and it is :" << *it1 <<"\n";
        // std::cout << "content of it2 shoud be 200 and it is :" << *it2 <<"\n";
    
 

        // foo.swap(bar);
        // std::cout << "content of it1 shoud be 100 and it is :" << *it1 <<"\n";
        // std::cout << "content of it2 shoud be 200 and it is :" << *it2 <<"\n";
        // it1++;
        // std::cout << *it1<< "\n";
    
    
        // for (unsigned i=0; i<foo.size(); i++)
        //     std::cout << ' ' << foo[i];
        // std::cout << '\n';

        // std::cout << "bar contains:";
        // for (unsigned i=0; i<bar.size(); i++)
        //     std::cout << ' ' << bar[i];
        // std::cout << '\n';
    }
    {// insert
        // ft::Vector<int> myvector (3,100);
        // ft::Vector<int>::iterator it;

        // it = myvector.begin();
        // it = myvector.insert (it , 200);
        // myvector.insert (it,3,300);
        // //"it" no longer valid, get a new one:
        // it = myvector.begin();

        // ft::Vector<int> anothervector (2,400);
        // myvector.insert (it+2,anothervector.begin(),anothervector.end());

        // int myarray [] = { 501,502,503 };
        // myvector.insert (myvector.begin(), myarray, myarray+3);

        // std::cout << "myvector contains:";
        // for (it=myvector.begin(); it<myvector.end(); it++)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';
    }
    {// GET ALLOCATOR
        //   ft::Vector<int> myvector;
        // int * p;
        // unsigned int i;

        // // allocate an array with space for 5 elements using vector's allocator:
        // p = myvector.get_allocator().allocate(5);

        // // construct values in-place on the array:
        // for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

        // std::cout << "The allocated array contains:";
        // for (i=0; i<5; i++) std::cout << ' ' << p[i];
        // std::cout << '\n';

        // // destroy and deallocate:
        // for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
        // myvector.get_allocator().deallocate(p,5);

    }
    {// == OPERATOR
        // ft::Vector<int> v1(3,100);
        // ft::Vector<int> v2(3,200);
        // if(v1 == v2)
        //     std::cout << " your vectors are equal\n";
        // else
        //     std::cout << " your vectors are not equal\n";
        // ft::Vector<int> foo (5,200);   // three ints with a value of 100
        // ft::Vector<int> bar (5,100);   // two ints with a value of 200

        // if (foo==bar) std::cout << "foo and bar are equal\n";
        //  if (foo!=bar) std::cout << "foo and bar are not equal\n";
        //  if (foo< bar) std::cout << "foo is less than bar\n";
        // if (foo> bar) std::cout << "foo is greater than bar\n";
        //  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        //  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
        //  std::cout << "\n\n\n";

    }
    {
    //     std::vector<int> foo (5,200);   // three ints with a value of 100
    //     std::vector<int> bar (5,100);   // two ints with a value of 200

    //     if (foo==bar) std::cout << "std: foo and bar are equal\n";
    //     if (foo!=bar) std::cout << "std: foo and bar are not equal\n";
    //     if (foo< bar) std::cout << "std: foo is less than bar\n";
    //     if (foo> bar) std::cout << "std: foo is greater than bar\n";
    //     if (foo<=bar) std::cout << "std: foo is less than or equal to bar\n";
    //     if (foo>=bar) std::cout << "std: foo is greater than or equal to bar\n";
    }
    {//ft swap
       // unsigned int i;
        // ft::Vector<int> foo (3,100);   // three ints with a value of 100
        // ft::Vector<int> bar (5,200);   // five ints with a value of 200

        // ft::swap(bar,foo);

        // std::cout << "foo contains:";
        // for (ft::Vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';

        // std::cout << "bar contains:";
        // for (ft::Vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        //     std::cout << ' ' << *it;
        // std::cout << '\n';
    }
    {//std swap
        // std::vector<int> foo (3,100);   // three ints with a value of 100
        // std::vector<int> bar (5,200);   // five ints with a value of 200

        // swap(bar,foo);

        // std::cout << "foo contains:";
        // for (unsigned i=0; i<foo.size(); i++)
        //     std::cout << ' ' << foo[i];
        // std::cout << '\n';

        // std::cout << "bar contains:";
        // for (unsigned i=0; i<bar.size(); i++)
        //     std::cout << ' ' << bar[i];
        // std::cout << '\n';
    }
    {// itertor comparaison
        ft::Vector<int> v(2,5);
        ft::Vector<int>::iterator it1;
        it1 = v.begin() ;
        ft::Vector< int>::const_iterator it2;

        it2 = v.begin();
        if(it2 == it1)
            std::cout << "it is working \n";
        else
            std::cout << "it is not working\n";
        
    }
    { // iterator invalidation
    //  ft::Vector<int> v;
    //  v.push_back(1);
    //  ft::Vector<int>::iterator it = v.begin() ;
    //  v.insert(it,10);
    //  std::cout << "content of it is " << *it << std::endl;

    }
   
        
    
  return 0;
        
}
