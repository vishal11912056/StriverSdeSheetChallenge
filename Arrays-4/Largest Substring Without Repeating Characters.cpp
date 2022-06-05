#include<bits/stdc++.h>
int uniqueSubstrings(string s)
{
	vector<int> mp(256,-1);
	int r=0,l=0,n=s.length(),ans=0;
	while(r<n)
	{
		if(mp[s[r]]!=-1)
		{
			l= max(mp[s[r]]+1,l);
		}
		mp[s[r]]=r;
		ans= max(ans,(r-l+1));
		r++;
	}
	return ans;
    //Write your code here
}
