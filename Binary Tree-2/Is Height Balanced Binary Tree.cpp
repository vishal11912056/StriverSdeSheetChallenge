int isBal(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l = isBal(root->left);
        if(l==-1)
        {
            return -1;
        }
        int r = isBal(root->right);
        if(r==-1)
        {
            return -1;
        }
        if(abs(l-r)>1)
        {
            return -1;
        }
        else
        {
            return max(l,r)+1;
        }
    }
bool isBalancedBT(BinaryTreeNode<int>* root) 
{
       if(isBal(root)==-1)
        {
            return false;
        }
        return true;
    // Write your code here.
}
