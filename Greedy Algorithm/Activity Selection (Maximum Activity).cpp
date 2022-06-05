#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) 
{
	int n=start.size();
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		v.push_back({finish[i],start[i]});
	}
	sort(v.begin(),v.end());
	int fin=v[0].first;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(v[i].second>=fin)
		{
			cnt++;
			fin=v[i].first;
		}
	}
	return cnt;
    // Write your code here.
}
