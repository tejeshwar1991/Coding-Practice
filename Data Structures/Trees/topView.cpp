/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_left(node *root)
{
    
    if(root == NULL)
        printf("EMPTY\n");
    else{                    
            if(root->left != NULL)
            { 
                top_left(root->left);
                printf("%d ",root->left->data);
            }          
    }
}
void top_right(node *root)
{
    if(root == NULL)
        printf("EMPTY\n");
    else {
        if(root->right!= NULL ){   
            printf("%d ",root->right->data);
            top_right(root->right);
        }
    }    
}
void top_view(node * root)
{
    top_left(root);
    printf("%d ",root->data);
    top_right(root);    
}
