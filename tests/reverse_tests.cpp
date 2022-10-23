#include "../vector.hpp"
#include "../random_access_iterator.hpp"
#include "../iterator_traits.hpp"
#include "../reverse_iterator.hpp"
#include <iterator>
#include <vector>
int main () {
  //ft::random_access<int> rev_from;
  int numbers[]={10,20,30,40,50};
   ft::random_access< int> rand_from(numbers);// constuctor with(pointer);
   ft::random_access< int> rand_until(numbers+5);// testeing operator+(int n) and constructor with (reverse_iterator)
  for ( ft::random_access< int> rev_from=rand_from; rev_from!= rand_until; rev_from++)// assignement operator and != and operator++(post)
    std::cout << *rev_from << ' '; // operator*()
  std::cout << '\n';
  //*****************reverse
  ft::reverse_iterator<ft::random_access<int> > rev_from(rand_from);
  ft::reverse_iterator<ft::random_access<int> > rev_until(rand_until);
  

//****************comparaison operaors*****
ft::reverse_iterator<ft::random_access<int> > rev1 = ft::reverse_iterator<ft::random_access<int> >();
rev1 = rev_from ;
ft::reverse_iterator<ft::random_access<int> > constru_test(rev_from);
// == opeartor
if(rev_from == rev1) // == opeartor
    std::cout << "************    == is working " << std::endl;
else
    std::cout << "t***********   hey are not equal " << std::endl;
//<  operator 
if(rev_from < rev_until)
    std::cout << "************   < is working " << std::endl;
// >  opeartor 
if(rev_until > rev_from)
    std::cout << "************  > is working " << std::endl;
// <=  opeartor 
if(rev_from <= rev1 )
    std::cout << "************** <= is working" << std::endl;
// >=  opeartor 
if(rev_until >= rev_from)
    std::cout << "************  >= is working " << std::endl;
// !=  opeartor 
if(rev_from != rev1)
    std::cout << " ********** !=  is not working " << std::endl;
else
    std::cout << " ********** !=  is  working " << std::endl;
//***************derefferenced as an rvalue and lvalue****

// as an rvalue
    std::cout << *rev_from << std::endl;
// as an lvalue
*rev_from = 1337;
std::cout << *rev_from << std::endl;
*rev_from = 10;
//******************incremant and decrement********//

// ++ (pre)
++rev_from;
std::cout << *rev_from << std::endl;
// -- (pre)
--rev_from;
std::cout << *rev_from << std::endl;
//++ (post)
rev_from++;
std::cout << *rev_from << std::endl;
// -- (post)
rev_from--;
std::cout << *rev_from << std::endl;
// += 
rev_from += 1;
std::cout << *rev_from << std::endl;
// -=
rev_from -= 1;
std::cout << *rev_from << std::endl;
// operator+(int n)
rev_from = rev_from + 1;
std::cout << *rev_from << std::endl;
// operator-(reverse_iterator rev_from)
ptrdiff_t   diff = rev_until - rev_from;
std::cout << diff << " std::distance " << std::endl;// std::distance(rev_from, rev_until) << std::endl;
// operator-(int n)
rev_from = rev_until - 5;
std::cout << *rev_from << std::endl;
// opeartor []
std::cout << rev_from[0] << " " << rev_from[1]<< " " << rev_from[2] <<  std::endl;
// opeartor+(int n, rev_from)
//rev_from = 4 + rev_from;
std::cout << *rev_from << std::endl;





return 0;
}