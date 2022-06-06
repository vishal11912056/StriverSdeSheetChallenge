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
string serializeTree(TreeNode<int> *root)
{
    if(!root) return "";
        
        string str="";
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            if(tmp==NULL)
            {
                str+="#,";
            }
            else
            {
                str+=(to_string(tmp->data)+',');
            }
            if(tmp)
            {
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return str;
 //    Write your code here for serializing the tree

}

TreeNode<int>* deserializeTree(string &serialized)
{
     if(serialized.size()==0)
        {
            return NULL;
        }
        stringstream s(serialized);
        string str;
        getline(s,str,',');
        TreeNode<int>* root= new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty())
        {
            auto tmp=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#")
            {
                tmp->left=NULL;
            }
            else
            {
                 TreeNode<int>* left= new TreeNode<int>(stoi(str));
                tmp->left=left;
                q.push(left);
            }
            
            
            
             getline(s,str,',');
            if(str=="#")
            {
                tmp->right=NULL;
            }
            else
            {
                 TreeNode<int>* right= new TreeNode<int>(stoi(str));
                tmp->right=right;
                q.push(right);
            }
        }
        return root;
 //    Write your code here for deserializing the tree

}



