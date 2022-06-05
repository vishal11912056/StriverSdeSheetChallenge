#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
     int n = v.size(); 
		    vector<vector<int>> ans; 
		    for(int num = 0; num < (1 << n); num++) {
		        vector<int> sub; 
		        for(int i = 0;i<n;i++) {
		            if(num & (1<<i)) {
		                sub.push_back(v[i]);
		            }
		        }
		        if(sub.size() > 0)
		            ans.push_back(sub);
		    }
		    sort(ans.begin(), ans.end()); 
		    return ans; 
    //Write your code here
}
