vector<int> getLeftView(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return {};
    }
    vector<int> v;
    queue<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty())
    {
        int sz=st.size();
        for(int i=0;i<sz;i++)
        {
            TreeNode<int> *curr= st.front();
            st.pop();
            if(i==0)
            {
                v.push_back(curr->data);
            }
            if(curr->left)
            {
                st.push(curr->left);
            }
            if(curr->right)
            {
                st.push(curr->right);
            }
        }
    }
    return v;
    //    Write your code here
}
