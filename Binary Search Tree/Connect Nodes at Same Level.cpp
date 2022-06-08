#include<bits/stdc++.h> 
void connectNodes(BinaryTreeNode< int > *root) {
        queue<BinaryTreeNode< int > *> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                BinaryTreeNode< int > *  cur=q.front();
                q.pop();
                if(i!=size-1){
                    cur->next=q.front();
                }
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
}
