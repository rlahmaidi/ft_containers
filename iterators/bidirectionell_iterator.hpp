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
                  }
                else
                  if (_node->right != NULL)
                    {
                      _node = _node->right;
                      
                      while (_node->left != NULL) {
                        _node = _node->left;
                      }
                    }
                  else
                    {
                      node_type p = _node->parent;
                      while (p != NULL && _node == p->right)
                        {
                          _node = p;
                          p = p->parent;
                        }
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

