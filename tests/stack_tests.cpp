#include "../STACK/stack.hpp"
#include <map>

int main()
{
    {
    //     std::deque<int> mydeque (3,100);          // deque with 3 elements
    //     ft::Vector<int> myvector (2,200);        // vector with 2 elements

    //     ft::stack<int> first;                    // empty stack
    //    ft::stack<int,std::deque<int> > second (mydeque);         // stack initialized to copy of deque

    //     ft::stack<int,ft::Vector<int> > third;  // empty stack using vector
    //     std::stack<int,ft::Vector<int> > fourth (myvector);

    //     std::cout << "size of first: " << first.size() << '\n';
    // std::cout << "size of second: " << second.size() << '\n';
    //     std::cout << "size of third: " << third.size() << '\n';
    //     std::cout << "size of fourth: " << fourth.size() << '\n';
    //     std::map<char,int> mymap;
    //         mymap['a']=101;
    //         mymap['b']=202;
    //         mymap['c']=302;
    //     ft::stack<int, std::map<char, int> > map_stack(mymap);
    //     std::cout << "size of map_stack is " << map_stack.size() << std::endl;
    }
    { // empty
        // ft::stack<int> mystack;
        // int sum (0);

        // for (int i=1;i<=10;i++) mystack.push(i);

        // while (!mystack.empty())
        // {
        //     sum += mystack.top();
        //     mystack.pop();
        // }

        // std::cout << "total: " << sum << '\n';

    }
    {// size
    //     ft::stack<int> myints;
    //     std::cout << "0. size: " << myints.size() << '\n';

    //     for (int i=0; i<5; i++) myints.push(i);
    //     std::cout << "1. size: " << myints.size() << '\n';

    //     myints.pop();
    //     std::cout << "2. size: " << myints.size() << '\n';
    }
    {// top
        // ft::stack<int> mystack;

        // mystack.push(10);
        // mystack.push(20);

        // mystack.top() -= 5;

        // std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }
    {// push and pop;
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }
}
                            