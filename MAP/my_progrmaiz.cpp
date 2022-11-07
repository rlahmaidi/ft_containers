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

}