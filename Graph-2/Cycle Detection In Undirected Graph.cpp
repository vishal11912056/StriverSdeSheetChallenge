#include<bits/stdc++.h> 
bool isCycle(int src,vector<int> &vis,vector<int> prerequisites[])
    {
        queue<pair<int,int>> q;
        vis[src]=1;
        q.push({src,-1});
        while(!q.empty())
        {
            auto node =q.front().first;
            auto par= q.front().second;
            
            q.pop();
            
            for(auto it:prerequisites[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(par!=it)
                {
                    return true;
                }
            }
        }
        return false;
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
//        if(edges.size()<=1)
//         {
//             return "No";
//         }
        vector<int> adj[n+1];
       for(int i=0; i<edges.size(); i++)
       {
           
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
       }
       
//        for(int i=1;i<=n;i++)
//         {
//            sort(adj[i].begin(),adj[i].end());
//         }
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(isCycle(i,vis,adj))
                {
                    return "Yes";
                }
            }
        }
        return "No";
    // Write your code here.
}
