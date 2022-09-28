#include <iostream>

namespace first
{
    int x =0;
}
namespace second 
{
    float x = 0.1;
}
namespace second
{
    float y =0.5;
}

int main()
{
    std::cout << first::x << std::endl;
    std::cout << second::x << std::endl;
    std::cout << second::y << std::endl;
}