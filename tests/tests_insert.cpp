#include"../vector.hpp"
#include <iomanip>
// #include <vector>
// #include <iostream>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
//#define IMHEREE std::cout  << "DeBug " << __LINE__ << "Function " << __PRETTY_FUNCTION__ << "FILE " << __FILE__ << std::endl;
#define THIS(X) std::cout  << "  DeBug " << __LINE__ << " bool "   << X<< std::endl;
/*
class Test
{
    std::string *l  = new std::string("Helooooooooooooooo");
    public:
        Test()
        {
            IMHEREE

        }
        ~Test()
        {
            IMHEREE
            delete l;
        }
        Test& operator=(const Test& tmp)
        {
            IMHEREE
            (void)tmp;
            return *this;
            
        }
        Test(const Test& tmp)
        {
            IMHEREE
            
            (void)tmp;
        }
};
*/
#define NS ft

int main ()
{
            std::cout << " the error is comming from here \n";
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::Vector<std::string>::size_type s, ft_s;
        ft::Vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond = true;
            
            
            
            std::cout << "***************** from the vector capacity >= size + n******"<< "\n";
            std::vector<std::string> v(20, "string");
            ft::Vector<std::string> ft_v(20, "string");
            ft::Vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, 70, "hello");
           
            ft_v.insert(ft_v.begin() + 15, 70, "hello");
          

            str.clear();
            ft_str.clear();
            s = v.size();
            THIS(s);
            ft_s = ft_v.size();
            THIS(ft_s)
            c = v.capacity();
            THIS(c);
            ft_c = ft_v.capacity();
            THIS(ft_c)
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];


            for (size_t i = 0; i < ft_v.size() ; ++i)
                ft_str += ft_v[i];

            for(size_t i = 0; i < v.size() ;i++)
            {
                std::cout << "+" << v[i] << std::endl;
            }
            for(size_t i = 0; i < ft_v.size() ;i++)
            {
                std::cout << "-" << ft_v[i] << std::endl;
            }
            s = v.size();
            THIS(s);
            ft_s = ft_v.size();
            THIS(ft_s)
            c = v.capacity();
            THIS(c);
            ft_c = ft_v.capacity();
            THIS(ft_c)
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
            if(cond == true)
                std::cout << "cond is true 3"<< std::endl;
            else 
                std::cout << "cond is false 3" << std::endl;
    
   
}
