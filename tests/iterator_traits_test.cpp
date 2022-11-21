#include "../iterators/iterator_traits.hpp"

template <class MyIterator>
void do_something(MyIterator start, MyIterator end) {
    typedef typename iterator_traits<MyIterator>::value_type value_type; 
    //value_type v = *start;
    std::cout << " from do something \n";
    size_t i = 0;
    while(start != end)
    {
        std::cout << i << std::endl;
        i++;
    }
    
}

int main()
{
    int **myint ;
    **myint = 1;
    **(myint + 1) = 2;
    **(myint + 2) = 3;
    **(myint + 3) = 4;
   

    do_something(myint, myint + 4);

}