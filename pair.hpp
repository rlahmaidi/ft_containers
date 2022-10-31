#include <iostream>
namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        public:
                //member types
                typedef T1  first_type;
                typedef T2  second_type;
                // member variables
                first_type  first;
                second_type second;

                pair()
                {

                }
                //copy (2)	
                template<class U, class V> 
                pair (const pair<U,V>& pr)
                {
                    first = pr.first;
                    second = pr.second;
                }
                //initialization (3)	
                pair (const first_type& a, const second_type& b)
                {
                    first = a;
                    second = b;
                }
                pair& operator= (const pair& pr)
                {
                    first = pr.first;
                    
                }
                void swap (pair& pr) noexcept ( noexcept(swap(first,pr.first)) &&
                                noexcept(swap(second,pr.second)) )
                                {

                                }
                
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    //(2)	
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    //(3)	
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
   // (4)	
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
   // (5)	
    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    //(6)	
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

}