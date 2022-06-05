#include<bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &nums, int target)
{
	vector<vector<int>> vv;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
				int count =m[target-nums[i]];
				while(count)
				{
					vv.push_back({min(nums[i],target-nums[i]),max(nums[i],target-nums[i])});
					count--;
				}
                 
            }
            m[nums[i]]++;
        }
	    sort(vv.begin(),vv.end());
        return vv;
}
