/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{   
   Node *cur = head;
   Node *prev = head;
    
   Node *temp = (struct Node*)(malloc(sizeof(struct Node))); 
   temp->data = data;
   temp->next = NULL;
    
    if(head==NULL) return temp;
  
   while(cur->next!=NULL)
   {
       cur = cur->next;
   }
    cur->next = temp;
    return head;
}
