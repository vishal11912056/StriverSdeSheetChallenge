#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
     unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        sort(res.begin(),res.end());
        return res;
}