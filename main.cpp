#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // Create a vector of integers
    vector<int> vec_of_num{1, 3, 4, 7, 8, 9};
    // Iterate over a vector in backward direction using
    // reverse iterators
    std::vector<int>::reverse_iterator it = vec_of_num.rbegin();
    while (it != vec_of_num.rend())
    {
        std::cout<<*it<<", ";
        it++;
    }
    return 0;
}
