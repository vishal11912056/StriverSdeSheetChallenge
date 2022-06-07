#include<bits/stdc++.h>
int findKthSmallest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        while(k!=1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>> pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        while(k!=1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    int x=findKthSmallest(arr,k);
    int y= findKthLargest(arr,k);
    return {x,y};
}
