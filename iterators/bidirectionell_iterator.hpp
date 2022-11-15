#include <iostream>
#include "../MAP/avl_test.hpp"
namespace ft
{
        template <typename value_type, typename node_type>
        struct tree_iterator 
        {
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::ptrdiff_t difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;

        // const tree::tree_node<T>* node; i made it private;
            tree_iterator():_node(),_root()
            {

            }
            tree_iterator(node_type node, node_type root):_node(node),_root(root)
            {

            }

            tree_iterator(const tree_iterator& other)
            {
                this->_node = other._node;
                this->_root = other._root;
            }
            const tree_iterator& operator=(const tree_iterator& other)
            {
                this->_node = other._node;
                this->_root = other._root;
                return(*this);
            }
            bool operator ==(const tree_iterator &other) const
            {
                if(this->_node == other._node)
                    reuturn(true);
                else
                    return(false);
            }
            bool operator !=(const tree_iterator &other) const
            {
                if(this->_node != other._node)
                    return(true);
                else
                    return(false);
            }
            reference operator*() const
            {
                return (_node->data);
            }
            pointer operator->()
            {
                return(&(_node->data));
            }

          
            tree_iterator& operator++()
            {

            }

            tree_iterator operator++(int)
            {

            }

            tree_iterator& operator--()
            {

            }

            tree_iterator operator--(int)
            {

            }


            private:
                    const tree::node_type *node;
                    node_type		    _node;
			        node_type			_root;
        };
}

// template < typename Value_type, typename node_type>
//     class bidirectional_iterator
template <class Comparable>
typename BinarySearchTree<Comparable>::BstIterator&
BinarySearchTree<Comparable>::BstIterator::operator++ ()
{
  BinaryNode<Comparable> *p;
  
  if (nodePtr == nullptr)
    {
      // ++ from end(). get the root of the tree
      nodePtr = tree->root;
      
      // error! ++ requested for an empty tree
      if (nodePtr == nullptr)
        throw UnderflowException { };
      
      // move to the smallest value in the tree,
      // which is the first node inorder
      while (nodePtr->left != nullptr) {
        nodePtr = nodePtr->left;
      }
    }
  else
    if (nodePtr->right != nullptr)
      {
        // successor is the farthest left node of
        // right subtree
        nodePtr = nodePtr->right;
        
        while (nodePtr->left != nullptr) {
          nodePtr = nodePtr->left;
        }
      }
    else
      {
        // have already processed the left subtree, and
        // there is no right subtree. move up the tree,
        // looking for a parent for which nodePtr is a left child,
        // stopping if the parent becomes NULL. a non-NULL parent
        // is the successor. if parent is NULL, the original node
        // was the last node inorder, and its successor
        // is the end of the list
        p = nodePtr->parent;
        while (p != nullptr && nodePtr == p->right)
          {
            nodePtr = p;
            p = p->parent;
          }
        
        // if we were previously at the right-most node in
        // the tree, nodePtr = nullptr, and the iterator specifies
        // the end of the list
        nodePtr = p;
      }
  
  return *this;
}