bool isSame(BinaryTreeNode<int>* p,BinaryTreeNode<int>* q)
{
    if(p==NULL || q==NULL)
    {
        return p==q;
    }
    if(p->data==q->data)
    {
        return (isSame(p->left,q->right)&isSame(p->right,q->left));
    }
    return false;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return true;
    }
    return isSame(root->left,root->right);
    // Write your code here.    
}
