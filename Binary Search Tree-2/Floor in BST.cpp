
int floorInBST(TreeNode<int> * root, int X)
{
    int suc=-1;
    while(root!=NULL)
    {
        if(root->val>X)
        {
            root=root->left;
        }
        else
        {
            suc=root->val;
            root=root->right;
        }
    }
    return suc;
}
