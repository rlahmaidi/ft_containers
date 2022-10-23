#include "../vector.hpp"
#include "../random_access_iterator.hpp"
#include "../iterator_traits.hpp"
int main () {
  int numbers[]={10,20,30,40,50};
   ft::random_access< int> from(numbers);// constuctor with(pointer);
   ft::random_access< int> until(numbers+5);// testeing operator+(int n) and constructor with (random_access)
  for ( ft::random_access< int> it=from; it!=until; it++)// assignement operator and != and operator++(post)
    std::cout << *it << ' '; // operator*()
  std::cout << '\n';
//****************comparaison operaors*****
ft::random_access<int> it = ft::random_access<int>();
it = from;
// == opeartor
if(it == from) // == opeartor
    std::cout << "************    == is working " << std::endl;
else
    std::cout << "t***********   hey are not equal " << std::endl;
//<  operator 
if(it < until)
    std::cout << "************   < is working " << std::endl;
// >  opeartor 
if(until > it)
    std::cout << "************  > is working " << std::endl;
// <=  opeartor 
if(it <= from )
    std::cout << "************** <= is working" << std::endl;
// >=  opeartor 
if(until >= it)
    std::cout << "************  >= is working " << std::endl;
// !=  opeartor 
if(it != from)
    std::cout << " ********** !=  is not working " << std::endl;
else
    std::cout << " ********** !=  is  working " << std::endl;
//***************derefferenced as an rvalue and lvalue****

// as an rvalue
    std::cout << *it << std::endl;
// as an lvalue
*it = 1337;
std::cout << *it << std::endl;
*it = 10;
//******************incremant and decrement********//

// ++ (pre)
++it;
std::cout << *it << std::endl;
// -- (pre)
--it;
std::cout << *it << std::endl;
//++ (post)
it++;
std::cout << *it << std::endl;
// -- (post)
it--;
std::cout << *it << std::endl;
// += 
it += 1;
std::cout << *it << std::endl;
// -=
it -= 1;
std::cout << *it << std::endl;
// operator+(int n)
it = it + 1;
std::cout << *it << std::endl;
// operator-(random_access it)
std::cout << (until - it) << " std::distance " << std::distance(it, until) << std::endl;
// operator-(int n)
it = until - 5;
std::cout << *it << std::endl;
// opeartor []
std::cout << it[0] << " " << it[1]<< " " << it[2] <<  std::endl;
// opeartor+(int n, it)
it = 4 + it;
std::cout << *it << std::endl;





return 0;
}