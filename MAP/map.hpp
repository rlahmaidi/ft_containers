#pragma once
#include <iostream>
#include "../utils/pair.hpp"
#include "../iterators/random_access_iterator.hpp" // i think we should define a bidir now;
#include "../iterators/iterator_traits.hpp"
#include "avl_test.hpp"
#include "../iterators/bidirectionell_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"



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
            typedef ft::pair<const Key, T> value_type;
            typedef Compare key_compare;
            typedef Allocator allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename ft::avl_tree<value_type, key_compare, allocator_type>  tree_type;
            typedef typename ft::node<value_type,allocator_type>     node_type;
            //typedef ft::node<value_type, allocator_type>    node_type;


            typedef tree_iterator<value_type, node_type *>     iterator; // See 23.1// to 
            typedef tree_iterator<const value_type, node_type *>    const_iterator; // 
    
             typedef  ptrdiff_t  difference_type;// See 23.1// same here;
             typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef  ft::reverse_iterator<iterator> reverse_iterator;// remove ft and test???
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;//same here;
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
                return(tree.size());
            }

            size_type max_size() const
            {
                return(my_allocator.max_size());
            }

            //*************  ITERATORS *****
            iterator begin()
            {
                node_type *temp = tree.find_min();
                iterator tmp(temp, tree._root);
                return(tmp);

            }
            const_iterator begin() const
            {
                const_iterator tmp(tree.find_min(), tree._root);
                return(tmp);
            }
            iterator end()
            {
                iterator    tmp(NULL, tree._root);
                return(tmp);
            }

            const_iterator end() const
            {
                const_iterator    tmp(NULL, tree._root);
                return(tmp);
            }

            reverse_iterator rbegin()
            {
                reverse_iterator tmp(end());
                return(tmp);
            }

            const_reverse_iterator rbegin() const
            {
                const_reverse_iterator tmp(end());
                return(tmp);
            }
            reverse_iterator rend()
            {
                reverse_iterator tmp(NULL);
                return(tmp);
            }

            const_reverse_iterator rend() const
            {
                const_reverse_iterator tmp(NULL);
                return(tmp);
            }

            mapped_type& operator[] (const key_type& k)
            {
                mapped_type *tmp = tree.search_second(k);
                if(tmp == NULL)
                {
                    //insert(k) and construct second  with default const of second;
                }
                return(*tmp);
            }
            //********** MODIFIERS ******
            //single element (1)	
            pair<iterator,bool> insert (const value_type& val)
            {
               // pair<iterator, bool> to_return;
               iterator tmp_it ;
               bool     inserted_or_not;
                node_type   *tmp_node;
                
                tmp_node = tree.search(val.first) ;
                if(tmp_node != NULL)
                {
                    tmp_it = iterator(tmp_node, tree._root);
                    // to_return.second = false;
                     inserted_or_not = false;
                }
                else
                {
                    tmp_node = tree.insert(val);
                    tmp_it = iterator(tmp_node,tree._root);
                    // to_return.second = true;
                    inserted_or_not = true;
                }
                return(pair<iterator, bool>(tmp_it, inserted_or_not));

            }
            //with hint (2)	
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                iterator tmp_it ;
                node_type   *tmp_node;
                
                tmp_node = tree.search(val.first) ;
                if(tmp_node != NULL)
                {
                    tmp_it = iterator(tmp_node, tree._root);

                }
                else
                {
                    tmp_node = tree.insert(val);
                    tmp_it = iterator(tmp_node,tree._root);
                }
                return(tmp_it);               
            }
            //range (3)	
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    insert(*first);
                    ++last;
                }
            }



            private:
                    tree_type tree;
                    allocator_type  my_allocator;
                    key_compare     my_compare;
                    size_type       tree_size;
    };
}