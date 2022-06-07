#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> res;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        // int index[k] = {0};
        
            
        for(int i=0; i<k; i++){
            pq.push({arr[i][0], {i,0}});
        }
        
        while(!pq.empty()){
            int val = pq.top().first;
            int arr_num = pq.top().second.first;
            int arr_idx = pq.top().second.second;
            arr_idx++;
            res.push_back(val);
             pq.pop();
            if(arr_idx < arr[arr_num].size()){
                pq.push({arr[arr_num][arr_idx], {arr_num,arr_idx}});
            }
        }
        
        return res;
    }
