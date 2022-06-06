#include<bits/stdc++.h>
class unionFind{
  
    vector<int> parent,rank;
    public:
    unionFind(int size)
    {
        parent.resize(size);
        rank.resize(size);
        for(int i=0;i<size;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return find(parent[x]);
    }
    void Union(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }else if(rank[x]>rank[y])
        {
            parent[y]=x;
        }else 
        {
            parent[x]=y;
            rank[y]++;
        }
    }
};
bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) 
{
    sort(graph.begin(),graph.end(),cmp);
    unionFind uf(n+1);
    int ans=0;
    for(auto it:graph)
    {
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        int par_x=uf.find(u);
        int par_y=uf.find(v);
        if(par_x!=par_y)
        {
            ans+=wt;
            uf.Union(u,v);
        }
    }
    return ans;
	// Write your code here.
}
