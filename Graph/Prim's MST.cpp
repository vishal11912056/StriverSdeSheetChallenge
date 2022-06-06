#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n];
   for (int i = 0; i < m; i++)
	{
		adj[g[i].first.first-1].push_back(make_pair(g[i].first.second-1, g[i].second));
		adj[g[i].first.second-1].push_back(make_pair(g[i].first.first-1, g[i].second));
	}
     int V=n;
     vector<int> key(V,INT_MAX),parent(V,-1);
        vector<bool> mst_set(V,false);
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        key[0]=0;
         mst_set[0]=true;
        
        pq.push({0,0});
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            
            mst_set[u]=true;
            for(auto it:adj[u])
            {
                int v=it.first;
                int weight=it.second;
                
                if(mst_set[v]==false && weight<key[v])
                {
                    key[v]=weight;
                     parent[v]=u;
                    pq.push({key[v],v});
                }
            }
        }
    vector<pair<pair<int, int>, int>> v;
   for (int i = 1; i < n; i++)
	{
		v.push_back({{min(parent[i]+1, i+1),max(parent[i]+1, i+1)}, key[i]});
	}

    return v;
    // Write your code here.
}
