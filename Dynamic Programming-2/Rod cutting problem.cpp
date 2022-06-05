int f(int idx,int tar,vector<int> &price, vector<vector<int>> &dp)
{
    if(idx==0)
    {
        return tar*price[0];
    }
    if(dp[idx][tar]!=-1)
    {
        return dp[idx][tar];
    }
    int untake = 0 + f(idx-1,tar,price,dp);
    int take = INT_MIN;
    if(idx+1 <= tar)
    {
        take= price[idx] + f(idx,tar-(idx+1),price,dp);
    }
    return dp[idx][tar]=max(untake,take);
}
int cutRod(vector<int> &price, int n)
{
//     vector<vector<int>> dp(n,vector<int>(n+1,0));
//     return f(n-1,n,price,dp);
    vector<int> dp(n+1,0);
    for(int i=0;i<=n;i++)
    {
        dp[i]= i*price[0];
    }
    for(int idx=1;idx<n;idx++)
    {
        for(int tar=0;tar<=n;tar++)
        {
             int untake = 0 + dp[tar];
            int take = INT_MIN;
            if(idx+1 <= tar)
            {
                take= price[idx] + dp[tar-(idx+1)];
            }
             dp[tar]=max(untake,take);
        }
    }
    return dp[n];
	// Write your code here.
}
