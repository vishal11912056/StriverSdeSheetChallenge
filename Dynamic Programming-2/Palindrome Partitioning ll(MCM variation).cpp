#include<bits/stdc++.h>
bool isPalindrome(int i,int j,string str)
{
	while(i<j)
	{
		if(str[i]!=str[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int palindromePartitioning(string str) 
{
	int n=str.length();
	vector<int> dp(n+1,0);
	for(int i=n-1;i>=0;i--)
	{
		int mini=1e9;
		for(int idx=i;idx<n;idx++)
		{
			if(isPalindrome(i,idx,str))
			{
				int cost = 1 + dp[idx+1];
				mini = min(mini,cost);
			}
		}
		 dp[i]=mini;
	}
    return dp[0]-1;
}
