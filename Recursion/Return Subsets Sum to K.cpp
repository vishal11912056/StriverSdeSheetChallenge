#include<bits/stdc++.h>
void solve(int idx,int n,int k, vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans)
{
	if(k==0)
	{
		ans.push_back(ds);
	}
	if(idx>=n)
	{
		return;
	}
	 for(int i=idx;i<n;i++){
		ds.push_back(arr[i]);
		solve(i+1,n,k-arr[i],arr,ds,ans);
		ds.pop_back();
	 } 
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
	vector<vector<int>> ans;
	vector<int> ds;

	solve(0,n,k,arr,ds,ans);
	return ans;
    // Write your code here.
}

