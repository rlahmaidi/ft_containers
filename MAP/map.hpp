#pragma once
#include <iostream>
#include "../UTILS/pair.hpp"
#include "../ITERATORS/random_access_iterator.hpp" // i think we should define a bidir now;
#include "../ITERATORS/iterator_traits.hpp"
#include "avl_test.hpp"
#include "../ITERATORS/bidirectionell_iterator.hpp"
#include "../ITERATORS/reverse_iterator.hpp"
#include "../UTILS/equal_lexecographi.hpp"
#include "../VECTOR/vector.hpp"

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
        typedef typename ft::avl_tree<value_type, key_compare, allocator_type> tree_type;
        typedef typename ft::node<value_type, allocator_type> node_type;
        // typedef ft::node<value_type, allocator_type>    node_type;

        typedef tree_iterator<value_type, node_type *> iterator;             // See 23.1// to
        typedef tree_iterator<const value_type, node_type *> const_iterator; //

        typedef ptrdiff_t difference_type; // See 23.1// same here;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;             // remove ft and test???
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; // same here;
        typedef size_t size_type;
        // i think the last argument in the above typedef are not neccesserry so i will
        // test them when the test phase is reached;

        typedef class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        } value_compare;

        // ****** CONSTRUCTORS********
        // empty (1)
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : tree(), my_allocator(alloc), my_compare(comp)
        {
        }
        // range (2)
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : tree(), my_allocator(alloc), my_compare(comp)
        {
            while (first != last)
            {
                tree.insert(*first);
                ++first;
            }
        }
        // copy (3)
        map(const map &x)
        {
            this->my_allocator = x.my_allocator;
            this->my_compare = x.my_compare;
            this->tree = x.tree;
            // this->tree_size = x.tree_size;
        }
        //********DESTRUCTOR****
        ~map()
        {
            // FROM CPLUSPLUS
            // This destroys all container elements, and deallocates all the storage
            // capacity allocated by the map container using its allocator.
            this->tree.clear();
        }
        map &operator=(const map &x)
        {
            // i may need to free something before doing the below;
            // if(this->tree)
            // {
            //     free(tree)
            // }
            this->tree.clear();
            this->my_allocator = x.my_allocator;
            this->my_compare = x.my_compare;
            this->tree = x.tree;
            // this->tree_size = x.tree_size;
            return (*this);
        }
        //***********CAPACITY**********//
        bool empty() const
        {
            if (tree.size() == 0)
                return (true);
            else
                return (false);
        }
        size_type size() const
        {
            return (tree.size());
        }

        size_type max_size() const
        {
            return (my_allocator.max_size());
        }

        //*************  ITERATORS *****
        iterator begin()
        {
            node_type *temp = tree.find_min();
            iterator tmp(temp, tree._root);
            return (tmp);
        }
        const_iterator begin() const
        {
            const_iterator tmp(tree.find_min(), tree._root);
            return (tmp);
        }
        iterator end()
        {
            iterator tmp(NULL, tree._root);
            return (tmp);
        }

        const_iterator end() const
        {
            const_iterator tmp(NULL, tree._root);
            return (tmp);
        }

        reverse_iterator rbegin()
        {
            reverse_iterator tmp(end());
            return (tmp);
        }

        const_reverse_iterator rbegin() const
        {
            const_reverse_iterator tmp(end());
            return (tmp);
        }
        reverse_iterator rend()
        {
            reverse_iterator tmp(begin());
            return (tmp);
        }

        const_reverse_iterator rend() const
        {
            const_reverse_iterator tmp(begin());
            return (tmp);
        }

        mapped_type &operator[](const key_type &k)
        {

            value_type val(k, mapped_type());
            node_type *tmp_node = tree.insert(val);

            return (tmp_node->data.second);
        }
        //********** MODIFIERS ******
        // single element (1)
        pair<iterator, bool> insert(const value_type &val)
        {
            // pair<iterator, bool> to_return;
            iterator tmp_it;
            bool inserted_or_not;
            node_type *tmp_node;

            tmp_node = tree.search(val.first);
            if (tmp_node != NULL)
            {
                tmp_it = iterator(tmp_node, tree._root);
                // to_return.second = false;
                inserted_or_not = false;
            }
            else
            {
                tmp_node = tree.insert(val);
                tmp_it = iterator(tmp_node, tree._root);
                // to_return.second = true;
                inserted_or_not = true;
            }
            return (pair<iterator, bool>(tmp_it, inserted_or_not));
        }
        // with hint (2)
        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            iterator tmp_it;
            node_type *tmp_node;

            tmp_node = tree.search(val.first);
            if (tmp_node != NULL)
            {
                tmp_it = iterator(tmp_node, tree._root);
            }
            else
            {
                tmp_node = tree.insert(val);
                tmp_it = iterator(tmp_node, tree._root);
            }
            return (tmp_it);
        }
        // range (3)
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                // tree.insert(*first);
                insert(*first);
                ++first;
            }
        }
        //(1)
        void erase(iterator position)
        {
            tree.delete_(position.getNode()->data.first);
        }

        //(2)
        size_type erase(const key_type &k)
        {
            return (tree.delete_(k));
        }

        // (3)
        // void erase (iterator first, iterator last)
        // {
        //     (void)first;
        //     (void)last;
        //     //  size_type i = 0;
        //     // // iterator tmp = first;

        //     // while(first != last)
        //     // {
        //     //     //++tmp;
        //     //     erase(first);
        //     //     std::cout << "for the " << i << " time " << std::endl;
        //     //     ++first;
        //     //     i++;
        //     // }
        // }
        void erase(iterator first, iterator last)
        {
            ft::Vector<key_type> v;
            while (first != last)
            {
                // erase(first);
                v.push_back(first->first);
                ++first;
            }
            for (size_t i = 0; i < v.size(); i++)
                erase(v[i]);
        }

        void swap(map &x) // All iterators, references and pointers remain valid for the swapped objects.
        {
            tree.swap(x.tree);
        }

        void clear()
        {
            tree.clear();
        }
        //************* Observers *********

        key_compare key_comp() const
        {
            return (my_compare);
        }
        value_compare value_comp() const
        {
            return (value_compare(my_compare));
        }

        //*********** Operations ********
        iterator find(const key_type &k)
        {
            node_type *tmp_node = tree.search(k);
            return (iterator(tmp_node, tree._root));
        }

        const_iterator find(const key_type &k) const
        {
            node_type *tmp_node = tree.search(k);
            return (const_iterator(tmp_node, tree._root));
        }

        size_type count(const key_type &k) const
        {
            if (tree.search(k) != NULL)
                return (1);
            else
                return (0);
        }
        iterator lower_bound(const key_type &k)
        {
            node_type *tmp_node = tree.lower_bound(k);
            return (iterator(tmp_node, tree._root));
        }

        const_iterator lower_bound(const key_type &k) const
        {
            node_type *tmp_node = tree.lower_bound(k);
            return (const_iterator(tmp_node, tree._root));
        }

        iterator upper_bound(const key_type &k)
        {
            node_type *tmp_node = tree.upper_bound(k);
            return (iterator(tmp_node, tree._root));
        }

        const_iterator upper_bound(const key_type &k) const
        {
            node_type *tmp_node = tree.upper_bound(k);
            return (const_iterator(tmp_node, tree._root));
        }

        pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        { // to remember:(from cplusplus) Because the elements in a map container have unique keys, the
            // ange returned will contain a single element at most.
            //  yet their equal_range return two iterators, on to the upper bound and the
            //  other to lower bound
            pair<const_iterator, const_iterator> ret;
            ret.first = lower_bound(k) /*find(k)*/;
            ret.second = upper_bound(k) /*find(k)*/;
            return (ret);
        }

        pair<iterator, iterator> equal_range(const key_type &k)
        {
            pair<iterator, iterator> ret;
            ret.first = lower_bound(k);  // find(k);
            ret.second = upper_bound(k); // find(k);
            return (ret);
        }
        allocator_type get_allocator() const
        {
            return (my_allocator);
        }

    private:
        tree_type tree;
        allocator_type my_allocator;
        key_compare my_compare;
        // size_type       tree_size;
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    //(1)
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs) /*equal(lhs.begin(),lhs.end(), rhs.begin())*/);
    }
    // (2)	(until C++20)
    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
                   const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    //(3)	(until C++20)
    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs < rhs || lhs == rhs)
            return (true);
        return (false);
    }
    //(4)	(until C++20)
    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
                   const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        // return(ft::lexicographical_compare(rhs.begin(),rhs.end(),lhs.begin(),lhs.end()));
        if ((lhs < rhs) || (lhs == rhs))
            return (false);
        return (true);
        // return(lhs < rhs);
    }
    //(5)	(until C++20)
    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs > rhs || lhs == rhs)
            return (true);
        return (false);
    }
}