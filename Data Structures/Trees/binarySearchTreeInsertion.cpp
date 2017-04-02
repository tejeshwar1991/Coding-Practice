/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value)
{
   node *cur = root;  
   if (cur == NULL){
       node *temp = new node;
       temp->data = value;
       temp->left = temp->right = NULL;
       return temp;
   } 

    if (value < cur->data)
        cur->left  = insert(cur->left, value);
    else if (value > cur->data)
        cur->right = insert(cur->right, value);   

   return root;
}
