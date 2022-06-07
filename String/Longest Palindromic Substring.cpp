#include<bits/stdc++.h>
void computemax(int i,int j,int &maxi,int &maxlen)
    {
        int len=j-i+1;
        if(len>maxlen)
        {
            maxi=i;
            maxlen=len;
        }
    }
    string longestPalinSubstring(string s) 
    {
        int n= s.size();
        if(n==1)
        {
            return s;
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxi=0,maxlen=1;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(i==j)
                {
                     dp[i][j]=1;
                }
                else if(j-i==1)
                {
                    if(s[j]==s[i])
                    {
                        dp[i][j]=1;
                        computemax(i,j,maxi,maxlen);
                    }
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        computemax(i,j,maxi,maxlen);
                    }
                }
                    
            }
        }
        
        return s.substr(maxi,maxlen);
        
    }
