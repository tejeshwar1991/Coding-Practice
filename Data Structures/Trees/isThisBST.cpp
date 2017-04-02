/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

#include<vector>

vector<int> vec;

bool check_vec(vector<int> vec1, int size)
{
    int j =0;
    for(int i = 0;i < size-1; i++){
         j = i+1;
         if(vec1[i] < vec1[j])
             continue;
         else
             return false;
    }
    
    return true;
}

bool checkBST(Node* root) {
    
    if(root == NULL) return true;

    checkBST(root->left);
    vec.push_back(root->data);
    checkBST(root->right);
    
    int vec_size = vec.size(); 

    if(check_vec(vec,vec_size))
        return true; 
    else
        return false;
    
}
