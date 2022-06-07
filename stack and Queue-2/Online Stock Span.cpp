#include<bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) 
{
    vector<int> ans;
   stack<int> s;

   for(int i=0; i<price.size(); i++) {

       while(!s.empty() && price[i] >= price[s.top()])

           s.pop();

       if(s.empty())

           ans.push_back(i+1);

       else

           ans.push_back(i - s.top());

       s.push(i);            

   }

   return ans;
    // Write your code here.
}
