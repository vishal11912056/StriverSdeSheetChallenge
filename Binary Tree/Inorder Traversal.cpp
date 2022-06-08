void f(TreeNode *root,vector<int> &v)
{
    if(!root)
    {
        return;
    }
    f(root->left,v);
    v.push_back(root->data);
    f(root->right,v);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> v;
    f(root,v);
    return v;
}
