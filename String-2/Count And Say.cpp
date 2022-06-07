string writeAsYouSpeak(int n) 
{
	        if(n==1) return "1";
        if(n==2) return "11";
        int c=1;
        string s="11";
        for(int i=3;i<=n;i++)
        {
            string t="";
            s+='$';
            for(int j=1;j<s.length();j++)
            {
                if(s[j-1]!=s[j])
                {
                    t+= to_string(c);
                    t+=s[j-1];
                    c=1;
                }
                else
                {
                    c++;
                }
            }
            s=t;
        }
        return s;
}
