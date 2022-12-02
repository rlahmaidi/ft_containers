#include "../VECTOR/vector.hpp"
// #include "../UTILS/is_integral.hpp"
// #include "../UTILS/enable_if.hpp"
#include "../STACK/stack.hpp"
// #include "../UTILS/pair.hpp"
#include "../MAP/map.hpp"

void print_map(ft::map<std::string, int> map, std::string map_name)
{
        ft::map<std::string, int>::iterator loop;
        std::cout << map_name << " contains: ";
        loop = map.begin();
        for(; loop != map.end(); ++loop)
        {
            std::cout << " key-" << loop->first << "-value:-";
            std::cout << loop->second;
        }
        std::cout << "\n";
}

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
        ft::map<std::string,int> map1;// default constructor;
        map1["1"] = 1;
        map1["2"] = 2;
        map1["3"] = 3;
        map1["4"] = 4;
        ft::map<std::string, int> map2(map1.begin(), map1.end());// range constructor;
        ft::map<std::string, int>::iterator loop;

        print_map(map1,"map1");
        print_map(map2, "map2");
        std::cout << "********************* operator=********" << std::endl;
        ft::map<std::string, int> map3 = map2;
        print_map(map3, "map3");
        std::cout << "******************** operator[]***************" << std::endl;
        std::cout << "print first element with operator[]: " << map3["1"] << std::endl;
        std::cout << "create a key without a value " << map3["5"] << std::endl;
        std::cout << "********************* iterators ***************" << std::endl;
        std::cout << "use begin and end to print map3 :";
        for(ft::map<std::string, int>::iterator it = map3.begin(); it != map3.end(); ++it)
        {
            std::cout << " key-"<< it->first << "-value-" ;
        }
        std::cout << "\n";

        std::cout << "use rbegin and rend to print map3 :";
        for(ft::map<std::string, int>::reverse_iterator it = map3.rbegin(); it != map3.rend(); ++it)
        {
            std::cout << " key-"<< it->first << "-value-" ;
        }
        std::cout << "\n";
        std::cout << " ********************* capacity methods ************" << std::endl;
        std::cout << "map3 size is " << map3.size() << std::endl;
        std::cout << "map3 max_size is " << map3.max_size() << std::endl;
        if(!map3.empty())
            std::cout << "our map is not empty\n";
        
        std::cout << " ******************** modifiers *****************" << std::endl;
        map1.clear();// clear
        std::cout << "map1 size after clear is "<< map1.size() << "\n";
        print_map(map1, "map1");
        std::cout << "************ insert with val****************\n";
        ft::pair<ft::map<std::string, int>::iterator , bool>  p;
        p = map1.insert(ft::make_pair("1",1));
        if(p.second == true)
        {
            std::cout << "the element that was inserted is " ;
            std::cout << p.first->first << std::endl;
        }
        std::cout << "************insert with position*************\n";
        loop = map1.insert(map1.begin(),ft::make_pair("2", 2));
        std::cout << "the element that was inserted is ";
        std::cout << loop->first << std::endl;
        std::cout << "************insert range ************\n";
        ft::map<std::string, int> inser(map1.begin(), map1.end());
        print_map(inser, "inser");

        std::cout << "************ erase ***************************\n";
        inser["3"] = 3;
        inser["4"] = 4;
        std::cout << "******erase by key****************************\n";
        inser.erase("3");
        print_map(inser, "inser");
        std::cout << "******erase by position***********************\n";
        inser.erase(inser.begin());
        print_map(inser, "inser");
        std::cout << "******erase range*****************************\n";
        inser.erase(inser.begin(), inser.end());
        print_map(inser, "inser");
        std::cout << "******erase range*****************************\n";


        
        //************* get_allocator*******
        
    
    }

}