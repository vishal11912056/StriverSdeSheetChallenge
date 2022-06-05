#include<bits/stdc++.h>
int f(int idx,int prev,int arr[],int n,vector<vector<int>> &dp)
{
	if(idx==n)
	{
		return 0;
	}
	if(dp[idx][prev+1]!=-1)
	{
		return dp[idx][prev+1];
	}
	int untake = 0 + f(idx+1,prev,arr,n,dp);
	int take = 0;
	if(prev==-1 || arr[idx]>arr[prev])
	{
		take = 1 + f(idx+1,idx,arr,n,dp);
	}
	return dp[idx][prev+1]= max(take,untake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//     return f(0,-1,arr,n,dp);
	for(int idx=n-1;idx>=0;idx--)
	{
		for(int prev=idx-1;prev>=-1;prev--)
		{
			int untake = 0 + dp[idx+1][prev+1];
			int take = 0;
			if(prev==-1 || arr[idx]>arr[prev])
			{
				take = 1 + dp[idx+1][idx+1];
			}
			dp[idx][prev+1] = max(take,untake);	
		}
	}
	return dp[0][-1+1];
}
