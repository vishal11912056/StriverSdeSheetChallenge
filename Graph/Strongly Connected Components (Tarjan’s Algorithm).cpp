#include<bits/stdc++.h>
void toposort(int i,stack<int> &st,vector<int> &vis,vector<int> adj[])
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            toposort(it,st,vis,adj);
        }
    }
    st.push(i);
}
void scc(int i,vector<int> &vis,vector<int> adj[],vector<int> &v)
{
    vis[i]=1;
    v.push_back(i);
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            scc(it,vis,adj,v);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            toposort(i,st,vis,adj);
        }
    }
    vector<int> trans[n];
    
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            trans[it].push_back(i);
        }
    }
    vector<vector<int>> v1;
    while(!st.empty())
    {
        auto i=st.top();
        st.pop();
        if(!vis[i])
        { 
            vector<int> v;
            scc(i,vis,trans,v);
            v1.push_back(v);
        }
    }
    return v1;
    // Write your code here.
}
