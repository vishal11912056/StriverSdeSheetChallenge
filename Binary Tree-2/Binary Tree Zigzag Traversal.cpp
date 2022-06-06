/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
         vector<int> v;
    if(!root)
    {
        return v;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int lvl=0;
    while(!q.empty())
    {
        int n=q.size();
        if(lvl%2==0)
        {
        for(int i=0;i<n;i++)
        {
            auto tmp= q.front();
            v.push_back(tmp->data);
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
        else
        {
            vector<int> v1;
        for(int i=0;i<n;i++)
        {
            auto tmp= q.front();
            v1.push_back(tmp->data);
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
        reverse(v1.begin(),v1.end());
        for(int i=0;i<n;i++)
        {
            v.push_back(v1[i]);
        }
        } 
        lvl++;
    }
    return v;
    // Write your code here!
}
