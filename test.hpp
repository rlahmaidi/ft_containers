#include <iostream>

class  box
{
    private:
        int a;
    public:
            box(int val):a(val)
            {

            }
            friend void print_a(box bx);
};

void print_a(box bx)
{
    std::cout << bx.a << std::endl;

}