 bool rabincarp(string txt,string pattrn)
    {
        int d=31;
        int q=101;
        int m=pattrn.length();
        int n= txt.length();
        int p=0;
        int t=0;
        int h=1;
        for(int i=0;i<m-1;i++)
        {
            h= (h*d)%q;
        }
        for(int i=0;i<m;i++)
        {
            p= (p*d + pattrn[i])%q;
            t= (t*d + txt[i])%q;
        }
        for(int i=0;i<=(n-m);i++)
        {
            
            if(p==t)
            {
               int j=0;
                for(;j<m;j++)
                {
                    if(txt[i+j]!=pattrn[j])
                    {
                        break;
                    }
                }
                if(j==m)
                {
                    return true;
                }
                
            }
            if(i< n-m)
            {
                t = (d*(t - txt[i]*h)%q+ txt[i+m])%q;
                
                if(t<0)
                {
                    t=t+q;
                }
            }
            
        }
        return false;
        
    }
    bool findPattern(string needle, string haystack) 
    {
        
        int n= haystack.length();
        int m= needle.length();
        if(m==0)
        {
            return true;
        }
        if(m>n)
        {
            return false;
        }
        return rabincarp(haystack,needle);
        // return -1;
        
    }

