/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
    Node *cur_headA = headA;
    Node *cur_headB = headB;
     
    while(cur_headA != NULL && cur_headB != NULL){
        if(cur_headA->data == cur_headB->data){
            cur_headA = cur_headA->next;
            cur_headB = cur_headB->next;
        }
        else
            return 0;
    }
    if(cur_headA == NULL && cur_headB == NULL)
        return 1;
    else
        return 0;
}
