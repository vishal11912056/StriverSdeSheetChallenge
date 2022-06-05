#include<bits/stdc++.h>
static bool cmp(pair<int, int> a,pair<int, int> b)
{
	double v1= (double)a.second/(double)a.first;
	double v2= (double)b.second/(double)b.first;
						
	return(v1>v2);					
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
	
	sort(items.begin(),items.end(),cmp);
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<(double)items[i].second<<"----"<<(double)items[i].first<<endl;
// 	}
	double ans=0;
	for(int i=0;i<n;i++)
	{
		if(w>=items[i].first)
		{
			ans+=items[i].second;
// 			cout<<"answer--"<<ans<<endl;
			w-=items[i].first;
// 			cout<<"weight--"<<w<<endl;
			continue;
		}
		double x = (double)items[i].second/(double)items[i].first;
		ans+= x*w;
		w=0;
// 		cout<<"answer--"<<ans<<endl;
		break;
	}
	return ans;
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
}
