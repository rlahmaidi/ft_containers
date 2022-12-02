#pragma once
#include <iostream>
#include <signal.h>
#include "../MAP/avl_tree.hpp"
namespace ft
{
        template <typename _value_type, typename node_type>
        struct tree_iterator 
        {
            typedef _value_type value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
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
            operator tree_iterator<const value_type, node_type>() const
            {
                return tree_iterator<const value_type, node_type>(_node, _root);  
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
                    return(true);
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
            pointer operator->() const
            {
                return(&(_node->data));
            }

          
            tree_iterator& operator++()
            {
              if (_node == NULL)
                  {
                    raise(SIGSEGV);
                    // _node = tree->root;
                    // if (_node == NULL)
                    //   throw UnderflowException { };
                    
                    // // move to the smallest value in the tree,
                    // // which is the first node inorder
                    // while (_node->left != NULL) {
                    //   _node = _node->left;
                    // }
                  }
                else
                  if (_node->right != NULL)
                    {
                      // successor is the farthest left node of
                      // right subtree
                      _node = _node->right;
                      
                      while (_node->left != NULL) {
                        _node = _node->left;
                      }
                    }
                  else
                    {
                      // have already processed the left subtree, and
                      // there is no right subtree. move up the tree,
                      // looking for a parent for which _node is a left child,
                      // stopping if the parent becomes NULL. a non-NULL parent
                      // is the successor. if parent is NULL, the original node
                      // was the last node inorder, and its successor
                      // is the end of the list
                      node_type p = _node->parent;
                      while (p != NULL && _node == p->right)
                        {
                          _node = p;
                          p = p->parent;// i think i f a node dosen't have any right parent this won't return
                                        // a NULL(case of C in the doc ), i shouold test it;
                        }
                      
                      // if we were previously at the right-most node in
                      // the tree, _node = NULL, and the iterator specifies
                      // the end of the list
                      _node = p;
                    }
                
                return *this;
            }

            tree_iterator operator++(int)
            {
              tree_iterator tmp (*this);
              ++(*this);
              return(tmp);
            }

            tree_iterator& operator--()
            {
              if(_node == NULL)
              {
                _node = _root;
                  _node = max_of_root(_root);
                 
              }
              else
              {
                if(_node->left != NULL)
                {
                  _node = _node->left;
                  while(_node->right != NULL)
                  {
                    _node = _node->right;
                  }
                }
                else
                {
                  node_type p = _node->parent;
                  while(p != NULL && _node == p->left)
                  {
                    _node = p;
                    p = _node->parent;
                  }
                  _node = p; 
                }
              }
              return(*this);
            }

            tree_iterator operator--(int)
            {
              tree_iterator tmp(*this);
              --(*this);
              return(tmp);
            }

            node_type   getNode(void) const
            {
                return(_node);
            }

            private:
                    //const tree::node_type *node;
                    node_type		    _node;
			              node_type			_root;

                    node_type max_of_root(node_type root)
                    {
                      node_type tmp = root;
                      if(tmp == NULL)
                        return(NULL);
                      while( tmp != NULL && tmp->right != NULL )
                        tmp = tmp->right;
                      return(tmp);
                    }
         };
}

// template < typename Value_type, typename node_type>
//     class bidirectional_iterator
// template <class Comparable>
// typename BinarySearchTree<Comparable>::BstIterator&
// BinarySearchTree<Comparable>::BstIterator::operator++ ()
// {
//   BinaryNode<Comparable> *p;
  
//   if (_node == NULL)
//     {
//       // ++ from end(). get the root of the tree
//       _node = tree->root;
      
//       // error! ++ requested for an empty tree
//       if (_node == NULL)
//         throw UnderflowException { };
      
//       // move to the smallest value in the tree,
//       // which is the first node inorder
//       while (_node->left != NULL) {
//         _node = _node->left;
//       }
//     }
//   else
//     if (_node->right != NULL)
//       {
//         // successor is the farthest left node of
//         // right subtree
//         _node = _node->right;
        
//         while (_node->left != NULL) {
//           _node = _node->left;
//         }
//       }
//     else
//       {
//         // have already processed the left subtree, and
//         // there is no right subtree. move up the tree,
//         // looking for a parent for which _node is a left child,
//         // stopping if the parent becomes NULL. a non-NULL parent
//         // is the successor. if parent is NULL, the original node
//         // was the last node inorder, and its successor
//         // is the end of the list
//         p = _node->parent;
//         while (p != NULL && _node == p->right)
//           {
//             _node = p;
//             p = p->parent;
//           }
        
//         // if we were previously at the right-most node in
//         // the tree, _node = NULL, and the iterator specifies
//         // the end of the list
//         _node = p;
//       }
  
//   return *this;
// }