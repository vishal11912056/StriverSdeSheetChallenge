/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* constructTree(vector<int>& inorder,int instart,int inend,vector<int>& preorder,int prestart,int preend,unordered_map<int,int> &mp)
    {
        if(instart>inend || prestart>preend)
        {
            return NULL;
        }
        TreeNode<int>* root = new TreeNode<int>(preorder[prestart]);
        int elem = mp[root->data];
        int nelem = elem-instart; 
        root->left = constructTree(inorder,instart,elem-1,preorder,prestart+1,prestart+nelem,mp);
        root->right = constructTree(inorder,elem+1,inend,preorder,prestart+nelem+1,preend,mp);
        
        return root;
    }
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
     int instart=0,inend=inorder.size()-1;
        int prestart=0, preend=preorder.size()-1;
        
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return constructTree(inorder,instart,inend,preorder,prestart,preend,mp);
	//    Write your code here
}
