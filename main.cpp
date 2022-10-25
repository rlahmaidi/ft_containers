#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v;
    int i;
 
    for (i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
 
    /*v contains 0 1 2 3 4 5 6 7 8 9*/
 
    std::vector<int>::iterator first;
    vector<int>::iterator last;
 
    // first pointing to 0
    first = v.begin();
 
    // last pointing to 5
    last = v.begin() + 5;
 
    // Calculating no. of elements between first and last
    int num = std::distance(first, last);
 
    // Displaying num
    cout << num << "\n";
    return 0;
}
