#include<bits/stdc++.h>
bool isPalindrom(int srt,int lst,string s)
{
        while(srt<=lst)
        {
            if(s[srt++]!=s[lst--])
            {
                return false;
            }
        }
        return true;
}
    void solve(int idx,string s,vector<string> &ds,vector<vector<string>> &ans)
    {
        if(idx==s.length())
        {
            ans.push_back(ds);
            return ;
        }
        
        for(int i=idx;i<s.length();i++)
        {
            if(isPalindrom(idx,i,s))
            {
                ds.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }

vector<vector<string>> partition(string &s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s,ds,ans);
        return ans;
    }
