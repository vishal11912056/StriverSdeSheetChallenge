#include<bits/stdc++.h> 
bool bipartite(int i,vector<int> &vis,vector<int> graph[])
    {
       if(vis[i]==-1)
       {
        
          vis[i]=1;
       }
         for(auto it:graph[i])
         {
             if(vis[it]==-1)
             {
                 vis[it]= 1-vis[i];
                 if(!bipartite(it,vis,graph))
                 {
                     return false;
                 }
             }
             else if(vis[it]==vis[i])
             {
                 return false;
             }
         }
            return true;
        
    }
  bool bipartite_bfs(int i,vector<int> &vis,vector<int> graph[])
    {
        queue<int> q;
        vis[i]=1;
        q.push(i);
        while(!q.empty())
        {
            auto src=q.front();
            q.pop();
            for(auto it:graph[src])
            {
                if(vis[it]==-1)
                {
                    vis[it]=1-vis[src];
                    q.push(it);
                }
                else if(vis[it]==vis[src])
                {
                    return false;
                }
            }
        }
        return true;
    }
bool isGraphBirpatite(vector<vector<int>> &edges) 
{
     int n=edges.size();
     vector<int> adj[n];
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<n; j++)
           {
               if(edges[i][j]==1)
               {
                  adj[i].push_back(j);
                  adj[j].push_back(i);
               }
           }
       }
   
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                // vis[i]=1;
                if(!bipartite_bfs(i,vis,adj))
                {
                    return false;
                }
            }
        }
        return true;
	// Write your code here.
}
