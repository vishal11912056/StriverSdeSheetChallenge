#include<bits/stdc++.h>
bool static comparator(pair<int,pair<int,int>> m1, pair<int,pair<int,int>> m2) {
         if (m1.first < m2.first) return true;
         else if (m1.first > m2.first) return false;
         else if (m1.second.second < m2.second.second) return true;
         return false;
      }
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) 
{
	int n=start.size();
// 	int cnt=1;
	vector<int> v;
        vector<pair<int,pair<int,int>>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({end[i],{start[i],i+1}});
        }
        sort(vp.begin(),vp.end(),comparator);
	v.push_back(vp[0].second.second);
        int tmp=vp[0].first;
        for(int i=1;i<n;i++)
        {
            if(vp[i].second.first>tmp)
            {
                v.push_back(vp[i].second.second);
                tmp=vp[i].first;
            }
        }
        return v;
    // Write your code here.
}
