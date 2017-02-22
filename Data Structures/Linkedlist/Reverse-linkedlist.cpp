/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node *cur = NULL;
    Node *temp = NULL;

    while(head != NULL){
        temp = head->next;
        head->next = cur;
        cur = head;
        head = temp;
    }
    return cur;
}
