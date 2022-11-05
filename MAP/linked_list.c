#include <stdio.h>
#include <stdlib.h>
// void insert_node(int item);

//     void inorder(bintree_node *);
//     void postorder_seq();
//     void postorder(bintree_node *);

//     void preorder(bintree_node *);

typedef struct s_node 
{
    int data;
    struct s_node *next;
} Node;

void    insertAtEnd(Node **head,int a)
{
    Node    *head_tmp = *head;
    Node *tmp= malloc(sizeof(Node));
    tmp->data = a;
    tmp->next = NULL;
    if(head_tmp == NULL)
        head_tmp = tmp;
    else
        {
            
        }
   // head_tmp->next = tmp;
}
int main() 
{
   Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList(&head);
  printf("\nSorted List: ");
  printList(head);
}