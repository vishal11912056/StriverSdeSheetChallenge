#include<bits/stdc++.h>
void isIsland(int i,int j,int n,int m,int** grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
        {
            return;
        }
//         vis[i][j]=true;
        
        if(grid[i][j]==1)
        {
             grid[i][j]=0;
             isIsland(i+1,j,n,m,grid);
             isIsland(i-1,j,n,m,grid);
             isIsland(i,j+1,n,m,grid);
             isIsland(i,j-1,n,m,grid);
             isIsland(i+1,j+1,n,m,grid);
             isIsland(i-1,j-1,n,m,grid);
             isIsland(i+1,j-1,n,m,grid);
             isIsland(i-1,j+1,n,m,grid);
        }
    }
int getTotalIslands(int** arr, int n, int m)
{
//      int n=arr.size();
//         int m=arr[0].size();
        
//         vector<vector<bool>> vis(n,vector<bool> (m,false));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1 )
                {
                    cnt++;
                    isIsland(i,j,n,m,arr);
                    
                }
            }
        }
        return cnt;
        
   // Write your code here.
}
