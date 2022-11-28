#include "../VECTOR/vector.hpp"
// #include "../UTILS/is_integral.hpp"
// #include "../UTILS/enable_if.hpp"
#include "../STACK/stack.hpp"
// #include "../UTILS/pair.hpp"
#include "../MAP/map.hpp"


int main()
{
    {// for vector;
        //  //constructors;
        // ft::Vector<int> v;
        // v.push_back(1);
        // v.push_back(2);
        // ft::Vector<int> v2(v);
        // ft::Vector<int> v3(4,10);
        // ft::Vector<int> v4 = v3;
        // for(ft::Vector<int>::iterator it = v4.begin(); it!= v4.end(); ++it)
        // {
        //     std::cout << *it<< "\n";
        // }
        // // get_allocator()
        // ft::Vector<int>::allocator_type allo;
        // allo = v.get_allocator();
        // int *p = allo.allocate(5);
        // for(int i = 0; i < 5; i++)
        // {
        //     allo.construct(p+i,1);
        // }
        // for(int i = 0; i < 5; i++)
        // {
        //     std::cout << p[i] << "\n";
        // }
        // // at
        // std::cout << v.at(1) << "\n";
        // // operator []
        // std::cout <<"lmhaloussa chaksyan"<< v[1] << "\n";
        // // front 
        // std::cout << v.front() << std::endl;
        // //back 
        // std::cout << v.back() << std::endl;
        // // begin()
        // std::cout << *v.begin() << std::endl;
        // //end()
        // std::cout << *(v.end() -1) << std::endl;
        // //rbegin()
        // std::cout << *v.rbegin() << std::endl;
        // // rend()
        // std::cout << *v.rend() << std::endl;
        // //empty()
        // if(!v.empty())
        //     std::cout << " it is not empty\n";
        // //size()
        // std::cout << v.size() << std::endl;
        // // reserve()
        // //v.reserve(100);
        // std::cout << "new capacity is " << v.capacity() << "\n";
        // //max_size()
        // std::cout << "max size is " << v.max_size() << "\n";
        // //v.reserve( 461168601842);
        // std::cout << "new capacity is " << v.capacity() << "\n";
        // //clear()
        // v.clear();
        // std::cout << "capacity after clear is " << v.size() << std::endl;
        // //insert
        // std::cout << "v capacity now is " << v.capacity() << std::endl;
        // ft::Vector<int>::iterator it1 = v.begin();

        // it1 = v.insert(it1,3);
        // v.insert(it1,3,4);
        // v.insert(it1,v3.begin(),v3.end());
        // std::cout << "my vector now contains ";
        // for(ft::Vector<int>::iterator it6 = v.begin();it6 != v.end(); ++it6)
        // {
        //     std::cout << *it6 << " ";
        // }
        // std::cout << std::endl;
        // //erase
        // it1 = v.begin();
        // it1 = v.erase(it1);
        // std::cout << *it1 << "\n";
        // it1 = v.erase(it1, v.end() - 4);
        // std::cout << "my vector now contains ";
        // for(ft::Vector<int>::iterator it6 = v.begin();it6 != v.end(); ++it6)
        // {
        //     std::cout << *it6 << " ";
        // }
        // std::cout << std::endl;
        // //push_back()
        // ft::Vector<std::string> vec(3,"hello");
        // vec.push_back("world");
        // std::cout << "my vector now contains ";
        // for(ft::Vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
        // {
        //     std::cout << *it << " ";
        // }
        // std::cout << "\n";
        // //pop_back()
        // v.pop_back();
        //         std::cout << "my vector now contains ";
        // for(ft::Vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
        // {
        //     std::cout << *it << " ";
        // }
        // std::cout << "\n";
        // //swap
        // ft::Vector<int>     swap_vec(2,10);
        // ft::Vector<int>     swap_vec1(3,20);

        // swap_vec1.swap(swap_vec);
        //         std::cout << "my vector now contains ";
        // for(ft::Vector<int>::iterator it = swap_vec.begin(); it != swap_vec.end(); ++it)
        // {
        //     std::cout << *it << " ";
        // }
        // std::cout << "\n";
        // ft::swap(swap_vec,swap_vec1);
        //  std::cout << "my vector now contains ";
        // for(ft::Vector<int>::iterator it = swap_vec.begin(); it != swap_vec.end(); ++it)
        // {
        //     std::cout << *it << " ";
        // }
        // std::cout << "\n";
        // // comparaison operators;
        //  if (swap_vec < swap_vec1)
        //     std::cout << "it should print this\n";
        // else
        //     std::cout << "it shouldn't print this\n";  
    }
    {// for stack();
        // ft::Vector<int> myvector(10,20);
        // ft::stack<int, ft::Vector<int> >  mystack(myvector);

        // std::cout << "my stack size is "<< mystack.size() << std::endl;
        // std::cout << "the top element of my stack is "<< mystack.top() << std::endl;
        // mystack.push(30);
        // mystack.push(40);
        // mystack.push(50);
        // mystack.pop();
        // while(!mystack.empty())
        // {
        //     mystack.pop();
        // }
        // std::cout << "my stack size is "<< mystack.size() << std::endl;
        // // comparaison
        // ft::Vector<int>  second_vector(5,10);
        // if(myvector < second_vector)
        //     std::cout << "myvector is inferior to second_vector\n";
        // else
        //     std::cout << "myvector is superior to second_vector\n";
        // ft::stack<int,ft::Vector<int> > second_stack(second_vector);
        // if(second_stack > mystack)
        //     std::cout << " mystack is inferior to second_sta" <<"\n";
        // else
        //     std::cout << " mystack" <<"\n";
        
    }
    {//map
    
    }

}