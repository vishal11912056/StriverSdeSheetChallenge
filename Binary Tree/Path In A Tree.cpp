bool pathtonode(TreeNode<int>* A, int B,vector<int> &v)
 {
     if(A==NULL)
     {
         return false;
     }
     v.push_back(A->data);
     if(A->data==B)
     {
         return true;
     }
     if(pathtonode(A->left,B,v)||pathtonode(A->right,B,v))
     {
         return true;
     }
     v.pop_back();
     return false;
 }
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> v;
    pathtonode(root,x,v);
    return v;
}
