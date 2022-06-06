#include<bits/stdc++.h>
void topo(int src,stack<int> &st,vector<int> &vis,vector<int> adj[])
{
    vis[src]=1;
    for(auto it:adj[src])
    {
        if(!vis[it])
        {
            topo(it,st,vis,adj);
        }
    }
    st.push(src);
//     return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
{
    vector<int> adj[v];
    vector<int> ans;

    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
//     for(int i=0;i<v;i++)
//     {
//         sort(adj[i].begin(),adj[i].end());
//     }
    vector<int > vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            topo(i,st,vis,adj);
        }
    }
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    // Write your code here
}
