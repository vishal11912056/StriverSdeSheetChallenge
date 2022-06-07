#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
//        vector<int> v;
//         if(root==NULL)
//         {
//             return v;
//         }
//         int hd=0;
//         multimap<int,int> m;
//         queue<pair<TreeNode<int>*,int>> q;
//         q.push(make_pair(root,hd));
//         while(!q.empty())
//         {
//             auto curr=q.front();
//             q.pop();
//             TreeNode<int>* tmp=curr.first;
//              hd=curr.second;
//             m.insert({hd,tmp->data});
//             if(tmp->left)
//             {
//                 q.push(make_pair(tmp->left,hd-1));
//             }
//             if(tmp->right)
//             {
//                 q.push(make_pair(tmp->right,hd+1));
//             }
            
//         }
//         for(auto it=m.begin();it!=m.end();++it)
//         {
//             v.push_back(it->second);
//         }
//         return v;
         vector<int> result;

    // Base case
    if (root == NULL)
    {
        return result;
    }

    // Create a map and store vertical order in map.
    map<int, vector<int>> store;

    // Initial horizontal distance.
    int hd = 0;

    // Every pair of queue contains node and horizontal distance with respect to the root node.
    queue<pair<TreeNode<int> *, int>> level;

    level.push(make_pair(root, hd));

    while (level.empty() == false)
    {
        // Pop element from the queue.
        pair<TreeNode<int> *, int> temp = level.front();
        level.pop();

        hd = temp.second;

        TreeNode<int> *node = temp.first;

        // Insert the value of current node in the vector of map.
        store[hd].push_back(node->data);

        // For the left subtree, we pass the HD as the Horizontal distance of root minus 1.
        if (node->left != NULL)
        {
            level.push(make_pair(node->left, hd - 1));
        }

        // For the right subtree, we pass the HD as Horizontal Distance of root plus 1.
        if (node->right != NULL)
        {
            level.push(make_pair(node->right, hd + 1));
        }
    }

    // Traverse the map and store node values at every horizontal distance (hd).
    map<int, vector<int>>::iterator it;

    for (it = store.begin(); it != store.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
        {
            result.push_back(it->second[i]);
        }
    }

    // Return the vertical order traversal of the given binary tree.
    return result;
    
    //    Write your code here.
}
