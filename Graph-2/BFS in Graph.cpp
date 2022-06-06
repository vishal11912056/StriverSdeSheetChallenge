#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];
    for(int i=0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    for(int i=0;i<vertex;i++)
    {
       sort(adj[i].begin(),adj[i].end());
    }
    vector<int> bfs;
     vector<int> vis(vertex,0);
       for(int i=0;i<vertex;i++)
       {
           if(vis[i]==0)
           {
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                    int x=q.front();
                    q.pop();
                    bfs.push_back(x);
                    for(auto it:adj[x])
                    {
                        if(vis[it]==0)
                        {
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
           }
       }
        return bfs;
    // Write your code here
}
