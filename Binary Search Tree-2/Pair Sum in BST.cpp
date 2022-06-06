/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
class BST_iterator
{
    stack<BinaryTreeNode<int> *> st;
     bool reverse=true;
public:
    
       BST_iterator(BinaryTreeNode<int> * root,bool isReverse)
       {
           reverse=isReverse;
           pushAll(root);
       }
    
    bool hasNext() 
    {
        if(!st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    int next()
    {
        BinaryTreeNode<int> * tmp =st.top();
        st.pop();
        if(reverse==true)
        {
            pushAll(tmp->left);
        }
        else
        {
            pushAll(tmp->right);
        }
        return tmp->data;
    }
    private:
    void pushAll(BinaryTreeNode<int> * root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(reverse==true)
            {
               root=root->right;
            }
            else
            {
                root=root->left;
            }
                
        }
    }
    
    
    
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(!root) return false;
        BST_iterator l(root,false);
        BST_iterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j)
        {
            if((i+j)==k)
            {
                return true;
            }
            else if((i+j)<k)
            {
                i=l.next();
            }
            else
            {
                j=r.next();
            }
        }
        return false;
    // Write your code here
}
