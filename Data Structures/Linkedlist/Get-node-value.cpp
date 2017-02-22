/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int count = 1;
int len = 0;
int GetNode(Node *head,int positionFromTail)
{
    
    Node *cur = head;
    while(cur != NULL){
        ++len;
        cur = cur->next;
    }
        
    int position = len - positionFromTail;
    //cout<<"len:"<<len<<"positionFromTail:"<<positionFromTail<<"position:"<<position<<endl;
    cur = head;
    
    while(count != position){
        ++count;
        cur = cur->next;
        if(count == position)
        {
            break;   
        }
    }
    len = 0; position = 0; count = 1;
    return cur->data; 
}
