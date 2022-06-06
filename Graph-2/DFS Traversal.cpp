void Dfs(int src,vector<int> &vis,vector<vector<int>> &graph,vector<int> &v1)
{
    v1.push_back(src);
    vis[src]=1;
    for(auto it:graph[src])
    {
        if(!vis[it])
        {
            Dfs(it,vis,graph,v1);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &graph)
{
     vector<vector<int>> v;
     vector<int> vis(V,0);
     for(int i=0;i<V;i++)
     {
         if(vis[i]==0)
         {
             vector<int> v1;
             Dfs(i,vis,graph,v1);
                 v.push_back(v1);
         }
     }
    return v;
    
    
}
