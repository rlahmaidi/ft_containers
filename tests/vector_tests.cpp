#include"../vector.hpp"
// #include <vector>
// #include <iostream>

int main ()
{
    {
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
    {// CONSTRUCTORS;
         // constructors used in the same order as described above:
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
    {//assign:   NOT FIXED YET;
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
    //     ft::Vector<int> foo (3,100);   // three ints with a value of 100
    //     ft::Vector<int> bar (5,200);   // five ints with a value of 200

    //     foo.swap(bar);

    //     std::cout << "foo contains:";
    //     for (unsigned i=0; i<foo.size(); i++)
    //         std::cout << ' ' << foo[i];
    //     std::cout << '\n';

    //     std::cout << "bar contains:";
    //     for (unsigned i=0; i<bar.size(); i++)
    //         std::cout << ' ' << bar[i];
    //     std::cout << '\n';
    }
    {// clear()
        // std::vector<int> myvector;
        // myvector.push_back (100);
        // myvector.push_back (200);
        // myvector.push_back (300);

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';

        // myvector.clear();
        // myvector.push_back (1101);
        // myvector.push_back (2202);

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //     std::cout << ' ' << myvector[i];
        // std::cout << '\n';
    }
    {// INSERT 
        ft::Vector<int> myvector (3,100);
        ft::Vector<int>::iterator it;
        // std::cout << "myvector contains:";
        for (it = myvector.begin() ;it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << "\n";

        
        it = myvector.begin() + 1;
        //std::cerr << "molay [cd Rays] " << it - myvector.begin() <<" "<< sizeof(ptrdiff_t) <<"++" << &*myvector.begin() << std::endl;
        it = myvector.insert ( it , 200);
       // std::cerr <<__LINE__ <<  "molay [cd Rays] " << &*myvector.begin() << std::endl;
        for (it = myvector.begin() ;it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << "\n";
        //  std::cout << *it  <<" " << &*it << std::endl;
        //  std::cout << *it  <<" " << &*myvector.begin() << std::endl;

        // int i = 0;
        // while (i < 10)
        // {
        //     std::cout << "\t" <<*it << "++++" << &*it  << std::endl;
        //     it++;
        //     i++ ;
        // }

        //myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        //it = myvector.begin();

        // std::vector<int> anothervector (2,400);
        // myvector.insert (it+2,anothervector.begin(),anothervector.end());

        // int myarray [] = { 501,502,503 };
        // myvector.insert (myvector.begin(), myarray, myarray+3);
        // it = myvector.end() ;
        // it--;
        // std::cout << *it << std::endl;
        
        std::cout << "myvector contains:\n";
        for (it = myvector.begin() ;it<myvector.end(); it++)
            std::cout << "\t " << *it << " "<< &*it << std::endl;
        std::cout << '\n';
     }
    {
    //     std::vector<int> myvector (3,100);
    //     std::vector<int>::iterator it;

    //     it = myvector.begin();
    //    // std::cout << " form test , the distance in std is " << std::distance(myvector.end(), myvector.end());
    //     it = myvector.insert ( it , 200 );

    //     myvector.insert (it,2,300);

    //     // "it" no longer valid, get a new one:
    //     it = myvector.begin();

    //     std::vector<int> anothervector (2,400);
    //     myvector.insert (it+2,anothervector.begin(),anothervector.end());

    //     int myarray [] = { 501,502,503 };
    //     myvector.insert (myvector.begin(), myarray, myarray+3);

    //     std::cout << "myvector contains:";
    //     for (it=myvector.begin(); it<myvector.end(); it++)
    //         std::cout << ' ' << *it;
    //     std::cout << '\n';
    }
  return 0;     
}






























// iterator insert(iterator pos, const value_type& val)
// 		{
// 			difference_type p = pos - _data;

// 			if (_size == _capacity)
// 			{
// 				if (_capacity == 0)
// 					reserve(1);
// 				else
// 					reserve(_capacity*2);
// 			}
// 			for (difference_type i = _size; i > p; i--)
// 				_alloc.construct(&_data[i], _data[i - 1]);
// 			_alloc.construct(&_data[p], val);
// 			_size++;
// 			return (_data + p);
// 		}
// 		void insert(iterator position, size_type n , const value_type& val)
// 		{
//             size_type o = position - this->begin();
//             size_type i = 0;
//             size_type k = n;
//             if (_size + n > _capacity)
//             {
//                 if (_size + n < _size * 2)
//                     reserve(!(_size )? 1 : (_size * 2));
//                 else
//                     reserve(!(_size + n)? 1 : (_size + n ));
//             }
//             while (_size - i + n > 0)
//             {
//                 if (_size - i == o)
//                 {
//                     while (k--)
//                         _alloc.construct(&_data[_size - i + k] , val);
//                     break;
//                 }
//                 else
//                     _alloc.construct(&_data[_size - i + n - 1] , _data[_size - i - 1]);
//                 i++;
//             }
//             _size += n;
// 		}

// 		template <class InputIterator>
// 		void insert (iterator position, InputIterator first, InputIterator last,
// 					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
// 		{
//             size_type n = std::distance(first, last);
//             size_type i = 0;
//             size_type pos = position - begin();
//             if (_capacity < _size + n && n <= _size)
//                 reserve(_capacity * 2);
//             else if (_size + n > _capacity)
//                 reserve(_capacity + n);
//             while (_size + n - i > 0)
//             {
//                 if (_size - i == pos)
//                 {
//                     pos = n;
//                     try
//                     {
//                         while (pos--)
//                            _alloc.construct(&_data[_size - i + pos], *(--last));
//                     }
//                     catch (...)
//                     {
//                         for (size_type i = size(); i != 0; i--)
//                         {

//                             std::cout << "i =  " << i << std::endl;
//                             _alloc.destroy(&_data[i - 1]);
//                         }
//                         _capacity = 0;
//                         throw "out of range";
//                     }
//                     break;
//                 }
//                 else
//                     _alloc.construct(&_data[_size - i + n - 1] ,  _data[_size - i - 1]);
//                 i++;
//             }
//             _size += n;
// 		}