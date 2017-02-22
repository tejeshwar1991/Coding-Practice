/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    

    Node *t1 = headA;
    Node *t2 = headB;
    Node *t3 = new Node;
    Node *start =  t3;
    
   while(t1 && t2){
       if(t1->data < t2->data){
           t3->next = t1;
           t3 = t1;
           t1 = t1->next;
       }
       else{
           t3->next = t2;
           t3 = t2;
           t2 = t2->next;
       }
   }
    
    if(t1 == NULL){
        t3->next = t2;
    }
    else if(t2 == NULL){
        t3->next = t1;
    }
    
    start = start->next;
    return start;
}
