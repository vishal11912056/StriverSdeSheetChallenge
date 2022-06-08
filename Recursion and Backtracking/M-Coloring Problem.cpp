bool isSafe(int node,int col,int n,int color[],vector<vector<int>> &graph)
{
    for(int i=0;i<n;i++)
    {
        if(i!=node &&  graph[node][i]==1 && color[i]==col)
        {
            return false;
        }
        
    }
    return true;
}
bool solve(int node,int m,int n,int color[],vector<vector<int>> &graph)
{
    if (node==n)
    {
        return true;
    }
    
    for(int i=1;i<=m;i++)
    {
        if(isSafe(node,i,n,color,graph))
        {
            color[node]=i;
            if(solve(node+1,m,n,color,graph))
            {
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &graph, int m) 
{
    int V=graph.size();
    int color[V]={0};
    if(solve(0,m,V,color,graph)) return "YES";
    return "NO";
    // Write your code here
}
