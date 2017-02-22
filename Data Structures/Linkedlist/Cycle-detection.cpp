/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    Node *slowptr = head;
    Node *fastptr = head->next->next;
    
    if(head->next == NULL){ 
        return false;
    }
    else if(head == NULL) return NULL;
    else{
        while(fastptr != NULL){
            if(fastptr->next == slowptr)
                return true;
            else{
                fastptr = fastptr->next->next;                
                slowptr = slowptr->next;
            }
        }
        return false;    
    }     
}
