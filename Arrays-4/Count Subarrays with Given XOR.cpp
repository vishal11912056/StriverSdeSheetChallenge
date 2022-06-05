#include<bits/stdc++.h>
int subarraysXor(vector<int> &arr, int k)
{
	unordered_map<int,int> mp;
	int xr=0,cnt=0;
	for(int x:arr)
	{
		xr^=x;
		if(xr==k)
		{
			cnt++;
		}
		if(mp.find(xr^k)!=mp.end())
		{
			cnt+=mp[xr^k];
		}
		mp[xr]+=1;
	}
	return cnt;
    //    Write your code here.
}
