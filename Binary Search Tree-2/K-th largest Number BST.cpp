/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void reverse_inorder(TreeNode<int> *root, int &k,int &s)
    {
        if(root==NULL)
        {
            return;
        }
        reverse_inorder(root->right,k,s);
        k--;
        if(k==0)
        {
            s=root->data;
            return;
        }
        reverse_inorder(root->left,k,s);
    }

 int inorder(TreeNode<int>* root, int k,int &cnt)
    {
        stack<TreeNode<int>*> st;
        TreeNode<int>* curr=root;
        while(true)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->right;
            }
            else
            {
                if(st.empty())
                {
                    break;
                }
                curr=st.top();
                cnt--;
                if(cnt==0)
                {
                    return curr->data;
                }
                st.pop();
                curr=curr->left;
            }
        }
        return -1;
       
    }
int KthLargestNumber(TreeNode<int>* root, int k) 
{
     int cnt=k;
//   int s=-1;
      return inorder(root,k,cnt);
        
//         return s;
    // Write your code here.
}
