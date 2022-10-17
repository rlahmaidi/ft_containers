#include <iostream>
#include <vector>


int main ()
{
  std::vector<int> vec(5,1);
  std::cout << vec[-3] << std::endl;
  return(0);
}