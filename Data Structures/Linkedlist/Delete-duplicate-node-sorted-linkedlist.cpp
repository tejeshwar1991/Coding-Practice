/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/


Node* RemoveDuplicates(Node *head)
{
    Node *t1 = head;
    Node *t2 = head->next;
 
    while(t2 != NULL){
        if(t1->data == t2->data){
            t2 = t2->next;
            free(t1->next);
            t1->next = t2;
        }
        else{
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    
    return head;    
}
