TreeNode<int>* dfs(TreeNode<int>* root, int p, int q)
    {
        if(root==NULL || root->data==p || root->data==q)
        {
            return root;
        }
        
        TreeNode<int>* lft= dfs(root->left,p,q);
        TreeNode<int>* rght= dfs(root->right,p,q);
        
        if(lft==NULL)
        {
            return rght;
        }
        else if(rght==NULL)
        {
            return lft;
        }
        else
        {
            return root;
        }

    }
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    return (dfs(root,x,y))->data;
	//    Write your code here
}
