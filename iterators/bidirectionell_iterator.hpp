#include <iostream>
#include "../MAP/avl_test.hpp"
namespace ft
{
        template <typename value_type>
        struct tree_iterator 
        {
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::ptrdiff_t difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;

        // const tree::tree_node<T>* node; i made it private;
            tree_iterator() = default;
            tree_iterator(const tree::tree_node<T>* n);

            constexpr
            const T& operator*() const noexcept;
            tree_iterator& operator++();
            tree_iterator operator++(int);
            tree_iterator& operator--();
            tree_iterator operator--(int);


            private:
                    const tree::node_type *node;
        };
}

// template < typename Value_type, typename node_type>
//     class bidirectional_iterator