#include<bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > A) 
{
	int n=A.size();
	int res=0,sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0)
            {
                res= max(res,i+1);
            }
            else
            {
                if(m.find(sum)!=m.end())
                {
                    res=max(res,i-m[sum]);
                }
                else
                {
                    m[sum]=i;
                }
            }
        }
        return res;
  // Write your code here

}
