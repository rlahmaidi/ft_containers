// Example: of Constant member function
 
// #include<iostream>
// using namespace std;
 
// class Demo
// {
//     int x;
 
//       public:
//     Demo(int _x):x(_x)
//     {

//     }
     
//     void set_data(int a) 
//     {
//         x -= a;
//     }
  
//      int get_data()  const        //constant member function
//      {
//          ++x;            // Error while attempting to modify the data member
//          return x;
//      }
  
// };
 
 
// int main()
// {
//     const Demo d(12);
//     d.set_data(10);
//     cout<<endl<<d.get_data();
 
//     return 0;
//}
// long multiply(int i, int j) { return i * j; }

// template <class T>
// typename T::multiplication_result multiply(T t1, T t2)
// {
//   return t1 * t2;
// }
// int main(void)
// {
//   multiply(4,5);
// }