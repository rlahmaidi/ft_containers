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

                // stack()
                // {

                // }
                explicit stack (const container_type& ctnr = container_type()): my_container(ctnr)
                {
                   
                }
                ~stack()
                {

                }
                bool empty() const
                {
                    return(my_container.empty());
                }
                size_type size() const
                {
                    return(my_container.size());
                }
                value_type& top()
                {
                    return(my_container.back());
                }
                const value_type& top() const
                {
                    return(my_container.back());
                }
                void push (const value_type& val)
                {
                    my_container.push_back(val);
                }
                void pop()
                {
                    my_container.pop_back();
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

        private:
                container_type  my_container;
    };

  template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.my_container == rhs.my_container);
  }
//(2)	
template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.my_container != rhs.my_container);
  }
//(3)	
template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.my_container < rhs.my_container);
  }
//(4)	
template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.my_container <= rhs.my_container);
  }
//(5)	
template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.my_container > rhs.my_container);
  }
//(6)	
template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
    return(lhs.my_container >= rhs.my_container);
  }

}