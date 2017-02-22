/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{   
    Node *cur = head;
    Node *prev = NULL;
    int toBeDeleted = 0;
    
    if(cur->next == NULL){
           delete(cur);
           return (head = NULL);
    }
    else{
        while(cur->next != NULL)
        {
            if(position == 0)
            {
                head = cur->next;
                delete(cur);
                break;
            }
            else 
            {
                if(toBeDeleted == position)
                {
                    prev->next = cur->next;
                    delete(cur);
                    break;
                }
                toBeDeleted++;
                prev = cur;
                cur = cur->next;
            }
        }
        if(cur->next == NULL){
            prev->next = cur->next;
            delete(cur);
            
        }
    }
    return head;
}
