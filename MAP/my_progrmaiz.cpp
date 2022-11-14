#include <iostream>

class Node
{
    public:
        int key;
        Node *left;
        Node *right;
        int height;  
};

Node *newNode(int key)
{
    Node *node;
    node = new Node;
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;// why 1, it should be 0;
    return(node);
}

Node *insertNode(Node *node, int key)
{
    if(node == NULL)
        return(newNode(key));
    else if(key > node->key)
        insertNode(node->right, key);
    else if(key < node->key)
        insertNode(node->left, key);
    
}
Node *deleteNode(Node *root, int key)
{
    
}