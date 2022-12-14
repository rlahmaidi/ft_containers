#pragma once
#include <iostream>
namespace ft
{
    template <class T1, class T2>
    struct pair
    {
     
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
                pair ( const pair<U,V>& pr):first(pr.first),second(pr.second)
                {
                    // i'm assigning here , not copying and that cause me
                    // a 3 hours of headach, lesson :
                    // do not use assignement operator in copy constructors again
                    // first = pr.first;
                    // second = pr.second;
                }
                //initialization (3)	
                pair (const first_type& a, const second_type& b):first(a), second(b)
                {
                    // same here;
                    // first = a;
                    // second = b;
                }
                pair& operator= (const pair& pr)
                {
                    first = pr.first;
                    second = pr.second;
                    return(*this);
                    
                }
            

                
    };
                template <class T1,class T2>
                pair<T1,T2> make_pair (T1 x, T2 y)
                {
                    return ( pair<T1,T2>(x,y) );
                }

                
                template <class T1, class T2>
                bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
                {
                    return lhs.first==rhs.first && lhs.second==rhs.second; 
                }

                template <class T1, class T2>
                bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
                { 
                    return !(lhs==rhs); 
                }

                template <class T1, class T2>
                bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
                { 
                    return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
                }

                template <class T1, class T2>
                bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
                { 
                    return !(rhs<lhs); 
                }

               template <class T1, class T2>
                 bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
                { 
                    return rhs<lhs; 
                }

                template <class T1, class T2>
                bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
                { 
                    return !(lhs<rhs); 
                }

}