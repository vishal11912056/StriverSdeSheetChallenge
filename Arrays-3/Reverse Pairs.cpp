#include<bits/stdc++.h>
int merge(vector<int> &nums,int l,int mid,int h)
    {
        int cnt=0,j=mid+1;
        for(int i=l;i<=mid;i++)
        {
            while(j<=h && nums[i] > 2LL*nums[j])
            {
                j++;
            }
            cnt+= (j-(mid+1));
        }
        vector<int> tmp;
        int left=l,right=mid+1;
        while(left<=mid && right<=h)
        {
            if(nums[left]<=nums[right])
            {
                tmp.push_back(nums[left++]);
            }
            else
            {
                tmp.push_back(nums[right++]);
            }
        }
        while(left<=mid)
        {
            tmp.push_back(nums[left++]);
        }
        while(right<=h)
        {
            tmp.push_back(nums[right++]);
        }
        for(int i=l;i<=h;i++)
        {
            nums[i]=tmp[i-l];
        }
        return cnt;
        
    }
    int mergesort(vector<int> &nums,int l,int h)
    {
        if(l>=h)
        {
            return 0;
        }
        int mid= l+(h-l)/2;
        int pair=0;
        pair+=mergesort(nums,l,mid);
        pair+=mergesort(nums,mid+1,h);
        pair+=merge(nums,l,mid,h);
        return pair;
    }
int reversePairs(vector<int> &nums, int n)
{
	 return mergesort(nums,0,nums.size()-1);
	// Write your code here.	
}
