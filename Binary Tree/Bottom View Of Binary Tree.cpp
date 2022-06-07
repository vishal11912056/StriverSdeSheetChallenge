vector<int> bottomView(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    {
        return {};
    }
    vector<int> v;
    int hd=0;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,hd});
    map<int,int> m;
    while(!q.empty())
    {
        auto tmp= q.front();
        q.pop();
        hd=tmp.second;
        auto curr=tmp.first;
         m[hd]=curr->data;
        if(curr->left)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right)
        {
            q.push({curr->right,hd+1});
        }
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
        v.push_back(i->second);
    }
    return v;
    // Write your code here.
    
}
