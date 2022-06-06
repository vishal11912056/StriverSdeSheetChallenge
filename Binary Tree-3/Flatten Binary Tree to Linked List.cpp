void flatTree(TreeNode<int> *root,TreeNode<int>* &prev)
{
    if(root==NULL)
    {
        return ;
    }
    
    flatTree(root->right,prev);
    flatTree(root->left,prev);
    
    root->right=prev;
    root->left=NULL;
    
    prev=root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev=NULL;
     flatTree(root,prev);
    return root;
    // Write your code here.
}
