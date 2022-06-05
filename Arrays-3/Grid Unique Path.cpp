int uniquePaths(int m, int n) 
{
//      vector<long long int> dp(n,0);
//         for(int i=0;i<m;i++)
//         {
//             vector<long long int> tmp(n,0);
//             for(int j=0;j<n;j++)
//             {
                
//                 if(i==0 && j==0)
//                 {
//                     tmp[j]=1;
//                 }
//                 else
//                 {
//                    long long int up=0,left=0;
//                     if(i>0)
//                     {
//                         up = dp[j]%1000000007;
//                     }
//                     if(j>0)
//                     {
//                         left = tmp[j-1]%1000000007;
//                     }
//                      tmp[j]=(up+left)%1000000007;
//                 }
               
//             }
//             dp=tmp;
//         }
//         return dp[n-1]%1000000007;
    
    int N= (m+n-2);
    int r = m-1;
    int res=1;
    for(int i=1;i<=r;i++)
    {
        res = res* (N-r+i)/i;
    }
    return res;
	// Write your code here.
}
