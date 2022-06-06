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
class BSTiterator
{
    private: 
    stack<TreeNode<int>*> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
        // write your code here
    }

    int next()
    {
         TreeNode<int>* tmp =st.top();
        st.pop();
        if(tmp->right)
        {
            pushAll(tmp->right);
        }
        return tmp->data;
        // write your code here
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
        // write your code here
    }
     private:
    void pushAll(TreeNode<int>* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
