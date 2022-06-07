#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &nums2, int n) {
 
     vector<int> res(nums2.size());
//         unordered_map<int,int> res(nums2.size());
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                res[i]=-1;
            }
            else
            {
                res[i]=st.top();
            }
            st.push(nums2[i]);
        }
        
        return res;// Write your code here

}
