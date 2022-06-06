/************************************************************

    Following is the TreeNode class structure:

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
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    BinaryTreeNode<int> *root=node;
    int pre=-1;
    while(root!=NULL)
    {
        if(root->data<x)
        {
            root=root->right;
        }
        else
        {
            pre=root->data;
            root=root->left;
        }
    }
    return pre;
    // Write your code here.
}
