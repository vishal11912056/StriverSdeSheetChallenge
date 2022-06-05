bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    
//         vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
    vector<bool> dp(k+1,false),tmp(k+1,false);
//         for(int i=0;i<n;i++)
//         {
//             dp[i][0]=true;
            
//         }
//         dp[0][arr[0]]=true;
    dp[0]=true,dp[arr[0]]=true;
    tmp[0]=true;
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=k;tar++)
            {
                bool untake= dp[tar];
                bool take= false;
                if(tar>=arr[i])  take=dp[tar-arr[i]];
                
                tmp[tar]=(untake||take);
            }
            dp=tmp;
        }
        return dp[k];
    // Write your code here.
}
