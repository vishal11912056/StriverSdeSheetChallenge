/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
 bool bst(BinaryTreeNode<int>* root,long long int mn,long long int mx)
    {
        if(root==NULL)
        {
            return true;
        }
        if((mn > root->data)||(mx < root->data))
        {
            return false;
        }
        
        return (bst(root->left,mn,root->data) && bst(root->right,root->data,mx));
        
    }
bool validateBST(BinaryTreeNode<int> *root) 
{
     return bst(root,LLONG_MIN,LLONG_MAX);
    // Write your code here
}
