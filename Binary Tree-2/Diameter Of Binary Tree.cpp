int height(TreeNode<int> *root,int &diam)
{
       if(root==NULL)
        {
            return 0;
        }
        int lh= height(root->left,diam);
        int rh= height(root->right,diam);
        diam=max(diam,lh+rh);
        return max(lh,rh)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diam=0;
    height(root,diam);
      return diam;
	// Write Your Code Here.
}
