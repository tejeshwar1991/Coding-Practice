/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    
    Node *cur = head;
    Node *temp = NULL;
    
    if(cur == NULL)
        return NULL;
    
    while(cur){
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    
    if(temp != NULL)
        head = temp->prev;
    
    return head;
}
