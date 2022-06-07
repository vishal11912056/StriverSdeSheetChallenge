string reverseString(string s)
{
    string str="";
        if(s.length()==1)
        {
            return s;
        }
       for(int i=s.length()-1;i>=0;i--)
       {
           if(s[i]==' ')
           {
               continue;
           }
           int j=i;
           while(j>=0 && s[j]!=' ')
           {
               j--;
           }
           str+= s.substr(j+1,i-j);
           str+=' ';
           i=j;
       }
        return str;
}
