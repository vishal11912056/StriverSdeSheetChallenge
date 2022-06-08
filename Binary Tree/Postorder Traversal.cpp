void f(TreeNode *root,vector<int> &v)
{
    if(!root)
    {
        return;
    }
    f(root->left,v);
    f(root->right,v);
     v.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> v;
    f(root,v);
    return v;
}
