#include<bits/stdc++.h>
long f(int idx,int value,int *arr,vector<vector<long>> &dp)
{
    if(idx==0)
    {
        return (value%arr[0]==0);
    }
    if(dp[idx][value]!=-1)
    {
        return dp[idx][value];
    }
    long untake = f(idx-1,value,arr,dp);
    long take=0;
    if(value>=arr[idx])
    {
        take= f(idx,value-arr[idx],arr,dp);
    }
    return dp[idx][value]=(untake+take);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
    //Write your code here
}
