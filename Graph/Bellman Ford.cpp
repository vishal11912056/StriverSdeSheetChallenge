#include<bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
//     vector<pair<int,int>> adj[n+1];
//     for(int i=0;i<edges.size();i++)
//     {
        
//         adj[edges[i][0]].push_back({edges[i][1],vec[i][2]});
       
//         adj[edges[i][1]].push_back({edges[i][0],vec[i][2]});
//     }
    vector<int> dist(n+1,1000000000);
        dist[src]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int u= edges[j][0];
                int v= edges[j][1];
                int w= edges[j][2];
                if(dist[u]!=1000000000 && dist[v]>(dist[u] + w))
                {
                
                   dist[v]=dist[u] + w;
                }

  
            }
        }
        return dist[dest];
    // Write your code here.
}
