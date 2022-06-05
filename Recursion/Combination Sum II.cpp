#include<bits/stdc++.h>
void solve(int idx,int tar,vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans)
{
	if(tar==0)
	{
		ans.push_back(ds);
	}
	for(int i=idx;i<arr.size();i++)
	{
		if(i>idx && arr[i]==arr[i-1])
		{
			continue;
		}
		if(arr[i]>tar)
		{
			break;
		}
		ds.push_back(arr[i]);
		solve(i+1,tar-arr[i],arr,ds,ans);
		ds.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	   sort(arr.begin(),arr.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,target,arr,ds,ans);
        
        return ans;
	// Write your code here.
}
