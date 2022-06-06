#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<pair<int,int>> adj[vertices];
    for(int i=0;i<vec.size();i++)
    {
        
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
       
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    vector<int> dist(vertices,INT_MAX);
  queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//     queue<pair<int,int>> q;
    q.push({0,source});
    dist[source]=0;
    while(!q.empty())
    {
        int prevdist= q.top().first;
        int prev= q.top().second;
        q.pop();
        for(auto it:adj[prev])
        {
            int next=it.first;
           int nextdist=it.second;
            if(dist[next]>(prevdist+nextdist))
            {
                dist[next]=prevdist+nextdist;
                q.push({dist[next],next});
            }
        }
    }
    return dist;
    // Write your code here.
}
