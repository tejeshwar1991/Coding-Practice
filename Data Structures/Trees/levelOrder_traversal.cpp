
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
#include<queue>


void LevelOrder(node * root)
{
    if(root == NULL) return;
    
    queue<node *> Q;
    
    Q.push(root);
    
    while(!Q.empty()){
        node *cur = Q.front();
        cout<<cur->data<<" ";
        if(cur->left != NULL) Q.push(cur->left);
        if(cur->right != NULL) Q.push(cur->right);
        Q.pop();
    }
}
