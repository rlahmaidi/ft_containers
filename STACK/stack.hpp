#include <iostream>
#include "../VECTOR/vector.hpp"
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>
namespace ft
{
    template <class T, class Container = ft::Vector<T> > 
    class stack
    {
        public:
                typedef     T          value_type;
                typedef     Container  container_type;
                typedef     size_t     size_type;

                explicit stack (const container_type& ctnr = container_type()): c(ctnr)
                {
                   
                }
                ~stack()
                {

                }
                bool empty() const
                {
                    return(c.empty());
                }
                size_type size() const
                {
                    return(c.size());
                }
                value_type& top()
                {
                    return(c.back());
                }
                const value_type& top() const
                {
                    return(c.back());
                }
                void push (const value_type& val)
                {
                    c.push_back(val);
                }
                void pop()
                {
                    c.pop_back();
                }
                template <class T1, class container>
                friend bool operator== (const stack<T1,container>& lhs, const stack<T1,container>& rhs);
                template <class T1, class container>
                friend bool operator!= (const stack<T1,container>& lhs, const stack<T1,container>& rhs);
                template <class T1, class container>
                friend bool operator< (const stack<T1,container>& lhs, const stack<T1,container>& rhs);
                template <class T1, class container>
                friend bool operator> (const stack<T1,container>& lhs, const stack<T1,container>& rhs);
                template <class T1, class container>
                friend bool operator<= (const stack<T1,container>& lhs, const stack<T1,container>& rhs);
                template <class T1, class container>
                friend bool operator>= (const stack<T1,container>& lhs, const stack<T1,container>& rhs);

        protected:
                container_type  c;
    };

  template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.c == rhs.c);
  }
//(2)	
template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.c != rhs.c);
  }
//(3)	
template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.c < rhs.c);
  }
//(4)	
template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.c <= rhs.c);
  }
//(5)	
template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.c > rhs.c);
  }
//(6)	
template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.c >= rhs.c);
  }

}