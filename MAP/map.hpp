#pragma once
#include <iostream>
#include "../utils/pair.hpp"
#include "../iterators/random_access_iterator.hpp" // i think we should define a bidir now;
#include "../iterators/iterator_traits.hpp"
#include "avl_test.hpp"



namespace ft 
{
    template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<pair<const Key, T> > >
    class map 
    {
            public:
            // types:
            typedef Key key_type;
            typedef T mapped_type;
            typedef pair<const Key, T> value_type;
            typedef Compare key_compare;
            typedef Allocator allocator_type;
            typedef typename Allocator::reference reference;
            typedef typename Allocator::const_reference const_reference;
            // typedef implementation defined iterator; // See 23.1// to be defined by me;
            // typedef implementation defined const_iterator; // See 23.1 // same here;
            // typedef implementation defined size_type; // See 23.1// semae here;
            // typedef implementation defined difference_type;// See 23.1// same here;
            // typedef typename Allocator::pointer pointer;
            typedef typename Allocator::const_pointer const_pointer;
            //typedef std::reverse_iterator<iterator> reverse_iterator;// i think we should define our own rev_it instead of std::rev_it???
            //typedef std::reverse_iterator<const_iterator> const_reverse_iterator;//same here;
            typedef typename ft::avl_tree<value_type, key_compare, allocator_type>  tree_type;
            typedef     size_t size_type;
            // i think the last argument in the above typedef are not neccesserry so i will
            // test them when the test phase is reached;

            typedef class value_compare : public std::binary_function<value_type,value_type,bool> 
            {
                friend class map;
                protected:
                Compare comp;
                value_compare(Compare c) : comp(c) {}
                public:
                bool operator()(const value_type& x, const value_type& y) const 
                {
                    return comp(x.first, y.first);
                }
            } value_compare;

            // ****** CONSTRUCTORS********
            //empty (1)	
            explicit map (const key_compare& comp = key_compare(),
                        const allocator_type& alloc = allocator_type()):tree(),my_allocator(alloc), my_compare(comp),tree_size(0)
            {

            }
            //range (2)	
            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
            {
                // inputiterator isn't defined yet;
            }
            //copy (3)	
            map (const map& x)
            {
                this->my_allocator = x.my_allocator;
                this->my_compare = x.my_compare;
                this->tree = x.tree;
                this->tree_size = x.tree_size;
            }
            //********DESTRUCTOR****
            ~map()
            {
                //FROM CPLUSPLUS
                //This destroys all container elements, and deallocates all the storage
                //capacity allocated by the map container using its allocator.
            }
            map& operator= (const map& x)
            {
                // i may need to free something before doing thte below;
                // if(this->tree)
                // {
                //     free(tree)
                // }
                this->my_allocator = x.my_allocator;
                this->my_compare = x.my_compare;
                this->tree = x.tree;
                this->tree_size = x.tree_size;
                return(*this);              
            }
            //***********CAPACITY**********//
            bool empty() const
            {
                if(tree_size == 0)
                    return(true);
                else
                    return(false);
            }
            size_type size() const
            {
                return(tree_size);
            }

            size_type max_size() const
            {
                return(my_allocator.max_size());
            }





            private:
                    tree_type tree;
                    allocator_type  my_allocator;
                    key_compare     my_compare;
                    size_type       tree_size;
    };
}