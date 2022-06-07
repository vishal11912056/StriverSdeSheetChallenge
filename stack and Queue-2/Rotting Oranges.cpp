#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
//      int n = grid.size();
//         int m = grid[0].size();
        int r[]= {0,0,1,-1};
        int c[]= {1,-1,0,0};
        int timer=-1;
        bool flg=false;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                }
                else if(grid[i][j]==1)
                {
                    flg=true;
                }
            }
            
        }
        if(!flg)
        {
            return 0;
        }
        while(!q.empty())
        {
            int sz= q.size();
            for(int i=0;i<sz;i++)
            {
                auto it =q.front();
                q.pop();
                int sr = it.first;
                int sc = it.second;
                for(int j=0;j<4;j++)
                {
                    int x = sr + r[j];
                    int y= sc+ c[j];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                    {
                        grid[x][y]=0;
                        q.push({x,y});
                        
                    }
                }
            }
            timer++;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return timer;
        
}
