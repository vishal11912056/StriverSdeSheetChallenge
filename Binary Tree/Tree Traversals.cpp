#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> v(3);
    vector<int> pre,in,post;
    stack<pair<BinaryTreeNode<int>*,int>> st;
    st.push({root,1});
    if(root==NULL)
    {
        return v;
    }
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right)
            {
                st.push({it.first->right,1});
            }
        }
        else
        {
             post.push_back(it.first->data);
        }
    }
    v.push_back(in);
    v.push_back(pre);
    v.push_back(post);
    return v;
    // Write your code here.
}
