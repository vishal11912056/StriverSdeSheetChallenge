/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* bstform(int srt,int end,vector<int> &arr)
{
    if(srt>end)
    {
        return NULL;
    }
    int mid = (srt+end)>>1;
    TreeNode<int>* root= new TreeNode<int>(arr[mid]);
    root->left = bstform(srt,mid-1,arr);
    root->right = bstform(mid+1,end,arr);
    
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return bstform(0,n-1,arr);
    // Write your code here.
}
