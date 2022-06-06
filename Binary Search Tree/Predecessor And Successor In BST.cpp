/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if(root==NULL)
   {
       return {-1,-1};
   }
   BinaryTreeNode<int>* tmp=root;
   int suc=-1;
   int pre=-1;
   while(root!=NULL)
   {
       if(root->data<=key)
       {
           root=root->right;
       }
       else
       {
           suc=root->data;
           root=root->left;
       }
   }
   root=tmp;
    while(root!=NULL)
   {
       if(root->data>=key)
       {
           root=root->left;
       }
       else
       {
           pre=root->data;
           root=root->right;
       }
   }
  return {pre,suc};
    // Write your code here.
}
