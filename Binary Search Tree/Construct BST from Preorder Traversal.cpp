/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* bstform_1(vector<int>& preOrder,int &preindex,int &n,int srt,int end)
{
        if(preindex>=n)
        {
            return NULL;
        }
    int curr=preOrder[preindex];
    if(curr>srt && curr<end)
    {
        TreeNode<int> *root= new TreeNode<int>(curr);
    
        preindex++;
        if(preindex<n)
        {
            root->left = bstform_1(preOrder,preindex,n,srt,curr);
        }
        if(preindex<n)
        {
            root->right = bstform_1(preOrder,preindex,n,curr,end);
        }
        
        return root;
    }
    return NULL;
}
// TreeNode<int>* bstform(int srt,int end,vector<int>& preorder,vector<int>& v)
//     {
//         if(srt>end)
//         {
//             return NULL;
//         }
//         TreeNode<int> *root= new TreeNode<int>(preorder[srt]);
//         root->left = bstform(srt+1,v[srt]-1,preorder,v);
//         root->right = bstform(v[srt],end,preorder,v);
        
//         return root;
//     }
TreeNode<int>* preOrderTree(vector<int> &preOrder)
{
        int n=preOrder.size();
//         vector<int> v(n);
//         stack<int> st;
//         for(int i=preOrder.size()-1;i>=0;i--)
//         {
//              while(!st.empty() && preOrder[i]>=preOrder[st.top()])
//              {
//                  st.pop();
//              }
//             if(st.empty())
//             {
//                 v[i]=n;
//             }
//             else
//             {
//                 v[i]=st.top();
//             }
//             st.push(i);
//         }
//         return bstform(0,n-1,preOrder,v);
    int preindex=0;
    return bstform_1(preOrder,preindex,n,INT_MIN,INT_MAX);
    // Write your code here.
}
