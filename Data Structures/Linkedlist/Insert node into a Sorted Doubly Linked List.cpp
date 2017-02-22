/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node *cur = head;
    Node *temp = new Node; 
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    
    if(!head){
        return temp;
    }
    
    else if(data < head->data){
        temp->next = cur;
        cur->prev = temp;        
        return temp;
    }
    else{ 
        while(cur->next != NULL){
            if(data < (cur->next)->data){
                temp->prev = cur;
                temp->next = cur->next;
                (cur->next)->prev = temp;
                cur->next = temp;
                return head;
            }
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
        return head;
    }
}
