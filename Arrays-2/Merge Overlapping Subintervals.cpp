#include<bits/stdc++.h>
vector<vector<int>> mergeIntervals(vector<vector<int>> &v)
{
	int j=0;
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            if(v[j][1]>=v[i][0])
            {
                v[j][1]=max(v[j][1],v[i][1]);
            }
            else
            {
                j++;
                v[j]=v[i];
            }
        }
        v.resize(j+1);
        return v;
}
