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
 int inorder(TreeNode<int>* root, int k,int &cnt)
    {
        stack<TreeNode<int>*> st;
        TreeNode<int>* curr=root;
        while(true)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                if(st.empty())
                {
                    break;
                }
                curr=st.top();
                cnt++;
                if(cnt==k)
                {
                    return curr->data;
                }
                st.pop();
                curr=curr->right;
            }
        }
        return 0;
       
    }
int kthSmallest(TreeNode<int> *root, int k)
{
     int cnt=0;
//         int s=-1;
     return inorder(root,k,cnt);
	//	Write the code here.
}
