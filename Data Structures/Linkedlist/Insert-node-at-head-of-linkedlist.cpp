/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
    Node *temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->data = data;
    
    Node *cur = head;
    if(cur == NULL)
        temp->next = NULL;
    else
        temp->next = head;

    head = temp;
    return head;
}