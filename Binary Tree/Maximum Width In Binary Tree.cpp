int getMaxWidth(TreeNode<int> *root)
{
     if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            ans= max(ans,sz);
            for(int i=0;i<sz;i++)
            {
                TreeNode<int>* tmp=q.front();
               
                q.pop();
                
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
        }
        return ans;
         
    // Write your code here.
}
