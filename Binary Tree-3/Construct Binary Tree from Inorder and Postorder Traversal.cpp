/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* constructTree(vector<int>& inorder,int instart,int inend,vector<int>& postOrder,int prestart,int preend,unordered_map<int,int> &mp)
    {
        if(instart>inend || prestart>preend)
        {
            return NULL;
        }
        TreeNode<int>* root = new TreeNode<int>(postOrder[preend]);
        int elem = mp[root->data];
        int nelem = elem-instart; 
        root->left = constructTree(inorder,instart,elem-1,postOrder,prestart,prestart+nelem-1,mp);
        root->right = constructTree(inorder,elem+1,inend,postOrder,prestart+nelem,preend-1,mp);
        
        return root;
    }
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     int instart=0,inend=inOrder.size()-1;
        int prestart=0, preend=postOrder.size()-1;
        
        unordered_map<int,int> mp;
        for(int i=0;i<inOrder.size();i++)
        {
            mp[inOrder[i]]=i;
        }
        return constructTree(inOrder,instart,inend,postOrder,prestart,preend,mp);
	// Write your code here.
}
