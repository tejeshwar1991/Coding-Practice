/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

int __cur1(int diff,Node *cur_headA, Node *cur_headB){
    int data = 0;
    
    while(diff){
        cur_headA = cur_headA->next;
        diff--;
    }
    
    while(cur_headA && cur_headB){
        if(cur_headA->data == cur_headB->data){
            data = cur_headA->data;
            break;
        }
        else{
            cur_headA = cur_headA->next;
            cur_headB = cur_headB->next;
        }
    }
    return data;
}
 
int __cur2(int diff,Node *cur_headA, Node *cur_headB){
    int data = 0;
    
    while(diff){
        cur_headB = cur_headB->next;
        diff--;
    }
    
    while(cur_headA && cur_headB){
        if(cur_headA->data == cur_headB->data){
            data = cur_headA->data;
            break;
        }
        else{
            cur_headA = cur_headA->next;
            cur_headB = cur_headB->next;
        }  
    }
    return data;  
}

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    
    Node *cur1 = headA;
    Node *cur2 = headB;
    int count = 0;
    int cur_len1 = 0;
    int cur_len2 = 0;
    int diff = 0;
    int merge_node_data = 0;
    
    while(cur1){
        count++;
        cur1 = cur1->next;
    }
    
    cur_len1 = count;
    count = 0;
    
    while(cur2){
        count++;
        cur2 = cur2->next;        
    }
    
    cur_len2 = count;
    count = 0;
    
    if(cur_len1>=cur_len2){
        diff = cur_len1 - cur_len2;
        merge_node_data = __cur1(diff,headA,headB);
    }
    else{
        diff = cur_len2 - cur_len1;        
        merge_node_data = __cur2(diff,headA,headB);
    }
    
    return merge_node_data;
}
