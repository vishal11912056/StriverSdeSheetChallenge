#include<bits/stdc++.h>
class Kthlargest {
public:
    int kth;
    priority_queue<int,vector<int>,greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) 
    {
        kth=k;
        for(auto num: arr)
        {
            pq.push(num);
        }
        while(k<pq.size())
        {
            pq.pop();
        }
       // Write your code here.
    }

    void add(int num) 
    {
        pq.push(num);
        if(pq.size()>kth)
        {
            pq.pop();
        }
        
        // Write your code here.
    }

    int getKthLargest() 
    {
        return pq.top();
       // Write your code here.
    }

};
