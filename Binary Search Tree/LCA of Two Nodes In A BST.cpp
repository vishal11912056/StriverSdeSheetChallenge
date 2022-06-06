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
  TreeNode<int>* dfs(TreeNode<int>* root, int p, int q)
    {
          if(root==NULL)
          {
              return NULL;
          }
        if(root->data <p && root->data<q )
        {
            return dfs(root->right,p,q);
        }
       else if(root->data >p && root->data>q )
        {
            return dfs(root->left,p,q);
        }
        return root;
    }
// void lca(TreeNode<int>* root , int &x,vector<TreeNode<int>*> &v)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
//         v.push_back(root);
//         if(root->data==x)
//         {
//             return;
//         }
//         if(x>root->data)
//         {
//             lca(root->right,x,v);
//         }
//         else
//         {
//             lca(root->left,x,v);
//         }
//     }
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
//      vector<TreeNode<int>*> v1,v2;
//         int x=P->data;
//         int y=Q->data;
        
//         if(root==NULL)
//         {
//             return NULL;
//         }
//         lca(root,x,v1);
//         lca(root,y,v2);
//         int i;
//         for(i=0;i<v1.size() && i<v2.size();i++)
//         {
//             if(v1[i]->data!=v2[i]->data)
//             {
//                 break;
//             }
//         }
//         return v1[i-1];
    int x=P->data;
    int y=Q->data;
        return dfs(root,x,y);
	// Write your code here
}
