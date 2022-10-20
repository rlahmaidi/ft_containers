#include "random_access_iterator.hpp"
#include"vector.hpp"


int main()
{
    //ft::random_access<int>  it;
    ft::Vector<int> vec(3,2);
   //ft::Vector<int>::reverse_iterator rev;
    std::cout << vec.at(1) << std::endl;
 
    return 0;
}
