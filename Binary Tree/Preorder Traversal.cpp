void f(TreeNode *root,vector<int> &v)
{
    if(!root)
    {
        return;
    }
    v.push_back(root->data);
    f(root->left,v);
    f(root->right,v);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
     vector<int> v;
    f(root,v);
    return v;
}
