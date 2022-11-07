#include <iostream>

typedef struct node
{
    int data;// may be changed into any class 
    int height;
    struct node *left;
    struct node *right;

} node;

class AVl
{
    public:
        node *root;
        AVl()
        {
            this->root = NULL;
        }
        ~AVL()
        {
            
        }
        node* insert(struct node *r,int data)
        {
            if(r == NULL)
            {
                node *tmp = new node;
                tmp->data = data;
                tmp->left = NULL;
                tmp->right = NULL;
                tmp->height = 1;
                return(tmp);
                // they implement it another way so , test...
            }
            else
            {
                if(r->data < data)
                {
                    insert(r->right, data);
                }
                else
                {
                    insert(r->left, data);
                }
                // i converte the above condition tom make sure
                // it donsen't matter were to put an equal node;
            }
            // balncing;
        }
        node    *deleteNode(node *p, int data)
        {
            
        }
};



int main(){

    AVL b;
    int c,x;

    do{
        std::cout<<"\n1.Display levelorder on newline";
        std::cout<<"\n2.Insert";
        std::cout<<"\n3.Delete\n";
        std::cout<<"\n0.Exit\n";
        std::cout<<"\nChoice: ";

        std::cin>>c;

        switch (c)
        {
        case 1:
            b.levelorder_newline();
            // to print the tree in level order
            break;
                  
        case 2:
            std::cout<<"\nEnter no. ";
            std::cin>>x;
            b.root = b.insert(b.root,x);
            break;
        
        case 3:
            std::cout<<"\nWhat to delete? ";
            std::cin>>x;
            b.root = b.deleteNode(b.root,x);
            break;
            
        case 0:
            break;
        }

     } while(c!=0);
  