#include<bits/stdc++.h>
int fun(int e,int f,vector<vector<int>> &dp)
    {
        
        if(f==1 || f==0)
        {
            return f;
        }
        if(e==1)
        {
            return f;
        }
        if(dp[e][f]!=-1)
        {
            return dp[e][f];
        }
        int ans=1000000,l=1,h=f,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=fun(e-1,mid-1,dp);   //egg broken check for down floors of mid
            int right=fun(e,f-mid,dp) ;   // not broken check for up floors of mid
            temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
       return dp[e][f]=ans;
    }
int cutLogs(int n, int k)
{
//     k---->floor  && n--->>eggs
   vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return fun(n,k,dp);
}
