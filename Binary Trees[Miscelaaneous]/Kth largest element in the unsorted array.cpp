#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int K)
{
     priority_queue<int,vector<int>> pq;
        for(auto it:arr)
        {
            pq.push(it);
        }
        while(K!=1)
        {
            pq.pop();
            K--;
        }
        return pq.top();
	// Write your code here.
}
