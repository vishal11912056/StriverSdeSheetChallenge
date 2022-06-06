#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> res;
    priority_queue<int,vector<int>, greater<int>> minq;
    priority_queue<int,vector<int>> maxq;
    for(int i=0;i<n;i++)
    {
       if(i%2==0)
       {
           minq.push(arr[i]);
           maxq.push(minq.top());
           minq.pop();
           res.push_back(maxq.top());
       }
        else
        {
            maxq.push(arr[i]);
            minq.push(maxq.top());
            maxq.pop();
            res.push_back((minq.top()+maxq.top())/2);
        }
    }
	return res;
}
