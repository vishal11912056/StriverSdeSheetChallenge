#include<bits/stdc++.h>
bool isCycle(int src,vector<int> &vis,vector<int> &dfs,vector<int> adj[])
{
    vis[src]=1;
    dfs[src]=1;
    for(auto it:adj[src])
    {
        if(!vis[it])
        {
            if(isCycle(it,vis,dfs,adj))
            {
                return true;
            }
            
        }
        else if(dfs[it])
        {
            return true;
        }
    }
    dfs[src]=0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
    vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
//     for(int i=0;i<edges.size();i++)
//     {
        
//     }
    vector<int> vis(n+1,0);
    vector<int> dfs(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(isCycle(i,vis,dfs,adj))
            {
                return 1;
            }
        }
    }
    return 0;
  // Write your code here.
}
