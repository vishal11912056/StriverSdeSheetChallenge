#include<bits/stdc++.h>
int romanToInt(string s) 
{
     unordered_map<char, int> rm;
        rm['I'] = 1;
        rm['V'] = 5;
        rm['X'] = 10;
        rm['L'] = 50;
        rm['C'] = 100;
        rm['D'] = 500;
        rm['M'] = 1000;
        int ans = 0;
        int n = s.length();
        int i=0;
        while(i<n)
        {
            if(s.substr(i,2)=="CM" || s.substr(i,2)=="CD" || s.substr(i,2)=="XC" || s.substr(i,2)=="XL" || s.substr(i,2)=="IX" || s.substr(i,2)=="IV")
            {
                ans+= rm[s[i+1]]-rm[s[i]];
                i+=2;
            }
            else
            {
                ans+=rm[s[i]];
                i++;
            }
        }
        return ans;
    // Write your code here
}
