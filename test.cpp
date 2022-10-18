#include <iostream>
#include <vector>


int main ()
{
  try
  {
   std::vector<int> vec(4,1);
   std::cout << vec[1] << std::endl;
  }
  catch(const std::length_error& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  
  return(0);
}