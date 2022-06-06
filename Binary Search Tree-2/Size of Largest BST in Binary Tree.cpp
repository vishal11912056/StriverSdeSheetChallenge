/************************************************************

    Following is the Binary Tree node structure
    
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
class NodeValue
{
    public:
    int minNode,maxNode,maxSize;
    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSize=maxSize;
    }
};
NodeValue BSTlarge(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return NodeValue(INT_MAX,INT_MIN,0);
    }
    auto left= BSTlarge(root->left);
    auto right= BSTlarge(root->right);
    
    if(left.maxNode<root->data && right.minNode>root->data)
    {
        return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    
}
int largestBST(TreeNode<int>* root) 
{
    return BSTlarge(root).maxSize;
    
    // Write your code here.
}
