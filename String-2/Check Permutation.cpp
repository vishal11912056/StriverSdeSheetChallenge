bool areAnagram(string &s, string &t)
{
     if(s.length()!=t.length())
        {
            return false;
        }
        int x[26]={0};
        for(int i=0;i<s.length();i++)
        {
            x[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            if(x[t[i]-'a']==0)
            {
                return false;
            }
            else
            {
                x[t[i]-'a']--;
            }
        }
        return true;
    // Write your code here.
}
