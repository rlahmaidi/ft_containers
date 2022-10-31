#include"../vector.hpp"
#include <iomanip>
// #include <vector>
// #include <iostream>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define IMHEREE std::cout  << "DeBug " << __LINE__ << "Function " << __PRETTY_FUNCTION__ << "FILE " << __FILE__ << std::endl;

class Test
{
    public:
        Test()
        {
            IMHEREE
        }
        ~Test()
        {
            IMHEREE
            
        }
        Test& operator=(const Test& tmp)
        {
            IMHEREE
            (void)tmp;
            return *this;
            
        }
        Test(const Test& tmp)
        {
            IMHEREE
            (void)tmp;
        }
};

#define NS ft

int main ()
{
   NS::Vector<Test>  eyes(10);
   NS::Vector<Test>::iterator it = eyes.begin();
   for(; it != eyes.end(); it++)
   {
        
   }

}
