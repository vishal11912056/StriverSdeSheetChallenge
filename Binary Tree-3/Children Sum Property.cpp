/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void childTree(BinaryTreeNode < int > * root)
{
    if(root==NULL)
    {
        return;
    }
    int child=0;
    if(root->left)
    {
        child+=root->left->data;
    }
    if(root->right)
    {
        child+=root->right->data;
    }
    if(child<root->data)
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        else if(root->right)
        {
            root->right->data=root->data;
        }
    }
    childTree(root->left);
    childTree(root->right);
    
    int tot=0;
    if(root->left)
    {
        tot+=root->left->data;
    }
    if(root->right)
    {
        tot+=root->right->data;
    }
    if(root->left || root->right)
    {
        root->data=tot;
    }
}
void changeTree(BinaryTreeNode < int > * root) 
{
   childTree(root);
    return;  
    // Write your code here.
}  
