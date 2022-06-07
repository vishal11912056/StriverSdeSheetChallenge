int minlenstr(vector<string>& strs)
    {
        int minlen=strs[0].length();
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].length()<minlen)
            {
                minlen=strs[i].length();
            }
        }
        return minlen;
    }
string longestCommonPrefix(vector<string> &strs, int n)
{
//     int n=strs.size();
        string pre="";
         if(strs.size() == 1)    return strs[0];
        
        int m= minlenstr(strs);
   
        for(int i=0;i<m;i++)
        {
            char c=strs[0][i];
            for(int j=1;j<n;j++)
            {
                if( strs[j][i]!=c)
                {
                    return pre;
                }
            }
            pre+=c;
        }
        return pre;
}


