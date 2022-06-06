/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* root)
{
    return (!root->left && !root->right);
}
void leftNodes(TreeNode<int>* root,vector<int> &v)
{
    TreeNode<int>* curr= root->left;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            v.push_back(curr->data);
        }
        if(curr->left)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
}
void rightNodes(TreeNode<int>* root,vector<int> &v)
{
    TreeNode<int>* curr= root->right;
    vector<int> tmp;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            tmp.push_back(curr->data);
        }
        if(curr->right)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }
    for(int i=tmp.size()-1;i>=0;i--)
    {
        v.push_back(tmp[i]);
    }
}
void Leaves(TreeNode<int>* root,vector<int> &v)
{
    if(isLeaf(root))
    {
        v.push_back(root->data);
        return;
    }
    if(root->left)
    {
        Leaves(root->left,v);
    }
    if(root->right)
    {
        Leaves(root->right,v);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int> v;
    if(!root)
    {
        return v;
    }
    if(!isLeaf(root))
    {
        v.push_back(root->data);
    }
    leftNodes(root,v);
    Leaves(root,v);
    rightNodes(root,v);
    return v;
    // Write your code here.
}
