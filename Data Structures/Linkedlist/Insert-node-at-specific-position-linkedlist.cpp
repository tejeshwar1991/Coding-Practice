/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head,int data, int position) 
{
    Node *ToBeInserted;

    // Allocating Memory
    ToBeInserted = new Node;
    ToBeInserted -> data = data;
    ToBeInserted -> next = NULL;

    // It might be our First Node in Linked List
    if(head == NULL) {
        return (head = ToBeInserted);
    } 
    
    // Node Might to be inserted At Head
    else if(position == 0) {
        ToBeInserted -> next = head;
        return (head = ToBeInserted);
    } 
    else {
       
        int DistFromHead = 1;
        Node *traverse = head;
        
        while(traverse != NULL) {
            if(DistFromHead == position) {
                ToBeInserted -> next = traverse -> next;
                traverse -> next = ToBeInserted;
            }
            traverse = traverse -> next;
            DistFromHead++;
        }
    }
        return head;
}