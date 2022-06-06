/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
 int maxSum(TreeNode<int>* root,int &maxi)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return root->val;
        }
        int lh = maxSum(root->left,maxi);
        int rh = maxSum(root->right,maxi);
        
        if(root->left && root->right)
        {
            maxi = max(maxi,lh+rh+root->val);
            return max(lh,rh)+root->val;
        }
        if(!root->left)
        {
            return rh+root->val;
        }
        if(!root->right)
        {
            return lh+root->val;
        }
    }
long long int findMaxSumPath(TreeNode<int> *root)
{
       int maxi= INT_MIN;
      maxSum(root,maxi);
        if(maxi==INT_MIN)
        {
          return -1;
        }
        return maxi;
    // Write your code here.
}
