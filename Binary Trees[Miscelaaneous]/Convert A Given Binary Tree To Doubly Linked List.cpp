/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/
void BtoDll(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>* &prev)
{
    if(!root)
    {
        return;
    }
    BtoDll(root->left,head,prev);
    if(prev==NULL)
    {
        head=root;
    }   
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
        BtoDll(root->right,head,prev);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) 
{
    BinaryTreeNode<int>* head=NULL;
    BinaryTreeNode<int>* prev=NULL;
    BtoDll(root,head,prev);
    return head;
    // Write your code here
}
