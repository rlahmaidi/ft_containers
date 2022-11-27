// Static assertion using #error directive
#include <iostream>
#include  <type_traits>

template <bool, class T = void> 
struct enable_if 
{};

template <class T> 
struct enable_if<true, T> 
{ 
  typedef T type; 
};
template <class T>
// typename enable_if<is_arithmetic<T>::value , T>::type
// foo(T t)
// {
//   // ...
//   return t;
// }
// template <class T>
// T foo(T t, typename enable_if<is_arithmetic<T>::value >::type* dummy = 0);

int main()
{
    std::vector<int>::iterator it;
}
