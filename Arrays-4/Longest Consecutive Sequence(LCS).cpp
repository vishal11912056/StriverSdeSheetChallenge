#include<bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) 
{
	unordered_set<int> s;
        int cnt=0,curr,ans=0;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++ )
        {
            if(!s.count(nums[i]-1))
            {
                cnt=1,curr=nums[i];
                while(s.count(curr+1))
                {
                    cnt++;
                    curr++;
                }
                ans=max(ans,cnt);
            }
           
        }
        return ans;
        
}
