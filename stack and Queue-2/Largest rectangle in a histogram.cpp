#include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights) 
 {
      int ans=0;
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[i]<=heights[st.top()]))
            {
                int hgt= heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width=i;
                }
                else
                {
                    width= (i-st.top()-1);
                }
                ans = max(ans,hgt*width);
            }
            st.push(i);
        }
        return ans;   
   // Write your code here.
 }
