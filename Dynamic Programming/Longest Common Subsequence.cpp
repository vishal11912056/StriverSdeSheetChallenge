#include<bits/stdc++.h>
int lcs(string s1, string s2)
{
    int n=s1.size(),m=s2.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				curr[j] = 1 + prev[j-1]; 
			}
			else
			{
				curr[j] = 0 + max(prev[j],curr[j-1]);
			}
		}
		prev=curr;
	}
	return prev[m];
}
